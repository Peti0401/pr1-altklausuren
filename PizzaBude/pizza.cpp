//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "pizza.h"

template<typename T>
static bool contains_element(const vector<T>& vec, const T& elem) {
    for (const auto& e : vec) if (e == elem) return true;
    return false;
}

Pizza::Pizza(const vector<Topping>& desired_toppings, const vector<Topping>& undesired_toppings) {
    static const Topping standard_topping_1{"Tomato sauce"};
    static const Topping standard_topping_2{"Cheese", "G"};
    if (!contains_element(undesired_toppings, standard_topping_1)) toppings.push_back(standard_topping_1);
    if (!contains_element(undesired_toppings, standard_topping_2)) toppings.push_back(standard_topping_2);
    for (const auto& t : desired_toppings) if (!contains_element(toppings, t)) toppings.push_back(t);
    if (toppings.empty()) throw runtime_error("toppings empty!");
}

double Pizza::price() const {
    double price = 0;
    int num_all_toppings = toppings.size();
    int num_special_toppings = 0;
    for (const auto& topping : toppings) if (topping.is_specialty()) num_special_toppings++;

    double special_extra_price = num_special_toppings * 0.5;
    price = 7 + (num_all_toppings - 4) + special_extra_price;
    return price < 7 ? (7 + special_extra_price) : price;
}

void Pizza::print(ostream& out) const {
    out << "[{";
    for (size_t i = 0; i < toppings.size(); i++) {
        out << toppings[i].to_string();
        if (i != toppings.size() - 1) out << ", ";
    }
    out << "}, " << price() << " Euro]";
}

static void insert_char_in_order(string& str, const char ch) {
    if (str.empty()) { // first character
        str.insert(0,1,  ch);
    } else {
        for (size_t i = 0; i < str.size(); i++) {
            if (str[i] > ch) { // found its place
                str.insert(i, 1, ch);
                return;
            } else if (i == str.size() - 1) {
                str += ch;
                return;
            }
        }
    }
}

// Logic:
// Initialize a string str with value A
// Iterate over all toppings
// check the allergenes of each topping char by char
// check if the allergene represented by the current char is already present in str
// if not then insert it to str in alphabetic order
string Pizza::allergenes() const {
    string str = "A";
    for (const auto& topping : toppings)
        for (char ch : topping.get_allergenes())
            if (str.find(ch) == string::npos) // if the current allergen is not yet in str
                insert_char_in_order(str, ch); // insert

    return str;
}

void Pizza::accommodate(const string& forbidden) {
    vector<Topping> backup = toppings;
    for (auto it = toppings.begin(); it != toppings.end();) {
        bool should_erase = false;
        for (char ch : it->get_allergenes()) {
            if (forbidden.find(ch) != string::npos) {
                should_erase = true;
                break;
            }
        }
        it = should_erase ? toppings.erase(it) : (it + 1);
    }
    if (toppings.empty()) {
        toppings = backup;
        throw runtime_error("All toppings removed");
    }
}

ostream& operator<<(ostream& out, const Pizza& rop) {
    rop.print(out);
    return out;
}
