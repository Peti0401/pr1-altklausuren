//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef ARMADA_FLEET_H
#define ARMADA_FLEET_H

#include "spaceship.h"

class Fleet {

private:
    string name;
    Faction faction;
    vector<Spaceship> ships;

public:
    Fleet(const string&, const Faction&, const vector<Spaceship>&);

    bool add(const vector<Spaceship>&);
    string toString() const;

    // extra functions
    vector<int> extremes() const;
    vector<Spaceship> elite(Fleet&);
};

ostream& operator<<(ostream&, const Fleet&);


#endif //ARMADA_FLEET_H
