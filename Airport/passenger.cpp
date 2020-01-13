//
// Created by Peter Gyarmati on 2020. 01. 13..
//

#include "passenger.h"

Passenger::Passenger(const string& name, const Category& category) : category{category} {
    if (name.empty()) throw runtime_error("Passenger name cannot be empty!");
    this->name = name;
}

bool Passenger::in_category(Category c) const {
    return category == c;
}

bool Passenger::operator==(const Passenger& rop) const {
    return name == rop.name;
}

Category Passenger::getCategory() const {
    return category;
}

string Passenger::toString() const {
    return "[" + name + ": " + categoryToString(category) + "]";
}

ostream& operator<<(ostream& out, const Passenger& rop) {
    return out << rop.toString();
}