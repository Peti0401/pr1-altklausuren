//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "passenger.h"

Passenger::Passenger(const string& name, Category category) : category{category} {
    if (name.empty()) throw runtime_error("name empty!");
    this->name = name;
}

bool Passenger::in_category(Category c) const {
    return category == c;
}

bool Passenger::operator==(const Passenger& rop) const {
    return name == rop.name;
}

string Passenger::to_string() const {
    return "[" + name + ": " + category_names.at(static_cast<size_t>(category)) + "]";
}

Category Passenger::get_category() const {
    return category;
}

ostream& operator<<(ostream& out, const Passenger& rop) {
    return out << rop.to_string();
}
