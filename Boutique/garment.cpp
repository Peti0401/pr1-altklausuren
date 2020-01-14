//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "garment.h"

Garment::Garment(const string& description, int stock, const Designer& designer) : designer{designer} {
    if (description.empty()) throw runtime_error("error");
    if (stock < 0) throw runtime_error("error");
    this->description = description;
    this->stock = stock;
}

bool Garment::by_designer(const vector<Designer>& vd) const {
    for (const auto& d : vd) if (d == designer) return true;
    return false;
}

int Garment::available() const {
    return stock - reserved.size();
}

bool Garment::reserve(const string& name) {
    if (name.empty()) throw runtime_error("error");
    bool alreadyReserved = false;
    for (const auto& n : reserved) {
        if (n == name) {
            alreadyReserved = true;
            break;
        }
    }
    if (!available() || alreadyReserved) return false;

    reserved.push_back(name);
    return true;
}

string Garment::to_string() const {
    string str = "[" + description + ": " + designer_to_string(designer) + ", " + std::to_string(available()) + ", {";
    for (size_t i = 0; i < reserved.size(); i++) str += (reserved[i] + (i == reserved.size() - 1 ? "" : ", "));
    str += "}]";
    return str;
}

bool Garment::buy(const string& name) {
    for (auto it = reserved.begin(); it != reserved.end(); it++) {
        if ((*it) == name) {
            it = reserved.erase(it);
            stock--;
            return true;
        }
    }
    if (available()) {
        stock--;
        return true;
    } else {
        return false;
    }
}

const vector<string>& Garment::get_reserved() const {
    return reserved;
}

ostream& operator<<(ostream& out, const Garment& rop) {
    return out << rop.to_string();
}