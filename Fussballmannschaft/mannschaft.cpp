//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "mannschaft.h"

template <typename T>
static bool has_duplicate(const vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); i++)
        for (size_t j = i + 1; j < vec.size(); j++)
            if (vec[i] == vec[j]) return true;

    return false;
}

template<typename T>
static bool contains_element(const vector<T>& vec, const T& elem) {
    for (const auto& e : vec) if (e == elem) return true;
    return false;
}


Mannschaft::Mannschaft(const string& name, vector<Spieler> players) {
    if (name.empty()) throw runtime_error("name empty!");
    if (has_duplicate(players)) throw runtime_error("has duplicate");
    this->name = name;
    this->players = players;
}

vector<Spieler> Mannschaft::engagieren(const vector<Spieler>& new_players) {
    vector<Spieler> result;
    for (const auto& new_player : new_players) {
        if (contains_element(players, new_player))
            result.push_back(new_player);
        else
            players.push_back(new_player);

    }
    return result;
}

string Mannschaft::to_string() const {
    string str = "[" + name + ", {";
    for (size_t i = 0; i < players.size(); i++) {
        str += players[i].to_string();
        if (i != players.size() - 1) str += ", ";
    }
    return str += "}]";
}

string Mannschaft::aufstellung() const {
    // order of indices match the order of the enum declaration
    // 0. - Tor, 1. - Abwehr, 2. - Mitte, 3. - Sturm
    vector<int> number_of_players_per_position{0, 0, 0, 0};
    for (const auto& player : players)
        number_of_players_per_position[static_cast<size_t>(player.get_position())]++;

    int tor = number_of_players_per_position[0];
    int x = number_of_players_per_position[1];
    int y = number_of_players_per_position[2];
    int z = number_of_players_per_position[3];

    if (!(x + y + z + tor == 11 && tor == 1)) throw runtime_error("!(x + y + z + tor == 11 && tor == 1)!");
    return std::to_string(x) + "-" + std::to_string(y) + "-" + std::to_string(z);
}

vector<Spieler> Mannschaft::entlassen(vector<Position> positions) {
    vector<Spieler> result;
    for (auto it = players.begin(); it != players.end();) {
        const auto& player = *it;
        if (contains_element(positions, player.get_position())) {
            result.push_back(player);
            it = players.erase(it);
        } else {
            it++;
        }
    }
    return result;
}

ostream& operator<<(ostream& out, const Mannschaft& rop) {
    return out << rop.to_string();
}
