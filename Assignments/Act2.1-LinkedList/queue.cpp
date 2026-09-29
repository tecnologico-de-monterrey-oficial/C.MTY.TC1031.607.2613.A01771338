#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private: 
    Node<T>* head; 
    Node<T>* tail;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    
    void pop();
    void push(T data);
    T front();
    void print();
};

template <typename T>
void Queue<T>::pop() {
    if (head != nullptr) {
        if (head == tail) {
            Node<T>* aux = head;
            delete aux;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }
}

template <typename T>
void Queue<T>::push(T data) {
    Node<T>* nuevo = new Node<T>(data);
    nuevo->next = nullptr;

    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;
    } else {
        tail->next = nuevo;
        tail = nuevo;
    }
}

template <typename T>
T Queue<T>::front() {
    if (head != nullptr) {
        return head->data;
    }
    return T(); 
}

template <typename T>
void Queue<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}





