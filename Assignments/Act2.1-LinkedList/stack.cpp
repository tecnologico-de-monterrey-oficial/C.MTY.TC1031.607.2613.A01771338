#include "Node.h"
using namespace std;
#include <iostream>

template <typename T>
class Stack {
private: 
    Node<T>* head;
    int size;

public:
    Stack() {
        head = nullptr;
        size = 0;
    }
    
    void pop();
    void push(T data);
    T getTop();
    void print();
    bool empty();
    int getSize();
};

template <typename T>
void Stack<T>::pop() {
    if (head != nullptr) {
        Node<T>* aux = head;
        head = head->next;
        delete aux;
    }
}

template <typename T>
void Stack<T>::push(T data) {
    Node<T>* nuevo = new Node<T>(data);
    nuevo->next = head;
    head = nuevo;
}

template <typename T>
T Stack<T>::getTop() {
    if (head != nullptr) {
        return head->data;
    }
    return T();
}

template <typename T>
void Stack<T>::print() {
    Node<T>* aux = head;
    while (aux != nullptr) {
        cout << aux->data << " ";
        aux = aux->next;
    }
    cout << endl;
}

template <typename T>
bool Stack<T>::empty() {
    return head == nullptr;
}

template <typename T>
int Stack<T>::getSize() {
    return size;
}

struct PaginaWeb {
    string tittle;
    string url;
};


int main() {
    Stack<PaginaWeb> historial;
    int opcion;

    do {
        cout << "Historial" << endl;
        cout << "1. Visitar una nueva pagina" << endl;
        cout << "2. Retroceder a la pagina anterior" << endl;
        cout << "3. Ver la pagina actual" << endl;
        cout << "4. Mostrar cuantas paginas hay en el historial" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            PaginaWeb p;
            cout << "Titulo: ";
            cin >> p.tittle;
            cout << "URL: ";
            cin >> p.url;
            historial.push(p);
            cout << "Pagina visitada" << endl;
        }
        else if (opcion == 2) {
            if (historial.empty()) {
                cout << "No hay paginas en el historial" << endl;
            } else {
                PaginaWeb p = historial.getTop();
                historial.pop();
                cout << "Cerrando: " << p.tittle << endl;
                cout << "URL: " << p.url << endl;
            }
        }
        else if (opcion == 3) {
            if (historial.empty()) {
                cout << "No hay paginas" << endl;
            } else {
                PaginaWeb p = historial.getTop();
                cout << "Pagina actual: " << p.tittle << endl;
                cout << "URL: " << p.url << endl;
            }
        }
        else if (opcion == 4) {
            if (historial.empty()) {
                cout << "El historial esta vacio" << endl;
            } else {
                cout << "Paginas en el historial: " << historial.getSize() << endl;
            }
        }
        else if (opcion == 5) {
            cout << "Salida" << endl;
        }
        else {
            cout << "Error elije otra opcion: " << endl;
        }

    } while (opcion != 5);

    return 0;
}