#include <iostream>
#include <stdexcept>
#include "DoublyLinkedList.h"
using namespace std;
int main() {
    DoublyLinkedList<int> lista;
    int opcion, dato, indice;

    do {
        cout << "MENU" << endl;
        cout << "1.  Agregar al inicio" << endl;
        cout << "2.  Agregar al final" << endl;
        cout << "3.  Insertar despues de un indice" << endl;
        cout << "4.  Borrar un dato" << endl;
        cout << "5.  Borrar en una posicion" << endl;
        cout << "6.  Obtener dato en una posicion" << endl;
        cout << "7.  Actualizar un dato" << endl;
        cout << "8.  Actualizar en una posicion" << endl;
        cout << "9.  Buscar un dato" << endl;
        cout << "10. Leer con []" << endl;
        cout << "11. Escribir con []" << endl;
        cout << "12. Copiar lista (=)" << endl;
        cout << "13. Limpiar lista" << endl;
        cout << "14. Ordenar lista" << endl;
        cout << "15. Duplicar elementos" << endl;
        cout << "16. Quitar duplicados" << endl;
        cout << "17. Imprimir lista" << endl;
        cout << "0.  Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            cout << "Dato: "; cin >> dato;
            lista.addFirst(dato);
        }
        else if (opcion == 2) {
            cout << "Dato: "; cin >> dato;
            lista.addLast(dato);
        }
        else if (opcion == 3) {
            cout << "Indice: "; 
            cin >> indice;
            cout << "Dato: "; 
            cin >> dato;
            lista.insert(indice, dato);
        }
        else if (opcion == 4) {
            cout << "Dato que quieres borrar: "; 
            cin >> dato;
            lista.deleteData(dato);
        }
        else if (opcion == 5) {
            cout << "Indice: "; 
            cin >> indice;
            lista.deleteAt(indice);
        }
        else if (opcion == 6) {
            cout << "Indice: "; 
            cin >> indice;
            cout << "Dato: " << lista.getData(indice) << endl;
        }
        else if (opcion == 7) {
            int viejo, nuevo;
            cout << "Dato anterior: "; 
            cin >> viejo;
            cout << "Dato nuevo: "; 
            cin >> nuevo;
            lista.updateData(viejo, nuevo);
        }
        else if (opcion == 8) {
            int nuevo;
            cout << "Indice: "; 
            cin >> indice;
            cout << "Dato nuevo: "; 
            cin >> nuevo;
            lista.updateAt(indice, nuevo);
        }
        else if (opcion == 9) {
            cout << "Dato a buscar: "; 
            cin >> dato;
            int pos = lista.findData(dato);
            if (pos == -1) cout << "No encontrado" << endl;
            else cout << "Esta en la posicion: " << pos << endl;
        }
        else if (opcion == 10) {
            cout << "Indice: "; 
            cin >> indice;
            cout << "Dato: " << lista[indice] << endl;
        }
        else if (opcion == 11) {
            int nuevo;
            cout << "Indice: "; 
            cin >> indice;
            cout << "Dato nuevo: "; 
            cin >> nuevo;
            lista[indice] = nuevo;
        }
        else if (opcion == 12) {
            DoublyLinkedList<int> otra;
            int n, x;
            cout << "Cuantos datos tendra la otra lista: "; cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Dato " << i + 1 << ": "; cin >> x;
                otra.addLast(x);
            }
            lista = otra;
        }
        else if (opcion == 13) {
            lista.clear();
        }
        else if (opcion == 14) {
            lista.sort();
            cout << "Lista ya ordenada" << endl;
        }
        else if (opcion == 15) {
            lista.duplicate();
            cout << "Lista duplicada" << endl;
        }
        else if (opcion == 16) {
            lista.removeDuplicates();
            cout << "Listo ya no hay duplicados" << endl;
        }
        else if (opcion == 17) {
            lista.print();
        }
        else if (opcion == 0) {
            cout << "Salida" << endl;
        }
        else {
            cout << "Opcion no valida" << endl;
        }

    } while (opcion != 0);

    return 0;