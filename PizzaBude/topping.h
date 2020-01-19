//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef PIZZABUDE_TOPPING_H
#define PIZZABUDE_TOPPING_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Topping {
private:
    string name;
    string allergenes;
    bool specialty;

public:
    Topping(const string&, const string& allergenes = "", bool speciality = false);
    bool is_specialty() const;
    bool operator==(const Topping&) const;
    string get_allergenes() const;
    string to_string() const;
};

ostream& operator<<(ostream&, const Topping&);

#endif //PIZZABUDE_TOPPING_H
