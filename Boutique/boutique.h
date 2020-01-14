//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef BOUTIQUE_BOUTIQUE_H
#define BOUTIQUE_BOUTIQUE_H

#include "garment.h"


class Boutique {

private:
    vector<Garment> offer;

public:
    Boutique(const vector<Garment>&);
    vector<Garment> selection(const vector<Designer>&) const;
    string to_string() const;

    // extra functions
    vector<Garment> sale(Designer);
};

ostream& operator<<(ostream&, const Boutique&);


#endif //BOUTIQUE_BOUTIQUE_H
