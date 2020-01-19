//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "flight.h"

Flight::Flight(const string& number, int seats) {
    if (number.empty()) throw runtime_error("number empty!");
    if (seats < 0) throw runtime_error("seats < 0!");
    this->number = number;
    this->seats = seats;
}

template<typename T>
static bool contains_element(const vector<T>& vec, const T& elem) {
    for (const auto& e : vec) if (e == elem) return true;
    return false;
}

bool Flight::check_in(const Passenger& p) {
    bool already_checked_in = contains_element(checked_in, p);
    bool everyone_checked_in = checked_in.size() == seats;
    if (already_checked_in || everyone_checked_in) return false;
    checked_in.push_back(p);
    return true;
}

bool Flight::board(const Passenger& p) {
    bool not_checked_in_yet = !contains_element(checked_in, p);
    bool already_boarded = contains_element(boarded, p);
    if (not_checked_in_yet || already_boarded) return false;
    boarded.push_back(p);
    return true;
}

string Flight::to_string() const {
    string str = "[" + number + ", {";
    for (size_t i = 0; i < checked_in.size(); i++) {
        bool already_boarded = contains_element(boarded, checked_in[i]);
        str += checked_in[i].to_string();
        if (already_boarded) str += "*";
        if (i != checked_in.size() - 1) str += ", ";
    }
    return str += "}]";
}

bool Flight::ready(const vector<int>& seats_per_category) const {
    if (seats_per_category.size() != 3) throw runtime_error("seats_per_category.size() != 3!");
    for (const auto& s : seats_per_category) if (s < 0) throw runtime_error("s < 0!");

    vector<int> passenger_per_category{0, 0, 0};
    for (const auto& passenger : checked_in) passenger_per_category[static_cast<size_t >(passenger.get_category())]++;

    bool num_seats_per_category_exceeded = false;
    for (size_t i = 0; i < 3; i++) {
        if (seats_per_category[i] < passenger_per_category[i]) {
            num_seats_per_category_exceeded = true;
            break;
        }
    }

    return !num_seats_per_category_exceeded && (checked_in.size() == boarded.size());
}

void Flight::pretty_print() const {
    string str = number;

    if (!boarded.empty()) {
        str += ", boarded: {";
        for (size_t i = 0; i < boarded.size(); i++) {
            str += boarded[i].to_string();
            if (i != boarded.size() - 1) str += ", ";
        }
        str += "}";
    }

    vector<Passenger> missing;
    for (const auto& passenger : checked_in) if (!contains_element(boarded, passenger)) missing.push_back(passenger);

    if (!missing.empty()) {
        str += ", missing: {";
        for (size_t i = 0; i < missing.size(); i++) {
            str += missing[i].to_string();
            if (i != missing.size() - 1) str += ", ";
        }
        str += "}";
    }

    cout << str;
}

ostream& operator<<(ostream& out, const Flight& rop) {
    return out << rop.to_string();
}
