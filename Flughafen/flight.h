//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef FLUGHAFEN_FLIGHT_H
#define FLUGHAFEN_FLIGHT_H

#include "passenger.h"

class Flight {
private:
    string number;
    int seats;
    vector<Passenger> checked_in;
    vector<Passenger> boarded;
public:
    Flight(const string&, int);
    bool check_in(const Passenger&);
    bool board(const Passenger&);
    string to_string() const;

    // extra functions
    bool ready(const vector<int>&) const;
    void pretty_print() const;
};

ostream& operator<<(ostream&, const Flight&);

#endif //FLUGHAFEN_FLIGHT_H
