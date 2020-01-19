//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef FUSSBALLMANNSCHAFT_MANNSCHAFT_H
#define FUSSBALLMANNSCHAFT_MANNSCHAFT_H

#include "spieler.h"

class Mannschaft {
private:
    string name;
    vector<Spieler> players;
public:
    Mannschaft(const string&, const vector<Spieler> players = vector<Spieler>{});
    vector<Spieler> engagieren(const vector<Spieler>&);
    string to_string() const;

    // extra functions
    string aufstellung() const;
    vector<Spieler> entlassen(vector<Position>);
};

ostream& operator<<(ostream&, const Mannschaft&);


#endif //FUSSBALLMANNSCHAFT_MANNSCHAFT_H
