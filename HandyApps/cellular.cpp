//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "cellular.h"

Cellular::Cellular(int memory) {
    if (memory <= 0) throw runtime_error("memory <= 0!");
    this->memory = memory;
}

int Cellular::used_memory() const {
    int sum = 0;
    for (const auto& app : installed) sum += app.get_memory();
    return sum;
}

template<typename T>
static bool contains_element(const vector<T>& vec, const T& elem) {
    for (const auto& e : vec) if (e == elem) return true;
    return false;
}

bool Cellular::install(const App& app) {
    bool already_installed = contains_element(installed, app);
    bool out_of_storage = (used_memory() + app.get_memory()) / 1024.0 > memory;
    if (already_installed || out_of_storage) return false;
    installed.push_back(app);
    return true;
}

bool Cellular::run(const App& app) {
    bool already_running = contains_element(running, app.get_id());
    bool not_installed_yet = !contains_element(installed, app);
    if (already_running || not_installed_yet) return false;
    running.push_back(app.get_id());
    return true;
}

void Cellular::print(ostream& out) const {
    out << "[{";
    for (size_t i = 0; i < installed.size(); i++) {
        bool is_running = contains_element(running, installed[i].get_id());
        out <<  installed[i].to_string();
        if (is_running) out <<  "*";
        if (i != installed.size() - 1) out <<  ", ";
    }

    double occupied_gb = used_memory() / 1024.0;
    out << "} " << occupied_gb << "/" << memory << " GB]";
}

vector<App> Cellular::deinstall(Category c) {
    vector<App> result;
    for (auto it = installed.begin(); it != installed.end();) {
        if (it->in_category(c)) {
            bool is_running = contains_element(running, it->get_id());
            if (is_running) {
                result.push_back(*it);
                it++;
                continue;
            } else {
                it = installed.erase(it);
            }
        } else {
            it++;
        }
    }
    return result;
}

int Cellular::optimize() {
    vector<vector<App>> groups(4);
    // grouping apps based on category
    for (const auto& app : installed) groups[static_cast<size_t >(app.get_category())].push_back(app);

    // clearing the original installed list then adding the apps in order
    installed.clear();
    for (const auto& group : groups) for (const auto& app : group) installed.push_back(app);

    // calculating empty number of empty categories
    int num_empty_categories = 0;
    for (const auto& group : groups) if (group.empty()) num_empty_categories++;
    return num_empty_categories;
}

ostream& operator<<(ostream& out, const Cellular& rop) {
    rop.print(out);
    return out;
}