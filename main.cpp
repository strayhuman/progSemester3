#include <iostream>
#include <fstream>
#include "magazine.hpp"
#include "scientificMagazine.hpp"
#include "childrenMagazine.hpp"
#include "deque.hpp"


using namespace std;
void show_menu() {
    cout << "\nМЕНЮ\n";
    cout << "1. Добавить обычный журнал\n";
    cout << "2. Добавить детский журнал\n";
    cout << "3. Добавить научный журнал\n";
    cout << "4. Удалить первый журнал\n";
    cout << "5. Удалить последний журнал\n";
    cout << "6. Удалить журнал по номеру\n";
    cout << "7. Найти журнал по названию\n";
    cout << "8. Показать все журналы\n";
    cout << "0. Выход\n";
    cout << "Выбор: ";
}

int main() {
    Deque d;
 
    int choice = -1;

    while (choice != 0) {
        show_menu();
        cin >> choice;
        cin.ignore(); // очистка буфера

        if (choice == 1) {
            char name[100];
            int issues, circulation;
            try{
                cout << "Название: ";
                cin.getline(name, 100);
                cout << "Выпусков в год: ";
                cin >> issues;
                cout << "Тираж: ";
                cin >> circulation;
                
                d.add_back(new Magazine(name, issues, circulation));
            }
            catch(invalid_argument exception) {
                cout << "Значения не могут быть отрицательными" << endl;
            }

        }
            

        else if (choice == 2) {
            char name[100];
            int issues, circulation, age;
            cout << "Название: ";
            cin.getline(name, 100);
            cout << "Выпусков в год: ";
            cin >> issues;
            cout << "Тираж: ";
            cin >> circulation;
             try{
                d.add_back(new ChildrenMagazine(name, issues, circulation, age));
            }
            catch(invalid_argument exception) {
                cout << "Значения не могут быть отрицательными" << endl;
            }
            cout << "Возрастное ограничение: ";
            cin >> age;
            try {
                d.add_back(new ChildrenMagazine(name, issues, circulation, age));

            }
            catch (invalid_argument exception) {
                cout << "Возрастное ограничение не может быть отрицательным" << endl;
            }
            
            
           
        }

        else if (choice == 3) {
            char name[100];
            int issues, circulation, impact;
            cout << "Название: ";
            cin.getline(name, 100);
            cout << "Выпусков в год: ";
            cin >> issues;
            cout << "Тираж: ";
            cin >> circulation;
            try{
                d.add_back(new ScientificMagazine(name, issues, circulation, impact));
            }
            catch(invalid_argument exception) {
                cout << "Значения не могут быть отрицательными" << endl;
            }
            cout << "Импакт-фактор: ";
            cin >> impact;
            try {
                d.add_back(new ScientificMagazine(name, issues, circulation, impact));
            }
            catch (invalid_argument exception) {
                cout << "Импакт-фактор не может быть отрицательным" << endl;
            }
        }

        else if (choice == 4) {
            try {
                 d.remove_first();
            }
            catch(runtime_error exception) {
                cout << "Дек пуст, удаление невозможно" << endl;
            }
           
        }

        else if (choice == 5) {
            try {
                 d.remove_last();
            }
            catch(runtime_error exception) {
                cout << "Дек пуст, удаление невозможно" << endl;
            }
            
        }

        else if (choice == 6) {
            int index;
            cout << "Введите номер: ";
            cin >> index;
            d.remove(index);
        }

        else if (choice == 7) {
            char name[100];
            cout << "Введите название: ";
            cin.getline(name, 100);
            d.find(name);
        }

        else if (choice == 8) {
            d.print_all();
        }

        else if (choice == 0) {
            cout << "Выход...\n";
        }

        else {
            cout << "Неверный пункт меню\n";
        }
    }


  
    
    return 0;
}