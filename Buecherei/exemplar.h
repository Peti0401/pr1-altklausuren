//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#ifndef BUECHEREI_EXEMPLAR_H
#define BUECHEREI_EXEMPLAR_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Zustand {
    Neuwertig,
    Gut,
    Abgegriffen,
    Unbrauchbar
};

// using lower cases to match the sample output
static const vector<string> zustand_names{"neuwertig", "gut", "abgegriffen", "unbrauchbar"};
static string zustand_to_string(const Zustand& zustand) {
    const auto value = static_cast<size_t >(zustand);
    return zustand_names.at(value); // using enum value as index
}

class Exemplar {

private:
    int number;
    Zustand state;
    bool is_rented;

public:
    Exemplar(int, const Zustand& state = Zustand::Neuwertig);
    bool verfuegbar() const;
    bool entleihen();
    void retournieren(const Zustand&);
    string to_string() const;

    int get_number() const;
    Zustand get_state() const;

};

ostream& operator<<(ostream&, const Exemplar&);

#endif //BUECHEREI_EXEMPLAR_H
