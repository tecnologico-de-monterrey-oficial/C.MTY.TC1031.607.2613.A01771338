#ifndef QUEUE_H
#define QUEUE_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Queue() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~Queue() {                  // Destructor Agregado por IA
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }

    void pop() {
        if (head == nullptr) {
            cout << "La fila esta vacia, no se puede hacer dequeue" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
        size--;
    }

    void push(T data) {
        Node<T>* nuevo = new Node<T>(data);
        if (head == nullptr) {
            head = nuevo;
            tail = nuevo;
        } else {
            tail->next = nuevo;
            tail = nuevo;
        }
        size++;
    }

    T front() {
        if (head != nullptr) {
            return head->data;
        }
        return T();
    }

    void print() {
        Node<T>* aux = head;
        while (aux != nullptr) {
            cout << aux->data << " ";
            aux = aux->next;
        }
        cout << endl;
    }

    bool empty() {
        return head == nullptr;
    }

    int getSize() {
        return size;
    }
};

#endif