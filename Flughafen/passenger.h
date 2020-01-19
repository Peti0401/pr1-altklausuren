//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef FLUGHAFEN_PASSENGER_H
#define FLUGHAFEN_PASSENGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Category {
    Economy, Business, First
};

const vector<string> category_names{"Economy", "Business", "First"};

class Passenger {
private:
    string name;
    Category category;
public:
    Passenger(const string&, Category category = Category::Economy);
    bool in_category(Category c) const;
    bool operator==(const Passenger&) const;
    string to_string() const;
    Category get_category() const;
};

ostream& operator<<(ostream&, const Passenger&);

#endif //FLUGHAFEN_PASSENGER_H
