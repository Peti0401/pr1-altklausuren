//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "fleet.h"

Fleet::Fleet(const string& name, const Faction& faction, const vector<Spaceship>& ships)
: faction{faction}, ships{ships}
{
    if (name.empty()) throw runtime_error("Fleet name cannot be empty!");
    if (!Spaceship::same_faction(ships, faction)) throw runtime_error("Ships must be in the same faction!");
    this->name = name;
}

bool Fleet::add(const vector<Spaceship>& ships) {
    if (ships.empty()) throw runtime_error("List of ships to add cannot be empty!");
    if (!Spaceship::same_faction(ships, faction)) return false;

    for (const auto& ship : ships) this->ships.insert(this->ships.begin(), ship);
    return true;
}

string Fleet::toString() const {
    string str = "[" + name + ", " + factionToString(faction) + ", {";
    for (size_t i = 0; i < ships.size(); i++) str += (ships[i].toString() + (i == ships.size() - 1 ? "" : ", "));
    str += "}]";
    return str;
}

int getExtreme(const vector<Spaceship>& ships, bool min) {
    if (ships.empty()) throw runtime_error("error");
    int extreme = ships[0].get_value();
    for (size_t i = 1; i < ships.size() - 1; i++) {
        // toggling search for min / max value using the specified parameter
        if (min) {
            if (ships[i].get_value() < extreme) extreme = ships[i].get_value();
        } else {
            if (ships[i].get_value() > extreme) extreme = ships[i].get_value();
        }
    }
    return extreme;
}

vector<int> Fleet::extremes() const {
    return vector<int>{getExtreme(ships, true), getExtreme(ships, false)};
}

vector<Spaceship> Fleet::elite(Fleet& f) {
    if (f.faction != faction) throw runtime_error("Factions cannot be different!");
    if (f.ships.size() != ships.size()) throw runtime_error("Fleets cannot have different number of ships!");
    vector<Spaceship> result;
    for (size_t i = 0; i < ships.size(); i++) {
        // swap is necessary
        if (f.ships[i].get_value() > this->ships[i].get_value()) {
            result.insert(result.begin(), f.ships[i]); // inserting on the beginning of the list to obtain reversed order
            swap(f.ships[i], this->ships[i]);
        }
    }
    return result;
}

ostream& operator<<(ostream& out, const Fleet& rop) {
    return out << rop.toString();
}