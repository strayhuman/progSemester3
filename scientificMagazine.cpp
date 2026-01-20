#include "scientificMagazine.hpp"

ScientificMagazine::ScientificMagazine() {
    impact_factor = 0;
}

ScientificMagazine::ScientificMagazine(const char* name, int issues_per_year, int circulation, int impact_factor) : Magazine(name, issues_per_year, circulation) {
    this -> impact_factor = impact_factor;
}

ScientificMagazine::ScientificMagazine(const ScientificMagazine& other) {
    this -> impact_factor = other.impact_factor;
}

ScientificMagazine::~ScientificMagazine() {
    
}

int ScientificMagazine::get_impact_factor() {
    return impact_factor;
}

void ScientificMagazine::set_impact_factor(int imp) {
    impact_factor = imp;
}

void ScientificMagazine::print_impact_factor() {
    cout << "Импакт-фактор научного журнала: " << impact_factor << endl;
}

void ScientificMagazine::print_magazine() {
    cout << "---------- " << get_name() << " -----------" << endl;
}

