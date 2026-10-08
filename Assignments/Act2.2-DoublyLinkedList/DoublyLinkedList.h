// Elena María Barrios Jordan
// A01771338
#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h
#include "Node.h"
#include <iostream>    // para imprimir
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void addFirst(T data);
    void addLast(T data);
    void insert(int index, T data);
    bool deleteData(T data);
    bool deleteAt(int index);
    T getData(int index);
    void updateData(T oldData, T newData);
    void updateAt(int index, T newData);
    int findData(T data);

    
    void clear();
    void sort();
    void duplicate();
    void removeDuplicates();
    void print();

    
    T& operator[](int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other); // Sobrecarga de operadores

    int getSize() { return size; }
};

template <typename T>
void DoublyLinkedList<T>::addFirst(T data) {
    NodeD<T>* nuevo = new NodeD<T>(data);
    if (head == nullptr) { // Si la lista está vacía
        head = nuevo;
        tail = nuevo;
    } else {
        nuevo->next = head; // apunta al antiguo primer nodo
        head->prev = nuevo; // el antiguo primer nodo apunta al nuevo
        head = nuevo; 
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::addLast(T data) {
    NodeD<T>* nuevo = new NodeD<T>(data);
    if (head == nullptr) {
        head = nuevo;
        tail = nuevo;
    } else {
        nuevo->prev = tail;
        tail->next = nuevo;
        tail = nuevo;
    }
    size++;
}

template <typename T>
void DoublyLinkedList<T>::insert(int index, T data) {
    if (index < 0 && index >= size) {
        cout << "Índice inválido";
    }

    if (index == size - 1) { 
        addLast(data);
        return;
    }
    if(index == 0) {
        addFirst(data);
        return;
    }

    NodeD<T>* aux = head; // Buscamos el nodo en la posición index
    for (int i = 0; i < index; i++) {
        aux = aux->next; 
    }
    NodeD<T>* nuevo = new NodeD<T>(data);
    nuevo->prev = aux;
    nuevo->next = aux->next;
    aux->next->prev = nuevo;
    aux->next = nuevo;
    size++;
}

template <typename T>
bool DoublyLinkedList<T>::deleteData(T data) {
    int pos = findData(data);
    if (pos == -1) return false;
    return deleteAt(pos);
}

template <typename T>
bool DoublyLinkedList<T>::deleteAt(int index) {
    if (index < 0 && index >= size) return false;

    if (size == 1) {
        delete head;
        head = nullptr;
        tail = nullptr;
        size--;
        return true;
    }
    if (index == 0) {
        NodeD<T>* aux = head;
        head = head->next;
        head->prev = nullptr;
        delete aux;
        size--;
        return true;
    }

    if (index == size - 1) {
        NodeD<T>* aux = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete aux;
        size--;
        return true;
    }

    NodeD<T>* aux = head; //hacemos que el nodo aux apunte al primer nodo para buscar el índice
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->prev->next = aux->next; // Conectamos el anterior con el siguiente
    aux->next->prev = aux->prev; // Conectamos el siguiente con el anterior
    delete aux;
    size--;
    return true;
}

template <typename T>
T DoublyLinkedList<T>::getData(int index) {
    if (index < 0 && index >= size) {
        cout<< "Índice inválido"<<endl;
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next; // Avanzamos al siguiente nodo
    }
    return aux->data;
}

template <typename T>
void DoublyLinkedList<T>::updateData(T oldData, T newData) { // Busca el primer elemento igual a oldData y lo cambia por newData
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        if (aux->data == oldData) {
            aux->data = newData;
            return;
        }
        aux = aux->next;
    }
    cout <<"Dato no encontrado"<<endl;
}

template <typename T>
void DoublyLinkedList<T>::updateAt(int index, T newData) {
    if (index < 0 || index >= size) {
        cout << "Índice inválido" << endl;
        return;
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    aux->data = newData;
}

template <typename T>
int DoublyLinkedList<T>::findData(T data) {
    NodeD<T>* aux = head;
    int pos = 0;
    while (aux != nullptr) {
        if (aux->data == data) return pos;
        aux = aux->next;
        pos++;
    }
    return -1;
}

template <typename T>
void DoublyLinkedList<T>::clear() {
    while (head != nullptr) {
        NodeD<T>* aux = head;
        head = head->next;
        delete aux;
    }
    tail = nullptr;
    size = 0;
}


template <typename T>
void swap(vector<T> &list, int i, int j) {
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
//------------------------------------------------------------------
// Decidí usar Quick Sort pero para hacerlo más fácil, primero convertí la DoublyList a un vector, luego lo ordené como ya sabíamos y lo convertí otra vez a una DoublyList.
template <typename T>
int getPivot(vector<T> &list, int left, int right) {
    int aux = left - 1;
    int pivot = right;
    for (int i = left; i < pivot; i++) {
        if (list[pivot] > list[i]) {
            aux++;
            swap(list, aux, i);
        }
    }
    aux++;
    swap(list, aux, pivot);
    return aux;
}

template <typename T>
void quickSort(vector<T> &list, int left, int right) {
    if (left < right) {
        int pivot = getPivot(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

template <typename T>
void DoublyLinkedList<T>::sort() {
    if (size < 2) return;  

    // 1. Copiamos los datos de la lista a un vector
    vector<T> datos;
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        datos.push_back(aux->data);
        aux = aux->next;
    }

    // 2. Ordenamos el vector con quickSort
    quickSort(datos, 0, datos.size() - 1);

    // 3. Regresamos los datos ordenados a la lista
    aux = head;
    int i = 0;
    while (aux != nullptr) {
        aux->data = datos[i];
        aux = aux->next;
        i++;
    }
}



//-------------------------------------------------------------------------------------

template <typename T>
void DoublyLinkedList<T>::duplicate() {
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        NodeD<T>* nuevo = new NodeD<T>(aux->data);
        nuevo->next = aux->next;
        nuevo->prev = aux;
        if (aux->next != nullptr) {
            aux->next->prev = nuevo;
        } else {
            tail = nuevo;
        }
        aux->next = nuevo;
        aux = nuevo->next;
        size++;
    }
}

template <typename T>
void DoublyLinkedList<T>::removeDuplicates() {
    if (size < 2) return;
    sort();
    NodeD<T>* aux = head;
    while (aux != nullptr && aux->next != nullptr) {
        if (aux->data == aux->next->data) {
            NodeD<T>* repetido = aux->next;
            aux->next = repetido->next;
            if (repetido->next != nullptr) {
                repetido->next->prev = aux;
            } else {
                tail = aux;
            }
            delete repetido;
            size--;
        } else {
            aux = aux->next;
        }
    }
}

template <typename T>
void DoublyLinkedList<T>::print() {
    NodeD<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data;
        aux = aux->next;
        if (aux != nullptr) cout << "-";
    }
    cout << endl;
}
//------------------------------------------------------------------------------------------------------------------------



template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        cout << "Índice inválido" << endl;
        return nullptr;
    }
    NodeD<T>* aux = head;
    for (int i = 0; i < index; i++) {
        aux = aux->next;
    }
    return aux->data;
}


template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList<T>& other) {
    if (this == &other) return *this;  // evitar auto-asignación
    clear();
    NodeD<T>* aux = other.head;
    while (aux != nullptr) {
        addLast(aux->data);
        aux = aux->next;
    }
    return *this;
}

#endif /* DoublyLinkedList_h */