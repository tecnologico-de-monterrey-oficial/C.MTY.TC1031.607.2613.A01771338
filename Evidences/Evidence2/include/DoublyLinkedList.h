#ifndef DoublyLinkedList_h
#define DoublyLinkedList_h

#include "Node.h"
#include "Log.h"
#include <vector>
#include <iostream>    // para imprimir
using namespace std;

template <typename T>
class DoublyLinkedList {
private:
    NodeD<T>* head;
    NodeD<T>* tail;
    int size;

    // Contadores para Merge Sort
    int comparaciones;
    int profundidadActual;
    int profundidadMaxima;

    // métodos privados del Merge Sort
    NodeD<T>* getMiddle(NodeD<T>* head);
    NodeD<T>* merge(NodeD<T>* a, NodeD<T>* b);
    NodeD<T>* mergeSortRec(NodeD<T>* head);

public:

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0),comparaciones(0), profundidadActual(0), profundidadMaxima(0) {}

    // Destructor agregado por ia   
    ~DoublyLinkedList() {
        clear();
    }

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
    void sort();              // sort viejo con vector
    void mergeSort();         // sort sobre la lista
    void duplicate();
    void removeDuplicates();
    void print();

    T& operator[](int index);
    DoublyLinkedList<T>& operator=(const DoublyLinkedList<T>& other); // Sobrecarga de operadores ia ayuda

    int getSize() { return size; }

    // getters de contadores y head
    int getComparaciones() { return comparaciones; }
    int getProfundidadMaxima() { return profundidadMaxima; }
    NodeD<T>* getHead() { return head; }
    NodeD<T>* getTail() { return tail; }
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
    if (index < 0 || index >= size) {
        cout << "Índice inválido" << endl;
        return;
    }

    if (index == size - 1) {
        addLast(data);
        return;
    }
    if (index == 0) {
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
    if (index < 0 || index >= size) return false;

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
    if (index < 0 || index >= size) {
        cout << "Índice inválido" << endl;
        return T();
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
    cout << "Dato no encontrado" << endl;
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

//sort con vector
template <typename T>
void swapVec(vector<T> &list, int i, int j) {
    T temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}

template <typename T>
int getPivot(vector<T> &list, int left, int right) {
    int aux = left - 1;
    int pivot = right;
    for (int i = left; i < pivot; i++) {
        if (list[pivot] > list[i]) {
            aux++;
            swapVec(list, aux, i);
        }
    }
    aux++;
    swapVec(list, aux, pivot);
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

// Decidí usar Quick Sort pero para hacerlo más fácil, primero convertí la DoublyList a un vector, luego lo ordené como ya sabíamos y lo convertí otra vez a una DoublyList.
// NOTA: Este sort queda solo para pruebas pequeñas. Para la Parte B (logs) se usa mergeSort().
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

//Operator ayuda ia
template <typename T>
T& DoublyLinkedList<T>::operator[](int index) {
    static T dummy = T();
    if (index < 0 || index >= size) {
        cout << "Índice inválido" << endl;
        return dummy;
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


//Merge sort doubly linked list
// Regresa el nodo del medio de la lista (de head a nullptr)
template <typename T>
NodeD<T>* DoublyLinkedList<T>::getMiddle(NodeD<T>* head) {
    NodeD<T>* slow = head;
    NodeD<T>* fast = head->next;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// Mezcla dos listas ordenadas en una sola
template <typename T>
NodeD<T>* DoublyLinkedList<T>::merge(NodeD<T>* a, NodeD<T>* b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

    comparaciones++;
    NodeD<T>* result = nullptr;

    if (!(b->data < a->data)) {   //ayuda de la ia
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    if (result->next != nullptr) {
        result->next->prev = result;
    }
    return result;
}

// Recursión del Merge Sort
template <typename T>
NodeD<T>* DoublyLinkedList<T>::mergeSortRec(NodeD<T>* head) {
    if (head == nullptr || head->next == nullptr) return head;

    profundidadActual++;
    if (profundidadActual > profundidadMaxima) {
        profundidadMaxima = profundidadActual;
    }

    // Encontrar el medio y cortar la lista
    NodeD<T>* mid = getMiddle(head);
    NodeD<T>* right = mid->next;
    mid->next = nullptr;
    if (right != nullptr) right->prev = nullptr;

    // Ordenar cada mitad
    NodeD<T>* left = mergeSortRec(head);
    NodeD<T>* rightSorted = mergeSortRec(right);

    // Mezclar
    NodeD<T>* result = merge(left, rightSorted);

    profundidadActual--;
    return result;
}


template <typename T>
void DoublyLinkedList<T>::mergeSort() {
    if (size < 2) return;

    comparaciones = 0;
    profundidadActual = 0;
    profundidadMaxima = 0;

    head = mergeSortRec(head);

    // Actualizar tail
    tail = head;
    while (tail != nullptr && tail->next != nullptr) {
        tail = tail->next;
    }

    // Asegurar que head->prev y tail->next sean nullptr
    if (head != nullptr) head->prev = nullptr;
    if (tail != nullptr) tail->next = nullptr;
}

#endif /* DoublyLinkedList_h */