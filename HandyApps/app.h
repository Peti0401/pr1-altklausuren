//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#ifndef HANDYAPPS_APP_H
#define HANDYAPPS_APP_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum class Category {
    Social, Gadget, Tool, Game
};

const vector<string> category_names{"Social", "Gadget", "Tool", "Game"};

class App {

private:
    string id;
    int memory;
    Category category;

public:
    App(const string&, int, Category category = Category::Game);
    string get_id() const;
    int get_memory() const;
    Category get_category() const;
    bool in_category(Category c) const;

    bool operator==(const App&) const;

    string to_string() const;
};

ostream& operator<<(ostream&, const App&);


#endif //HANDYAPPS_APP_H
