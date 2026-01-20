#include <iostream>
#include <fstream>
#include "magazine.hpp"
#include "scientificMagazine.hpp"
#include "childrenMagazine.hpp"

using namespace std;

int main() {
    // Magazine m1("Комсомольская правда", 24, 5000);
    // Magazine m2("Мурзилка", 24, 5000);

    // //текстовый файл
    // ofstream text("magazine.txt");
    // text << m1;
    // text.close();

    // //запись в бинарный файл
    // ofstream binaryFileOut("magazines.bin", ios::binary);
    // if (binaryFileOut.is_open()) {
    //     writeToBinary(binaryFileOut, m1);
    //     binaryFileOut.close();
    //     cout << "Журнал  успешно записан в двоичный файл: magazine.bin" << endl;
    // }
    // else {
    //     cout << "Ошибка открытия двоичного файла для записи!" << endl;
    // }
    // cout << endl;

    // //чтение бинарного файла
    // Magazine m3; //пустой объект для чтения
    // cout << "\nЖурнал до чтения из бинарного файла:" << endl;
    // //пока пустой
    // m3.print_name();
    // m3.print_issues_per_year();
    // m3.print_circulation();

    // ifstream ifs("magazines.bin", ios::binary);
    // if (!ifs) {
    //     cerr << "Ошибка открытия файла для чтения!" << endl;
    //     return 1;
    // }
    // readFromBinary(ifs, m3);  // читаем объект
    // ifs.close();

    // cout << "\nЖурнал после чтения из бинарного файла:" << endl;
    // //выводим считанный объект
    // m3.print_name();
    // m3.print_issues_per_year();
    // m3.print_circulation();
      
    Magazine* scMag = new ScientificMagazine("Наука и свобода", 53, 10000, 5);
    Magazine* chMag = new ChildrenMagazine("Мурзик", 24, 5000, 0);

    ChildrenMagazine children("Жаваранок", 24, 5000, 0);
    children.print_name();
    children.print_age();

    scMag -> print_magazine();
    chMag -> print_magazine();

    delete scMag;
    delete chMag;
    
    return 0;
}