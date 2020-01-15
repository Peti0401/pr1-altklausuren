//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "werk.h"

Werk::Werk(const string& author, const string& name, int year_of_publish) {
    if (author.empty()) throw runtime_error("error");
    if (name.empty()) throw runtime_error("error");
    if (!(1700 <= year_of_publish && year_of_publish <= 2017)) throw runtime_error("error");
    this->author = author;
    this->name = name;
    this->year_of_publish = year_of_publish;
}

void Werk::erwerben(int nr, const Zustand &z) {
    if (z == Zustand::Unbrauchbar) throw runtime_error("error");
    examplar_list.push_back({nr, z});
}

bool Werk::entleihen() {
    for (auto& examplar : examplar_list) {
        if (examplar.verfuegbar()) {
            examplar.entleihen();
            return true;
        }
    }
    return false;
}

void Werk::retournieren(int index, const Zustand &z) {
    if (index >= examplar_list.size()) throw runtime_error("error");
    examplar_list[index].retournieren(z);
}

string Werk::to_string() const {
    string str = "[" + author + ", " + name + ", " + std::to_string(year_of_publish) + " {";
    for (size_t i = 0; i < examplar_list.size(); i++)
        str += (examplar_list[i].to_string() + (i == examplar_list.size() - 1 ? "" : ", "));
    str += "}]";
    return str;
}

vector<Werk> Werk::erstausgaben(const vector<Werk>& bestand) {
    vector<Werk> result;
    for (const auto& werk : bestand) {
        for (const auto& examplar : werk.examplar_list) {
            if (examplar.get_number() == 1) {
                result.push_back(werk);
                break;
            }
        }
    }
    return result;
}

void Werk::aussortieren(vector<Werk>& bestand) {
    for (auto& werk : bestand)
        for (auto it = werk.examplar_list.begin(); it != werk.examplar_list.end();)
            it = (*it).get_state() == Zustand::Unbrauchbar ? werk.examplar_list.erase(it) : (it + 1);
}

ostream& operator<<(ostream& out, const Werk& rop) {
    return out << rop.to_string();
}