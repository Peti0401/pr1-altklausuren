//
// Created by Peter Gyarmati on 2020. 01. 13..
//

#ifndef AIRPORT_CATEGORY_H
#define AIRPORT_CATEGORY_H

#include <string>
#include <vector>

using namespace std;

enum Category {
    Economy,
    Business,
    First
};

// helper vector to convert enum constants to string
static const vector<string> category_names{"Economy", "Business", "First"};

static string categoryToString(const Category& category) {
    // the passed category instance will be implicitly converted to integer
    return category_names[category];
}

#endif //AIRPORT_CATEGORY_H
