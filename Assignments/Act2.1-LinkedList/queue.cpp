//Elena María Barrios Jordan
//A01771338

#include <iostream>
#include <string>
using namespace std;

#include "Node.h"

struct Cliente {
    string nombre;
    int boletos;
};

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

    void pop() {
        if (head != nullptr) {
            if (head == tail) {
                Node<T>* aux = head;
                delete aux;
                head = nullptr;
                tail = nullptr;
            } else {
                Node<T>* aux = head;
                head = head->next;
                delete aux;
            }
            size--;
        }
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


int main() {
    Queue<Cliente> fila;
    int opcion;

    do {
        cout << " FILA DE CLIENTES" << endl;
        cout << "1. Llegada de un nuevo cliente" << endl;
        cout << "2. Atender al siguiente cliente" << endl;
        cout << "3. Ver al siguiente cliente" << endl;
        cout << "4. Mostrar cuantas personas hay en la fila" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Cliente c;
            cout << "Nombre: ";
            cin >> c.nombre;
            cout << "Boletos: ";
            cin >> c.boletos;
            fila.push(c);
            cout << "Cliente fue bien agregado a la fila" << endl;
        }
        else if (opcion == 2) {
            if (fila.empty()) {
                cout << "No hay nadie en la fila" << endl;
            } else {
                Cliente c = fila.front();
                fila.pop();
                cout << "Atendiendo a: " << c.nombre << endl;
                cout << "Boletos: " << c.boletos << endl;
            }
        }
        else if (opcion == 3) {
            if (fila.empty()) {
                cout << "No hay nadie más en la fila" << endl;
            } else {
                Cliente c = fila.front();
                cout << "Siguiente cliente: " << c.nombre << endl;
                cout << "Boletos: " << c.boletos << endl;
            }
        }
        else if (opcion == 4) {
            cout << "Personas que hay en la fila: " << fila.getSize() << endl;
        }
        else if (opcion == 5) {
            cout << "Saliendo" << endl;
        }
        else {
            cout << "Opcion Erronea" << endl;
        }

    } while (opcion != 5);

    return 0;
}