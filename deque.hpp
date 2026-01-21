#include "magazine.hpp"

class Deque {
private:
    //узел двусвязного списка
    struct Node {
        Magazine* data;
        Node* next;
        Node* prev;

    };
    //голова списка
    Node* head;
     //хвост списка
    Node* tail;

public:
    //конструктор
    Deque();
    //деструктор
    ~Deque();

    //добавление в хвост
    void add_back(Magazine* m);

    //удаление с начала
    void remove_first();

    //удаление с конца
    void remove_last();

    //вставка по номеру
    void insert(int index, Magazine* m);

    //удаление по номеру
    void remove(int index);

    //поиск по названию
    Magazine* find(const char* name);

    //просмотр всей стуктуры
    virtual void print_all();

    
};