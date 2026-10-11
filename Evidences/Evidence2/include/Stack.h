#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    Node<T>* head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }

    ~Stack() {                  // Destructor Agregado por IA
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }

    void pop();
    void push(T data);
    T getTop();
    void print();
    bool empty();
    int getSize();
};

template <typename T>
void Stack<T>::pop() {
    if (head == nullptr) {
        cout << "La pila esta vacia, no se puede hacer pop" << endl;
        return;
    }
    Node<T>* aux = head;
    head = head->next;
    delete aux;
    size--;
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* nuevo = new Node<T>(data);
    nuevo->next = head;
    head = nuevo;
    size++;
}

template <typename T>
T Stack<T>::getTop() {
    if (head != nullptr) {
        return head->data;
    }
    return T();
}

template <typename T>
void Stack<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <typename T>
bool Stack<T>::empty() {
    return head == nullptr;
}

template <typename T>
int Stack<T>::getSize() {
    return size;
}

#endif