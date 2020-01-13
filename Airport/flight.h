//
// Created by Peter Gyarmati on 2020. 01. 13..
//

#ifndef AIRPORT_FLIGHT_H
#define AIRPORT_FLIGHT_H

#include "passenger.h"
using namespace std;


class Flight {
private:
    string no;
    int seats;
    vector<Passenger> checked_in;
    vector<Passenger> boarded;

public:
    Flight(const string& no, int seats);

    bool check_in(const Passenger&);
    bool board(const Passenger&);

    // Extra functions:
    bool ready(const vector<int>&) const;
    void pretty_print() const;

    string toString() const;
};

ostream& operator<<(ostream&, const Flight&);

#endif //AIRPORT_FLIGHT_H
