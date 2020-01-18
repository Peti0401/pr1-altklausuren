//
// Created by Peter Gyarmati on 2020. 01. 18..
//

#include "fleet.h"

Fleet::Fleet(const string& owner, const vector<Bus>& buses) : buses{buses}{
     if (owner.empty()) throw runtime_error("owner empty!");
     this->owner = owner;
}

void Fleet::add_line(const Bus& bus) {
    buses.push_back(bus);
}

vector<Bus> Fleet::stops_at(Station station) const {
    vector<Bus> result;
    for (const auto& bus : buses) if (bus.stops_at(station)) result.push_back(bus);
    return result;
}

string Fleet::to_string() const {
    string str = "[" + owner + " {";
    for (size_t i = 0; i < buses.size(); i++)
        str += (buses[i].to_string() +
                (i == buses.size() - 1 ? "" : ", "));
    return str += ("}]");
}

vector<Bus> Fleet::has_loop() const {
    vector<Bus> result;
    for (const auto& bus : buses) if (has_duplicate(bus.get_stations())) result.push_back(bus);
    return result;
}

vector<Bus> Fleet::cheapest_connection(Station from, Station to) const {
    vector<Bus> result;
    int min_cost = -1;
    // finding minimum cost
    for (const auto& bus : buses) {
        int cur_cost = bus.cost(from, to); // saving to variable so that bus.cost(from, to) is called only once per loop
        if (cur_cost == 0) continue; // skipping costs of 0 which mean no connection between the specified endpoints
        if (min_cost == -1) { // setting min_cost for the first time
            min_cost = cur_cost;
            continue;
        }
        if (cur_cost < min_cost) min_cost = cur_cost; // setting min_cost after comparison
    }
    // adding all buses to the result which have minimum cost between the specified endpoints
    for (const auto& bus : buses) if (bus.cost(from, to) == min_cost) result.push_back(bus);
    return result;
}

ostream& operator<<(ostream& out, const Fleet& rop) {
    return out << rop.to_string();
}
