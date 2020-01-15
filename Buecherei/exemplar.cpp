//
// Created by Peter Gyarmati on 2020. 01. 14..
//

#include "exemplar.h"

Exemplar::Exemplar(int number, const Zustand& state) : state{state}, is_rented{false} {
    if (!(1 <= number && number <= 1000)) throw runtime_error("error");
    this->number = number;
}

bool Exemplar::verfuegbar() const {
    return !is_rented && state != Zustand::Unbrauchbar;
}

bool Exemplar::entleihen() {
    return verfuegbar() ? (is_rented = true) : false;
}

void Exemplar::retournieren(const Zustand& z) {
    const auto current_state_value = static_cast<size_t >(state);
    const auto returned_state_value = static_cast<size_t >(z);
    // the lower the value is, the more valuable the state is
    if (is_rented && (current_state_value <= returned_state_value)) {
        state = z;
        is_rented = false;
    } else {
        throw runtime_error("error");
    }
}

string Exemplar::to_string() const {
    return "[Auflage: " + std::to_string(number) +
            ", Zustand: " + zustand_to_string(state) +
            (is_rented ? ", verliehen" : "") + "]";
}

int Exemplar::get_number() const {
    return number;
}

Zustand Exemplar::get_state() const {
    return state;
}

ostream& operator<<(ostream& out, const Exemplar& rop) {
    return out << rop.to_string();
}