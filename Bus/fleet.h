//
// Created by Peter Gyarmati on 2020. 01. 18..
//

#ifndef BUS_FLEET_H
#define BUS_FLEET_H

#include "bus.h"

class Fleet {
private:
    string owner;
    vector<Bus> buses;
public:
    Fleet(const string&, const vector<Bus>& buses = vector<Bus>{});
    void add_line(const Bus&);
    vector<Bus> stops_at(Station) const;
    string to_string() const;

    // extra functions
    vector<Bus> has_loop() const;
    vector<Bus> cheapest_connection(Station, Station) const;
};

ostream& operator<<(ostream&, const Fleet&);


#endif //BUS_FLEET_H
