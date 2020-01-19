//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef HANDYAPPS_CELLULAR_H
#define HANDYAPPS_CELLULAR_H

#include "app.h"

class Cellular {
private:
    int memory;
    vector<App> installed;
    vector<string> running;

public:
    Cellular(int);
    int used_memory() const;
    bool install(const App&);
    bool run(const App&);
    void print(ostream&) const;

    // extra functions
    vector<App> deinstall(Category);
    int optimize();
};

ostream& operator<<(ostream&, const Cellular&);

#endif //HANDYAPPS_CELLULAR_H
