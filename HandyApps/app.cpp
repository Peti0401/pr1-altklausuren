//
// Created by Peter Gyarmati on 2020. 01. 19..
//

#include "app.h"

App::App(const string& id, int memory, Category category) : category{category} {
    if (id.empty()) throw runtime_error("id empty!");
    if (memory <= 0) throw runtime_error("memory <= 0!");
    this->id = id;
    this->memory = memory;
}

string App::get_id() const {
    return id;
}

int App::get_memory() const {
    return memory;
}

Category App::get_category() const {
    return category;
}

bool App::in_category(Category c) const {
    return category == c;
}

bool App::operator==(const App& rop) const {
    return id == rop.id;
}

string App::to_string() const {
    return "[" + id + ": " + category_names.at(static_cast<size_t >(category))
    + ", " + std::to_string(memory) + " MB]";
}

ostream& operator<<(ostream& out, const App& rop) {
    return out << rop.to_string();
}