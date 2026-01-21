#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Magazine {
private:
    //поля класса
    char* name;
    int issues_per_year;
    int circulation;
public:
    //конструктор  с параметрами
    Magazine(const char* name, int issues_per_year, int circulation);
    //конструктор копирования
    Magazine(const Magazine& other);
    //конструктор по умолчанию
    Magazine();

    //деструктор
    ~Magazine();

    //методы
    //get - возращает значение
    char* get_name();
    int get_issues_per_year();
    int get_circulation();
    
    //set - изменяет значение
    void set_name(const char* new_name);
    void set_issues_per_year(int i);
    void set_circulation(int c);

    //print - выводит значение
    void print_name();
    void print_issues_per_year();
    void print_circulation();
    virtual void print_magazine();

    //сложение(выпуск в год и выпуск в год, тираж и тираж) метод
    Magazine operator+(const Magazine& other);

    //вычитание(выпуск в год и выпуск в год, тираж и тираж) дружественная
    friend Magazine operator-(const Magazine& mag1, const Magazine& mag2);

    //присваивание метод
    Magazine& operator=(const Magazine& other);

    //инкремент постфиксный метод
    Magazine operator++(int);

    //инкремент префиксный метод
    Magazine& operator++();

    //приведение к int
    operator int();

    //текстовые файлы
    friend ofstream& operator<<(ofstream& ofs, const Magazine& m);

    //бинарные файлы
    friend ofstream& writeToBinary(ofstream& ofs, const Magazine& m);
    friend ifstream& readFromBinary(ifstream& ifs, Magazine& m);

     virtual void print();

     bool has_name(const char* other_name) const;

};

    
