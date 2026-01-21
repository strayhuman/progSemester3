#include "childrenMagazine.hpp"

ChildrenMagazine::ChildrenMagazine() {
    age = 0;
}

ChildrenMagazine::ChildrenMagazine(const char* name, int issues_per_year, int circulation, int age) : Magazine(name, issues_per_year, circulation) {
    if (age < 0) {
        throw invalid_argument("Возрастное ограничение не может быть отрицательным");
    }
    this -> age = age;
}

ChildrenMagazine::ChildrenMagazine(const ChildrenMagazine& other) {
    this -> age = other.age;
}

ChildrenMagazine::~ChildrenMagazine() {

}

int ChildrenMagazine::get_age() {
    return age;
}

void ChildrenMagazine::set_age(int a) {
    if (a < 0) {
        throw invalid_argument("Возрастное ограничение не может быть отрицательным");
    }
    age = a;
}

void ChildrenMagazine::print_age() {
    cout << "Возрастное ограничение журнала: " << age << "+" << endl;
}

void ChildrenMagazine::print_magazine() {
    cout << "++++++++++ " << get_name() << " ++++++++++" << endl;
}