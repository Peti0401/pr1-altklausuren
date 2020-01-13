//
// Created by Peter Gyarmati on 2020. 01. 13..
//

#include "flight.h"

Flight::Flight(const string& no, int seats) {
    if (no.empty()) throw runtime_error("Flight no. cannot be empty!");
    if (seats < 0) throw runtime_error("Number of seats cannot be negative!");
    this->no = no;
    this->seats = seats;
}

bool containsPassenger(const vector<Passenger>& vec, const Passenger& passenger) {
    for (const auto& p : vec) if (p == passenger) return true;
    return false;
}

bool Flight::check_in(const Passenger& p) {
    bool alreadyCheckedIn = containsPassenger(checked_in, p);
    bool flightIsFull = checked_in.size() == seats;
    if (alreadyCheckedIn || flightIsFull) return false;

    checked_in.push_back(p);
    return true;
}

bool Flight::board(const Passenger& p) {
    bool alreadyCheckedIn = containsPassenger(checked_in, p);
    bool alreadyBoarded = containsPassenger(boarded, p);
    if (!alreadyCheckedIn || alreadyBoarded) return false;

    boarded.push_back(p);
    return true;
}

bool Flight::ready(const vector<int>& seats_per_category) const {
    if (seats_per_category.size() != 3) throw runtime_error("seats_per_category should contain exactly 3 elements!");
    for (const auto& i : seats_per_category) if (i < 0) throw runtime_error("number of seats cannot be negative!");
    // helper vector to track the number of boarded passengers grouped by category
    vector<int> numberOfBoardedPassengersPerCategory{0, 0, 0};
    for (const auto& p : checked_in) {
        // automatically false if there is a passenger who has checked in but has not boarded yet
        if (!containsPassenger(boarded, p)) return false;
        // incrementing the corresponding value of the helper vector
        numberOfBoardedPassengersPerCategory[p.getCategory()]++;
    }
    // evaluating final condition
    for (size_t i = 0; i < 3; i++) if (seats_per_category[i] < numberOfBoardedPassengersPerCategory[i]) return false;
    return true;
}

void Flight::pretty_print() const {
    string str = no;
    vector<Passenger> missing;
    for (const auto& p : checked_in) if (!containsPassenger(boarded, p)) missing.push_back(p);

    if (!boarded.empty()) {
        str += ", boarded: {";
        for (size_t i = 0; i < boarded.size(); i++) str += boarded[i].toString() + ((i == boarded.size() - 1) ? "}" : ", ");
    }

    if (!missing.empty()) {
        str += ", missing: {";
        for (size_t i = 0; i < missing.size(); i++) str += missing[i].toString() + ((i == missing.size() - 1) ? "}" : ", ");
    }

    // actually printing the constructed string
    cout << str;
}

string Flight::toString() const {
    string str = "[" + no + ", {";
    for (size_t i = 0; i < checked_in.size(); i++) {
        const Passenger& passenger = checked_in[i];
        bool alreadyBoarded = containsPassenger(boarded, passenger);
        bool lastPassenger = i == checked_in.size() - 1;
        str += passenger.toString();
        if (alreadyBoarded) str += "*";
        if (!lastPassenger)  str += ", ";
    }
    str += "}]";
    return str;
}

ostream& operator<<(ostream& out, const Flight& rop) {
    return out << rop.toString();
}