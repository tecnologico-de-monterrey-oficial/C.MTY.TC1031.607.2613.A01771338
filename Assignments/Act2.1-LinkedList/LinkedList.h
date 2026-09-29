#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"
using namespace std;
#include <iostream>

template <typename T>
class LinkedList {
private: 
    Node<T>* head; // Apunta al primer nodo de la lista
    int size;
public:
    LinkedList() : head(nullptr), size(0) {} // Constructor: Al principio la lista está vacía
    void push_front(T data);
    void push_back(T data);
    void print();
};

template <typename T>
void LinkedList<T>::push_front(T data) {
    // crear un nodo nuevo
    Node<T>* node = new Node<T>(data);
    // actualizo el next del nodo nuevo para que apunte a head
    node->next = head;
    // actualizo head
    head = node;
}

template <typename T>
void LinkedList<T>::push_back(T data) {
    Node<T>* node = new Node<T>(data);  // Crear el nodo nuevo que queremos meter al final

    if (head == nullptr) { //lista vacía
        head = node;
    } 
    else { // la lista ya tiene elementos, hay que buscar el final
        
        Node<T>* aux = head;
        
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        aux->next = node;
    }
    size++;
}

template<typename T>
void LinkedList<T>::insert(int index, T data){
    //Checamos que la posición exisyta
    if (index >= 0 && index < size){
        int auxIndex = 0;
        aux = aux->node
    }

}

template<typename T>
void LinkedList<T> :: deleteData(T data){
    if (head != nullptr) //lista no vacía

        if (head->data==data){ //quiero borrar el primer elemento
            head = head->next; 

            delete aux; //borramos el primer elemento
        } else{
            Node<T>auxPrev

            Node<T>* aux = head->next
        }
}





template <typename T>
void LinkedList<T>::print() {
    // creamos un apuntador auxiliar que apunte a head
    Node<T>* aux = head;
    // recorremos la lista mientras aux sea diferente de nullptr
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) {
            cout << "-";
        }
    }
    cout << endl;
}

#endif 