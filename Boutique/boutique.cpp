//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "boutique.h"

Boutique::Boutique(const vector<Garment>& offer) {
    if (offer.empty()) throw runtime_error("error");
    this->offer = offer;
}

vector<Garment> Boutique::selection(const vector<Designer>& vd) const {
    vector<Garment> result;
    for (const auto& garment : offer) if (garment.available() && garment.by_designer(vd)) result.push_back(garment);
    return result;
}

string Boutique::to_string() const {
    string str = "[{";
    for (size_t i = 0; i < offer.size(); i++) {
        const auto& garment = offer[i];
        if (garment.available()) str += garment.to_string();
        else str += ("*" + garment.to_string() + "*");
        if (i != offer.size() - 1) str += ", ";
    }
    str += "}]";
    return str;
}

vector<Garment> Boutique::sale(Designer d) {
    vector<Garment> result;
    vector<Designer> helperVec{d}; // dummy vector for calling by_designer from Garment
    for (auto it = offer.begin(); it != offer.end(); it++) {
        const auto& garment = *it; // current Garment object
        if (garment.by_designer(helperVec)) {
            if (garment.get_reserved().empty()) offer.erase(it--); // decrementing iterator after deletion
            else result.push_back(garment);
        }
    }
    return result;
}

ostream& operator<<(ostream& out, const Boutique& rop) {
    return out << rop.to_string();
}