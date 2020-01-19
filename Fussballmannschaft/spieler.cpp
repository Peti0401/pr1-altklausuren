//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "spieler.h"

Spieler::Spieler(const string& name, int transfer_price, Position position) : position{position} {
    if (name.empty()) throw runtime_error("name empty!");
    if (!(10 <= transfer_price && transfer_price <= 500)) throw runtime_error("!(10 <= transfer_price && transfer_price <= 500)!");
    this->name = name;
    this->transfer_price = transfer_price;
}

bool Spieler::operator==(const Spieler& rop) const {
    return name == rop.name;
}

string Spieler::to_string() const {
    return "[" + name + ", " + std::to_string(transfer_price) + " Mio Euro, "
    + position_names.at(static_cast<size_t>(position)) + "]";
}

Position Spieler::get_position() const {
    return position;
}

ostream& operator<<(ostream& out, const Spieler& rop) {
    return out << rop.to_string();
}