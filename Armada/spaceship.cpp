//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "spaceship.h"

Spaceship::Spaceship(const string& name, const Faction& faction, const Type& type) : faction{faction}, type{type} {
    if (name.empty()) throw runtime_error("Name of a spaceship cannot be empty!");
    this->name = name;
}

int Spaceship::get_value() const {
    return faction == Faction::Rebels ? 2 * type : 3 * type;
}

bool Spaceship::operator<(const Spaceship& rop) const {
    return get_value() < rop.get_value();
}

bool Spaceship::same_faction(const vector<Spaceship>& ships, Faction f) {
    for (const auto& ship : ships) if (ship.faction != f) return false;
    return true;
}

string Spaceship::toString() const {
    return "[" + name + ", " + factionToString(faction) +
            ", " + typeToString(type) + ", " + to_string(get_value()) + "]";
}

ostream& operator<<(ostream& out, const Spaceship& rop) {
    return out << rop.toString();
}

