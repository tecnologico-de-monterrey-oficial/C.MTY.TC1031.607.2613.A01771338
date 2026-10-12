#include <iostream>
#include "../include/LinkedList.h"
#include "../include/Stack.h"
#include "../include/Queue.h"
using namespace std;

void probarLinkedList() {
    cout << "PRUEBAS DE LINKEDLIST " << endl;

    LinkedList<int> lista;

    // Caso 1: lista vacía
    cout << "Lista vacía" << endl;
    cout << "Tamaño: " << lista.getSize() << endl;
    cout << "Buscar 5: " << lista.findData(5) << "no encontrado" << endl;
    cout << "Borrar en posicion 0: " << (lista.deleteAt(0) ? "si" : "no") << endl;
    cout << "Borrar dato 5: " << (lista.deleteData(5) ? "si" : "no") << endl;

    // Caso 2: un solo elemento
    cout << "Un solo elemento " << endl;
    lista.push_back(10);
    lista.print();
    cout << "Tamaño: " << lista.getSize() << endl;
    cout << "Buscar 10: " << lista.findData(10) << endl;
    cout << "Buscar 99: " << lista.findData(99) << endl;

    // Caso 3: insertar al inicio y al final
    cout << "Insertar en los extremos " << endl;
    lista.push_front(5);
    lista.push_back(15);
    lista.push_front(1);
    lista.push_back(20);
    cout << "Lista: ";
    lista.print();
    cout << "Tamaño: " << lista.getSize() << endl;

    // Caso 4: borrar en los extremos
    cout << "Borrar en los extremos" << endl;
    lista.deleteAt(0);
    lista.print();
    lista.deleteData(20);
    lista.print();

    // Caso 5: accesar haciendo uso del índice
    cout << "Acceso por índice" << endl;
    cout << "Elemento en posición 0: " << lista[0] << endl;
    cout << "Elemento en posición 1: " << lista[1] << endl;
}

void probarStack() {
    cout << "PRUEBAS DE STACK" << endl;

    Stack<int> pila;

    // Caso 1: pila vacía
    cout << "Pila vacia " << endl;
    cout << "Esta vacia? " << (pila.empty() ? "si" : "no") << endl;
    cout << "Tamaño: " << pila.getSize() << endl;
    cout << "Pop sobre vacia: ";
    pila.pop(); 
    cout << "Top: " << pila.getTop() << " (0 = vacia)" << endl;

    // Caso 2: Un solo elemento
    cout << "Un solo elemento " << endl;
    pila.push(10);
    cout << "Tamaño: " << pila.getSize() << endl;
    cout << "Top: " << pila.getTop() << endl;
    cout << "Esta vacia? " << (pila.empty() ? "si" : "no") << endl;

    // Caso 3: varios elementos en LIFO
    cout << "Varios elementos en LIFO " << endl;
    pila.push(20);
    pila.push(30);
    pila.push(40);
    cout << "Pila actual: ";
    pila.print();
    cout << "Top: " << pila.getTop() << endl;
    cout << "Tamano: " << pila.getSize() << endl;

    // Caso 4: pop en orden LIFO
    cout << "Pop en orden LIFO " << endl;
    while (!pila.empty()) {
        cout << "Pop: " << pila.getTop() << endl;       
        pila.pop();
    }
    cout << "Tamano final: " << pila.getSize() << endl;

    cout << " Fin Stack " << endl;
}

void probarQueue() {
    cout << "PRUEBAS DE QUEUE " << endl;

    Queue<int> fila;

    // Caso 1: fila vacía
    cout << " Fila vacia " << endl;
    cout << "Esta vacia? " << (fila.empty() ? "si" : "no") << endl;
    cout << "Tamaño: " << fila.getSize() << endl;
    cout << "Dequeue sobre vacia: ";
    fila.pop();  
    cout << "Front: " << fila.front() <<endl;

    // Caso 2: un solo elemento
    cout << "Un solo elemento " << endl;
    fila.push(10);
    cout << "Tamaño: " << fila.getSize() << endl;
    cout << "Front: " << fila.front() << endl;
    cout << "Esta vacia? " << (fila.empty() ? "si" : "no") << endl;

    // Caso 3: varios elementos (FIFO)
    cout << "Varios elementos en FIFO " << endl;
    fila.push(20);
    fila.push(30);
    fila.push(40);
    cout << "Fila actual: ";
    fila.print();
    cout << "Front: " << fila.front() << endl;
    cout << "Tamaño: " << fila.getSize() << endl;

    // Caso 4: dequeue en orden FIFO
    cout << "Dequeue en orden FIFO " << endl;
    while (!fila.empty()) {
        cout << "Dequeue: " << fila.front() << endl;
        fila.pop();
    }
    cout << "Tamaño final: " << fila.getSize() << endl;

    cout << " Fin Queue " << endl;
}

int main() {
    cout << "Pruebas para la Parte A (Linked List, Stack, Queue)" << endl;
    probarLinkedList();
    probarStack();
    probarQueue();
    return 0;
}