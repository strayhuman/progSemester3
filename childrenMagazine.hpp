#include "magazine.hpp"

class ChildrenMagazine : public Magazine {
private:
    int age;
public:
    //конструкторы
    ChildrenMagazine();
    ChildrenMagazine(const char* name, int issues_per_year, int circulation, int age);
    ChildrenMagazine(const ChildrenMagazine& other);
    //деструктор
    virtual ~ChildrenMagazine();

    //методы
    int get_age();
    void set_age(int a);
    void print_age();
    virtual void print_magazine();

};