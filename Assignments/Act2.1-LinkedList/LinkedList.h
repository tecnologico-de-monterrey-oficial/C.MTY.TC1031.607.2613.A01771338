//Elena María Barrios Jordán
//A01771338

#ifndef LinkedList_h
#define LinkedList_h

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
void LinkedList<T>::push_front(T data) { //agrega al frente
    Node<T>* node = new Node<T>(data);
    node->next = head;
    head = node;
    size++;
}

template <typename T>
void LinkedList<T>::push_back(T data) { //agrega al final
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
void LinkedList<T>::insert(int index, T data) { //agregamos en una posicion especifica
    if (index < 0 && index >= size) {
        cout << "Error! that place is invalid" << endl;
        return;
    }
    if (index == size) { //checamos si es el final y lo agregamos
        push_back(data);
        return;
    }
    Node<T>* aux = head;
    for (int i = 0; i < index - 1; i++) {  // buscamos el nodo anterior
        aux = aux->next; // avanzamos al siguiente nodo  
    }
    Node<T>* node = new Node<T>(data); //y ahi lo insertamos
    node->next = aux->next;
    aux->next = node;
    size++;
}

template <typename T>
bool LinkedList<T>::deleteData(T data) { //borramos en alguna posicion
    if (head == nullptr) return false; //si la lista esta vacia da false 

    if (head->data == data) {  //si el primer nodo es el que queremos borrar
        Node<T>* aux = head;
        head = head->next;
        delete aux;
        size--;
        return true;
    }

    Node<T>* auxPrev = head; //si no es el primer nodo, buscamos el nodo anterior al que queremos borrar
    Node<T>* aux = head->next; // avanzamos al siguiente nodo
    while (aux != nullptr) {
        if (aux->data == data) { //si encontramos el dato
            auxPrev->next = aux->next; //apuntamos el nodo anterior al siguiente del actual
            delete aux; //eliminamos el nodo actual
            size--;
            return true;
        }
        auxPrev = aux; // convertimos auxPrev al nodo actual para seguir buscando
        aux = aux->next; // avanzamos al siguiente nodo hasta encontrar el que queremos borrar
    }
    return false;
}

template <typename T>
bool LinkedList<T>::deleteAt(int index) {
    if (index < 0 && index >= size) return false; 

    if (index == 0) {  // si es el primer nodo
        Node<T>* aux = head; 
        head = head->next; 
        delete aux; 
        size--;
        return true;
    }

    Node<T>* aux = head; // apuntamos al inicio de la lista
    for (int i = 0; i < index - 1; i++) { // buscamos el nodo anterior
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
    Node<T>* aux = head; // primero apuntamos al inicio de la lista
    int index = 0;
    while (aux != nullptr) {
        if (aux->data == data) return index; // si encontramos el dato, regresamos su indice
        aux = aux->next;
        index++;
    }
    return -1; // si no encontramos el dato, regresamos -1
}

template <typename T>
T& LinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Error! that position is invalid" << endl;
       
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

    // limpiar lista actual
    while (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }
    size = 0;

    // copiar elementos de other
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