#include "Node.h"
using namespace std;
#include <iostream>

template <typename T>
class Stack {
private: 
    Node<T>* head; // Cambiado de top a head

public:
    Stack() {
        head = nullptr;
    }
    
    void pop();
    void push(T data);
    T getTop();
    void print();
};

template <typename T>
void Stack<T>::pop() {
    if (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* nuevo = new Node<T>(data);
    
    if (head == nullptr) {
        nuevo->next = nullptr;
        head = nuevo;
    } else {
        nuevo->next = head;
        head = nuevo;
    }
}

template <typename T>
T Stack<T>::getTop() {
    if (head != nullptr) {
        return head->data;
    }
    return T();
}

template <typenameT>
void Stack<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}
