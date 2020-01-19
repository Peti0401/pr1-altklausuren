//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef FUSSBALLMANNSCHAFT_SPIELER_H
#define FUSSBALLMANNSCHAFT_SPIELER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Position {
    Tor, Abwehr, Mitte, Sturm
};

const vector<string> position_names{"Tor", "Abwehr", "Mitte", "Sturm"};

class Spieler {
private:
    string name;
    int transfer_price;
    Position position;
public:
    Spieler(const string&, int, Position position = Position::Tor);
    bool operator==(const Spieler&) const;
    string to_string() const;
    Position get_position() const;
};

ostream& operator<<(ostream&, const Spieler&);

#endif //FUSSBALLMANNSCHAFT_SPIELER_H