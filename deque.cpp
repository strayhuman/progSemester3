#include "deque.hpp"
#include "magazine.hpp"
#include <cstring>
#include <iostream>

using namespace std;

//создает пустой список
//Deque::Deque() : head(nullptr), tail(nullptr) {}
 Deque::Deque() {
     head = nullptr;
     tail = nullptr;
 }

Deque::~Deque() {
    while(head) {
        remove_first();
    }
}

void Deque::add_back(Magazine* m) {
    Node* node = new Node;
    node -> data = m;
    node -> next = nullptr;
    node -> prev = tail;

    if (!head) {
        head = tail = node;
    } else {
        tail->next = node;
        tail = node;
    }
   
 }

 void Deque::remove_first() {
    if (!head) return;

    Node* temp = head;
    head = head -> next;

    if (head)
        head -> prev = nullptr;
    else
        tail = nullptr;

    delete temp -> data;
    delete temp;
   
 }

 void Deque::remove_last() {
    if (!tail) return;

    Node* temp = tail;
    tail = tail -> prev;

    if (tail)
        tail -> next = nullptr;
    else
        head = nullptr;

    delete temp -> data;
    delete temp;
 }

void Deque::insert(int index, Magazine* m) {
    if (index <= 0) {
        Node* node = new Node;
        node -> data = m;
        node -> prev = nullptr;
        node -> next = head;

        if (head != nullptr) {
            head -> prev = node;
        } else {
            tail = node;
        }

        head = node;
    } else {
        Node* current_node = head;
        int i = 0;

        while (current_node != nullptr && i < index - 1) {
            current_node = current_node -> next;
            i++;
        }

        if (current_node == nullptr) {
            return;
        } 
        else {
            Node* node = new Node;
            node -> data = m;
            node -> next = current_node -> next;
            node -> prev = current_node;

            if (current_node -> next != nullptr) {
                current_node -> next -> prev = node;
            } 
            else {
                tail = node;
            }
            current_node -> next = node;
        }
    }
}

void Deque::remove(int index) {
     if (head == nullptr) {
        return;
    } 
    else {
        Node* current_node = head;
        int i = 0;

        while (current_node != nullptr && i < index) {
            current_node = current_node -> next;
            i++;
        }

        if (current_node == nullptr) {
            return;
        } 
        else {
            if (current_node -> prev != nullptr) {
                current_node -> prev -> next = current_node -> next;
            } 
            else {
                head = current_node -> next;
            }

            if (current_node -> next != nullptr) {
                current_node -> next -> prev = current_node -> prev;
            } 
            else {
                tail = current_node -> prev;
            }

            delete current_node -> data;
            delete current_node;
        }
    } 
}

Magazine* Deque::find(const char* name) {
    Node* current_node = head;

    while (current_node != nullptr) {
        if (current_node -> data -> has_name(name)) {
            cout << "Журнал найден" << endl;
            return current_node -> data;
        } 
        else {
            current_node = current_node -> next;
        }
    }
    cout << "Журнал не найден" << endl;
    return nullptr;
}

void Deque::print_all() {
    Node* current_node = head;

    while (current_node != nullptr) {
        current_node -> data -> print();   // виртуальный метод
        current_node = current_node -> next;
    }
}







