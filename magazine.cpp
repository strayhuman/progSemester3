#include <cstring>
#include <iostream>
#include <fstream>
#include "magazine.hpp"

using namespace std;

Magazine::Magazine(const char* name, int issues_per_year, int circulation) {
    if (name != nullptr) {
        this -> name = new char[strlen(name) + 1]; // выделяем точный размер
        strcpy(this -> name, name);
    } 
    else {
        this -> name = nullptr;
    }
    if (issues_per_year < 0 || circulation < 0) {
        throw invalid_argument("Количество выпусков и тираж не могут быть отрицательными");
    }

    this -> issues_per_year = issues_per_year;
    this -> circulation = circulation;
}

Magazine::Magazine(const Magazine& other) {
    if (other.name != nullptr) {
        name = new char[strlen(other.name) + 1];
        strcpy(this -> name, other.name);
    } else {
        name = nullptr;
    }
    this -> issues_per_year = other.issues_per_year;
    this -> circulation = other.circulation;
}

 Magazine::Magazine() {
    name = new char[10];
    name = nullptr;
    issues_per_year = 0;
    circulation = 0;
 }

Magazine::~Magazine() {
    delete [] name;
}

char* Magazine::get_name() {
    char* nameCopy = new char[10];
    strcpy(nameCopy, this -> name);
    return nameCopy;
}

int Magazine::get_issues_per_year() {
    return issues_per_year;
}

int Magazine::get_circulation() {
    return circulation;
}

void Magazine::set_name(const char* new_name) {
    strcpy(this -> name, new_name);
}

void Magazine::set_issues_per_year(int i) {
    issues_per_year = i;
}
void Magazine::set_circulation(int c) {
    circulation = c;
}

void Magazine::print_name() {
    cout << "Название журнала: " << name << endl;
}

void Magazine::print_issues_per_year() {
    cout << "Количество выпусков в год: " << issues_per_year << endl;
}

void Magazine::print_circulation() {
    cout << "Тираж: " << circulation << endl;
}

void Magazine::print_magazine() {
    cout << "********** " << name << " **********" << endl;
}

 Magazine Magazine::operator+(const Magazine& other) {
    Magazine result(*this);
    result.issues_per_year += other.issues_per_year;
    result.circulation += other.circulation;
    return result;
}

Magazine operator-(const Magazine& mag1, const Magazine& mag2) {
    Magazine result(mag1);
    result.issues_per_year -= mag2.issues_per_year;
    result.circulation -= mag2.circulation;
    return result;
}

 Magazine& Magazine::operator=(const Magazine& other) {
    if (this != &other) {
        delete[] name;
        strcpy(this -> name, other.name);
        issues_per_year = other.issues_per_year;
        circulation = other.circulation;
    }
    return *this;
 }

 Magazine Magazine::operator++(int) {
    Magazine temp(*this);
    issues_per_year ++;
    circulation ++;
    return *this;
 }

 Magazine& Magazine::operator++() {
    Magazine temp(*this);
    issues_per_year ++;
    circulation ++;
    return *this;
 }

 Magazine::operator int() {
    return circulation;
 }

//перегрузка оператора вывода для текстовых файлов
ofstream& operator<<(ofstream& ofs, const Magazine& m) {
    if (ofs.is_open()) {
        ofs << m.name << "\n";
        ofs << m.issues_per_year << "\n";
        ofs << m.circulation << "\n";
    }
    return ofs;
}

//запись двоичного файла
ofstream& writeToBinary(ofstream& ofs, const Magazine& m) {
    if (ofs.is_open()) {//проверяем что файл для записи открыт
        int nameLength = strlen(m.name);//определяем длину названия
        ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));//записываем длину названия в файл
        ofs.write(m.name, nameLength);//записываем название в бинарном виде

        ofs.write(reinterpret_cast<const char*>(&m.issues_per_year), sizeof(m.issues_per_year));//записываем кол-во выпусков в год
        ofs.write(reinterpret_cast<const char*>(&m.circulation), sizeof(m.circulation));//записываем тираж
        //вывод на экран для проверки
        cout << "Данные записаны в двоичный файл:" << endl;
        cout << "  Название: " << m.name << " (длина: " << nameLength << ")" << endl;
        cout << "  Выпусков в год: " << m.issues_per_year << endl;
        cout << "  Тираж: " << m.circulation << endl;
    }
    return ofs;
}


//чтение из двоичного файла
ifstream& readFromBinary(ifstream& ifs, Magazine& m) {
    if (ifs.is_open()) {
        //сначала читаем длину названия
        int nameLength;
        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        //читаем само название
        delete[] m.name; //освобождаем старую память
        m.name = new char[nameLength + 1];
        ifs.read(m.name, nameLength);
        m.name[nameLength] = '\0'; //добавляем нулевой терминатор

        //читаем количество выпусков в год и тираж
        ifs.read(reinterpret_cast<char*>(&m.issues_per_year), sizeof(m.issues_per_year));
        ifs.read(reinterpret_cast<char*>(&m.circulation), sizeof(m.circulation));

        //вывод на экран для проверки
        cout << "Данные прочитаны из двоичного файла:" << endl;
        cout << "  Название: " << m.name << " (длина: " << nameLength << ")" << endl;
        cout << "  Выпусков в год: " << m.issues_per_year << endl;
        cout << "  Тираж: " << m.circulation << endl;
    } else {
        cout << "Ошибка: не удалось открыть двоичный файл для чтения" << endl;
    }

    return ifs;
}

void Magazine::print() {

    cout << "Название: " << name << ", Выпусков в год: " << issues_per_year << ", Тираж: " << circulation << endl;
}

bool Magazine::has_name(const char* other_name) const {
    return name && other_name && strcmp(name, other_name) == 0;
}





 






