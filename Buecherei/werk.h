//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef BUECHEREI_WERK_H
#define BUECHEREI_WERK_H


#include "exemplar.h"

using namespace std;

class Werk {

private:
    string author;
    string name;
    int year_of_publish;
    vector<Exemplar> examplar_list;

public:
    Werk(const string&, const string&, int);
    void erwerben(int, const Zustand&);
    bool entleihen();
    void retournieren(int, const Zustand&);
    string to_string() const;

    // extra functions
    static vector<Werk> erstausgaben(const vector<Werk>&);
    static void aussortieren(vector<Werk>&);
};

ostream& operator<<(ostream&, const Werk&);

#endif //BUECHEREI_WERK_H
