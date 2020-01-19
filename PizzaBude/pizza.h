//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef PIZZABUDE_PIZZA_H
#define PIZZABUDE_PIZZA_H

#include "topping.h"

class Pizza {
private:
    vector<Topping> toppings;
public:
    Pizza(const vector<Topping>& desired_toppings = vector<Topping>{},
            const vector<Topping>& undesired_toppings = vector<Topping>{});
    double price() const;
    void print(ostream&) const;

    // extra functions
    string allergenes() const;
    void accommodate(const string&);
};

ostream& operator<<(ostream&, const Pizza&);

#endif //PIZZABUDE_PIZZA_H
