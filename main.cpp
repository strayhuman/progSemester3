#include <iostream>
#include <fstream>
#include "magazine.hpp"
#include "scientificMagazine.hpp"
#include "childrenMagazine.hpp"
#include "deque.hpp"

using namespace std;

int main() {
    //  Deque d;
    //  int choice;
    //  do {
    //     cout << "\n=== МЕНЮ ПРОГРАММЫ ===\n";
    //     cout << "1. Добавить журнал в конец\n";
    //     cout << "2. Удалить журнал с начала\n";
    //     cout << "3. Удалить журнал с конца\n";
    //     cout << "4. Вставить журнал по номеру\n";
    //     cout << "5. Удалить журнал по номеру\n";
    //     cout << "6. Найти журнал по названию\n";
    //     cout << "7. Показать все журналы\n";
    //     cout << "0. Выход\n";
    //     cout << "Выберите действие: ";
    //     cin >> choice;

    //     switch(choice) {
    //         case 1: {
    //             int type;
    //             cout << "Выберите тип журнала (1 - Научный, 2 - Детский): ";
    //             cin >> type;
    //             string name;
    //             int issues, circulation;
    //             cout << "Введите название журнала: ";
    //             cin >> ws;
    //             getline(cin, name);
    //             cout << "Введите количество выпусков в год: ";
    //             cin >> issues;
    //             cout << "Введите тираж: ";
    //             cin >> circulation;

    //             if (type == 1) {
    //                 int impact;
    //                 cout << "Введите импакт-фактор: ";
    //                 cin >> impact;
    //                 d.add_back(new ScientificMagazine(name.c_str(), issues, circulation, impact));
    //             } else {
    //                 int age;
    //                 cout << "Введите возрастное ограничение: ";
    //                 cin >> age;
    //                 d.add_back(new ChildrenMagazine(name.c_str(), issues, circulation, age));
    //             }
    //             break;
    //         }
    //         case 2:
    //             d.remove_first();
    //             break;
    //         case 3:
    //             d.remove_last();
    //             break;
    //         case 4: {
    //             int index, type;
    //             cout << "Введите номер позиции для вставки: ";
    //             cin >> index;
    //             cout << "Выберите тип журнала (1 - Научный, 2 - Детский): ";
    //             cin >> type;
    //             string name;
    //             int issues, circulation;
    //             cout << "Введите название журнала: ";
    //             cin >> ws;
    //             getline(cin, name);
    //             cout << "Введите количество выпусков в год: ";
    //             cin >> issues;
    //             cout << "Введите тираж: ";
    //             cin >> circulation;

    //             if (type == 1) {
    //                 int impact;
    //                 cout << "Введите импакт-фактор: ";
    //                 cin >> impact;
    //                 d.insert(index, new ScientificMagazine(name.c_str(), issues, circulation, impact));
    //             } else {
    //                 int age;
    //                 cout << "Введите возрастное ограничение: ";
    //                 cin >> age;
    //                 d.insert(index, new ChildrenMagazine(name.c_str(), issues, circulation, age));
    //             }
    //             break;
    //         }
    //         case 5: {
    //             int index;
    //             cout << "Введите номер журнала для удаления: ";
    //             cin >> index;
    //             d.remove(index);
    //             break;
    //         }
    //         case 6: {
    //             string name;
    //             cout << "Введите название журнала для поиска: ";
    //             cin >> ws;
    //             getline(cin, name);
    //             d.find(name.c_str());
    //             break;
    //         }
    //         case 7:
    //             d.print_all();
    //             break;
    //         case 0:
    //             cout << "Выход из программы.\n";
    //             break;
    //         default:
    //             cout << "Неверный выбор, попробуйте снова.\n";
    //     }

    // } while(choice != 0);

    // d.add_back(new ScientificMagazine("Наука и свобода", 12, 10000, 10));
    // d.add_back(new ChildrenMagazine("Мурзик", 24, 20000, 6));

    // d.print_all();

    // d.insert(1, new ScientificMagazine("Тайна и правда", 6, 8000, 8));
    // cout << '\n';

    // Magazine* found = d.find("Бабочка");

    // d.print_all();

    // cout <<'\n';

    // d.remove(0);
    // d.remove_first();
    // d.remove_last();

    // d.print_all();
    
    return 0;
}