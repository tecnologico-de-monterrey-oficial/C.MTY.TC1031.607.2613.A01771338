//Elena MAría Barrios Jordan
//A01771338
#include <iostream>
using namespace std;


class Fraction {
public:
    Fraction(int num, int den) : numerator(num), denominator(den) {}
    void print() const {
        cout << numerator << "/" << denominator << endl;
    }
private:
    int numerator;
    int denominator;
};

int ApuntadoresNormales() {
    int x = 42;
    int* p = &x;

    cout << x << endl; // Valor de x en este caso es 42
    cout << &x << endl; // '&x' hace referencia a la dirección de memoria de x
    cout << *p << endl; // el * hace que p nos dé el valor que guarda p o sea x
    cout << p << endl; // Guarda la dirección de x
    delete p;
    p = nullptr; // Evitamos que p apunte a una dirección de memoria inválida y ahora p es un puntero nulo hasta esperar otra asignación para p


    int* q = new int(5); // Asignación dinámica de memoria y mete ahí el valor 5
    cout << *q << endl; // el * hace que q nos dé el valor que guarda q
    delete q; // Liberamos ese espacio de memoria y queda disponible para futuros usos, no borra la info solo que el espacio queda disponible


    Fraction* f = new Fraction(1, 2); // Al inicio del renglon ponemos Fraction que es el tipo de dato, despues el apuntador f y luego usamos new para asignar memoria dinamica y crear un objeto de tipo Fraction con los valores 1 y 2, entonces lo que se va a guardar en f es la dirección de memoria donde se encuentra ese objeto.
    f->print(); // Usamos el operador -> para acceder los métodos de la clase Fraction y entonces imprimir la fracción que es guardada en f.



    //Smart pointer: nos sirven más que el pointer normal porque manejan la memoria automáticamente y evitan fugas de memoria.

    //unique_ptr : es un puntero inteligente que posee un único objeto y se encarga de liberarlo cuando ya no se necesita.
    unique_ptr<Fraction> h = make_unique<Fraction>(5, 6);
    h->print();



    return 0;
}