#ifndef LinkedList_h
#define LinkedList_h
#include "Node.h"

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

    // Caso especial: Si la lista está vacía, el primero es también el último
    if (head == nullptr) {
        head = node;
    } 
    // Caso normal: Si la lista ya tiene elementos, hay que buscar el final
    else {
        // Creamos un apuntador auxiliar para buscar el último nodo
        Node<T>* aux = head;
        
        // Caminamos por la lista hasta encontrar el nodo cuya flecha 'next' apunte a nullptr
        while (aux->next != nullptr) {
            aux = aux->next;
        }
        
        // Cuando lo encontramos, hacemos que ese último nodo apunte a nuestro nodo nuevo
        aux->next = node;
    }
    
    // Incrementamos el tamaño de la lista
    size++;
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