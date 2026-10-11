#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;
public:
    LinkedList() {
        head = nullptr;
        size = 0;
    }

    ~LinkedList() {                 // Destructor Agregado por IA
        while (head != nullptr) {
            Node<T>* aux = head;
            head = head->next;
            delete aux;
        }
    }

    void push_front(T data);
    void push_back(T data);
    void insert(int index, T data);
    void print();
    int getSize() { return size; }

    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T oldData, T newData);
    void updateAt(int index, T newData);
    int findData(T data);

    T& operator[](int index);
    LinkedList<T>& operator=(const LinkedList<T>& other);
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    Node<T>* node = new Node<T>(data);
    node->next = head;
    head = node;
    size++;    //Size incrementado agregado por IA
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    if (head != nullptr) {
        Node<T>* aux = head;
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = new Node<T>(data);
    } else {
        head = new Node<T>(data);
    }
    size++;
}

template <typename T>
void LinkedList<T>::insert(int index, T data) {
    if (index < 0 || index > size) {
        cout << "Error! that place is invalid" << endl;
        return;
    }
    if (index == 0) {           // AGREGADO POR IA 
        push_front(data);
        return;
    }
    if (index == size) {
        push_back(data);
        return;
    }
    Node<T>* aux = head;
    for (int i = 0; i < index - 1; i++) {
        aux = aux->next;
    }
    Node<T>* node = new Node<T>(data);
    node->next = aux->next;
    aux->next = node;
    size++;
}

template <typename T>
bool LinkedList<T>::deleteData(T data) {
    if (head == nullptr) return false;

    if (head->data == data) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return true;
    }

    Node<T>* auxPrev = head;
    Node<T>* aux = head->next;
    while (aux != nullptr) {
        if (aux->data == data) {
            auxPrev->next = aux->next;
            delete aux;
            size--;
            return true;
        }
        auxPrev = aux;
        aux = aux->next;
    }
    return false;
}

template <typename T>
bool LinkedList<T>::deleteAt(int index) {
    if (index < 0 || index >= size) return false;

    if (index == 0) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return true;
    }

    Node<T>* aux = head;
    for (int i = 0; i < index - 1; i++) {
        aux = aux->next;
    }
    Node<T>* toDelete = aux->next;
    aux->next = toDelete->next;
    delete toDelete;
    size--;
    return true;
}

template <typename T>
T LinkedList<T>::getData(int index) {
    if (index < 0 || index >= size) {
        cout << "Error! that position is invalid" << endl;
        return T();
    }
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
void LinkedList<T>::updateData(T oldData, T newData) {
    Node<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == oldData) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
    cout << "Error! element not found" << endl;
}

template <typename T>
void LinkedList<T>::updateAt(int index, T newData) {
    if (index < 0 || index >= size) {
        cout << "Error! that position is invalid" << endl;
        return;
    }
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->data = newData;
}

template <typename T>
int LinkedList<T>::findData(T data) {
    Node<T>* aux = head;
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == data) return index;
        aux = aux->next;
        index++;
    }
    return -1;
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    static T dummy = T();
    if (index < 0 || index >= size) {
        cout << "Error! that position is invalid" << endl;
        return dummy;
    }
    Node<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& other) {
    if (this == &other) return *this;

    while (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }
    size = 0;

    Node<T>* aux = other.head;
    while (aux != nullptr) {
        push_back(aux->data);
        aux = aux->next;
    }
    return *this;
}

template <typename T>
void LinkedList<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) cout << "-";
    }
    cout << endl;
}

#endif