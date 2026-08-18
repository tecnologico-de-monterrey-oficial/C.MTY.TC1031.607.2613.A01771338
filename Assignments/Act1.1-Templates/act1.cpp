#include <iostream>
using namespace std;

#include "List.h"


// int sum(int a, int b) {
//     return a + b;
// }

// double sum(double a, double b) {
//     return a + b;
// }

// string sum(string a, string b) {
//     return a + b;
// }

template <typename T>
T sum(T a, T b) {
    return a + b;
}

int main() {

    string a= "hola ";
    string b= "crayola";
    cout << "Sum of " << a << " and " << b << " is: " << sum(a, b) << endl;
    int c= 5;
    int d= 10;
    cout << "Sum of " << c << " and " << d << " is: " << sum(c, d) << endl;
    double e= 5.5;
    double f= 10.5;
    cout << "Sum of " << e << " and " << f << " is: " << sum(e, f) << endl;

    // Prueba de la clase List
    List<int> list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    list.print();
    cout << endl;

    //Prueba T get data
    cout << "Dato en la posicion 1: " << list.getData(1) << endl;
    //Prueba T get size
    cout << "Tamaño de la lista: " << list.getSize() << endl;
    //Prueba T get max
    cout << "Maximo de la lista: " << list.getMax() << endl;

    //Prueba T insert at
    cout << "Insertar el 7 en la posicion 1: ";
    list.insertAt(1, 7);
    list.print();

    //Prueba T remove at
    cout << "Remover el elemento en la posicion 2: ";
    list.removeAt(2);
    list.print();
    cout << "El elemento en la posicion 2 fue eliminado " << endl;


    // Prueba de la clase List con strings
    List<string> things;
    things.insert("Laptop");
    things.insert("bottle");
    things.print();

    return 0;
}