//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef ARMADA_SPACESHIP_H
#define ARMADA_SPACESHIP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Faction {
    Empire,
    Rebels
};

const static vector<string> factionNameHelper{"Empire", "Rebels"};
static string factionToString(const Faction& faction) {return factionNameHelper[faction];}

enum Type {
    Squadron=10,
    Small=50,
    Medium=100,
    Big=200
};

// helper vector cannot be used, as enum constants have values assigned to them,
// meaning that they cannot be used as indices anymore
static string typeToString(const Type& type) {
    switch (type) {
        case Squadron: return "Squadron";
        case Small: return "Small";
        case Medium: return "Medium";
        case Big: return "Big";
    }
}

class Spaceship {
private:
    string name;
    Faction faction;
    Type type;

public:
    Spaceship(const string&, const Faction&, const Type& type = Type::Squadron);

    int get_value() const;
    bool operator<(const Spaceship&) const;
    static bool same_faction(const vector<Spaceship>&, Faction);
    string toString() const;

};

ostream& operator<<(ostream&, const Spaceship&);

#endif //ARMADA_SPACESHIP_H
