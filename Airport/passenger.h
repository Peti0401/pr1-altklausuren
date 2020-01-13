//
// Created by Peter Gyarmati on 2020. 01. 13..
//

#ifndef AIRPORT_PASSENGER_H
#define AIRPORT_PASSENGER_H


#include <iostream>
#include <string>
#include "category.h"

using namespace std;


class Passenger {
private:
    string name;
    Category category;

public:
    // using default value in the constructor instead of declaring 2 separate constructors
    Passenger(const string&, const Category& category = Category::Economy);

    bool in_category(Category c) const;
    bool operator==(const Passenger&) const;

    // necessary for one of the extra functions
    Category getCategory() const;

    string toString() const;
};

ostream& operator<<(ostream&, const Passenger&);

#endif //AIRPORT_PASSENGER_H
