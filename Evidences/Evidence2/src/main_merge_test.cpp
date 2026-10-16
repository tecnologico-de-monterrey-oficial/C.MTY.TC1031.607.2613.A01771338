#include <iostream>
#include "../include/DoublyLinkedList.h"
using namespace std;

int main() {
    DoublyLinkedList<int> lista;


    lista.addLast(5);
    lista.addLast(2);
    lista.addLast(8);
    lista.addLast(1);
    lista.addLast(9);
    lista.addLast(3);
    lista.addLast(7);
    lista.addLast(4);
    lista.addLast(6);
    lista.addLast(0);

    cout << "Lista original:" << endl;
    lista.print();

    lista.mergeSort();

    lista.print();

    cout << "Comparaciones: " << lista.getComparaciones() << endl;
    cout << "Profundidad maxima: " << lista.getProfundidadMaxima() << endl;

    return 0;
}