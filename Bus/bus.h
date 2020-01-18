//
// Created by Peter Gyarmati on 2020. 01. 18..
//

#ifndef BUS_BUS_H
#define BUS_BUS_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum class Station{Bar,Restaurant,Church,Main,Railway,School,University,Park,Parliament,Center};
const std::vector<std::string> station_names{"Bar","Restaurant","Church","Main","Railway","School","University","Park",
                                             "Parliament","Center"};

/**
 * The static functions below can be used generically in other exam exercises as well
 */

template<typename T>
static bool contains_element(const vector<T>& vec, const T& elem) {
    for (const auto& e : vec) if (e == elem) return true;
    return false;
}

template<typename T>
static bool has_duplicate(const vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = i + 1; j < vec.size(); j++)
            if (vec[i] == vec[j]) return true;
    return false;
}

template<typename T>
static size_t first_index_of_element(const vector<T>& vec, const T& elem) {
    for (size_t i = 0; i < vec.size(); i++) if (vec[i] == elem) return i;
    return -1;
}

class Bus {
private:
    string line_number;
    vector<Station> stations;
    int price_per_station;

public:
    Bus(const string&, const vector<Station>&, int price_per_station = 7);
    bool stops_at(Station) const;
    int cost(Station, Station) const;
    string to_string() const;

    const vector<Station>& get_stations() const;

};

ostream& operator<<(ostream&, const Bus&);

#endif //BUS_BUS_H
