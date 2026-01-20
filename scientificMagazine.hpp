#include "magazine.hpp"

class ScientificMagazine : public Magazine {
    private:
    int impact_factor;
public:
    //конструкторы
    ScientificMagazine();
    ScientificMagazine(const char* name, int issues_per_year, int circulation, int impact_factor);
    ScientificMagazine(const ScientificMagazine& other);
    //деструктор
    virtual ~ScientificMagazine();

    //методы
    int get_impact_factor();
    void set_impact_factor(int imp);
    void print_impact_factor();
    virtual void print_magazine();

};