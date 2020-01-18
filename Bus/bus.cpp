//
// Created by Peter Gyarmati on 2020. 01. 18..
//

#include "bus.h"

Bus::Bus(const string& line_number, const vector<Station>& stations, int price_per_station) {
    if (line_number.empty()) throw runtime_error("line_number empty!");
    if (stations.empty()) throw runtime_error("stations empty!");
    if (!(0 < price_per_station && price_per_station <= 20)) throw runtime_error("!(0 < price_per_station && price_per_station <= 20)");
    this->line_number = line_number;
    this->stations = stations;
    this->price_per_station = price_per_station;
}

bool Bus::stops_at(Station station) const {
    return contains_element(stations, station);
}

int Bus::cost(Station from, Station to) const {
    bool stations_not_visited = !contains_element(stations, from) || !contains_element(stations, to);
    if (stations_not_visited) return 0;
    size_t from_index = first_index_of_element(stations, from);
    for (size_t i = from_index + 1; i < stations.size(); i++)
        if (stations[i] == to) return (int)(i - from_index) * price_per_station;

    return 0;
}

string Bus::to_string() const {
    string str = "[" + line_number + " " + std::to_string(price_per_station) + " cent/station {";
    for (size_t i = 0; i < stations.size(); i++)
        str += (station_names.at(static_cast<size_t >(stations[i])) +
                (i == stations.size() - 1 ? "" : ", "));

    return str += "}]";
}

const vector<Station>& Bus::get_stations() const {
    return stations;
}


ostream& operator<<(ostream& out, const Bus& rop) {
    return out << rop.to_string();
}