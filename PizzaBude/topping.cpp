//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "topping.h"

Topping::Topping(const string& name, const string& allergenes, bool specialty)
: allergenes{allergenes}, specialty{specialty} {
    if (name.empty()) throw runtime_error("name empty!");
    this->name = name;
}

bool Topping::is_specialty() const {
    return specialty;
}

bool Topping::operator==(const Topping& rop) const {
    return name == rop.name;
}

string Topping::to_string() const {
    string str = name;
    if (!allergenes.empty()) {
        str += " (";
        for (size_t i = 0; i < allergenes.length(); i++) {
            str += allergenes[i];
            if (i != allergenes.length() - 1) str += ", ";
        }
        str += ")";
    }
    return str;
}

string Topping::get_allergenes() const {
    return allergenes;
}

ostream& operator<<(ostream& out, const Topping& rop) {
    return out << rop.to_string();
}
