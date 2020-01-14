//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef BOUTIQUE_GARMENT_H
#define BOUTIQUE_GARMENT_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Designer {
    Prada,
    Chanel,
    Dior,
    Unknown
};

static vector<string> designer_names{"Prada", "Chanel", "Dior", "Unknown"};
static string designer_to_string(const Designer& designer) {return designer_names[designer];}

class Garment {

private:
    string description;
    int stock;
    Designer designer;
    vector<string> reserved;

public:
    Garment(const string& name, int stock, const Designer& designer = Designer::Unknown);

    bool by_designer(const vector<Designer>&) const;
    int available() const;
    bool reserve(const string&);

    string to_string() const;

    // extra function
    bool buy(const string&);

    const vector<string>& get_reserved() const;

};

ostream& operator<<(ostream&, const Garment&);


#endif //BOUTIQUE_GARMENT_H
