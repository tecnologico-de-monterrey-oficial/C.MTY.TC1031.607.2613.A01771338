#include <iostream>
using namespace std;
#include "LinkedList.h"

void probarInt() {
    LinkedList<int> lista;

    cout << "=== PRUEBAS INT ===" << endl;

    cout << "\n1. push_back(10), push_back(20), push_back(30)" << endl;
    lista.push_back(10);
    lista.push_back(20);
    lista.push_back(30);
    lista.print();

    cout << "\n2. push_front(5)" << endl;
    lista.push_front(5);
    lista.print();

    cout << "\n3. insert(2, 15)" << endl;
    lista.insert(2, 15);
    lista.print();

    cout << "\n4. deleteData(15)" << endl;
    bool r1 = lista.deleteData(15);
    lista.print();

    cout << "\n5. deleteAt(0)" << endl;
    bool r2 = lista.deleteAt(0);
    lista.print();

    cout << "\n6. getData(1)" << endl;
    cout << "Dato: " << lista.getData(1) << endl;

    cout << "\n7. updateData(20, 99)" << endl;
    lista.updateData(20, 99);
    lista.print();

    cout << "\n8. updateAt(0, 77)" << endl;
    lista.updateAt(0, 77);
    lista.print();

    cout << "\n9. findData(30)" << endl;
    cout << "Posicion: " << lista.findData(30) << endl;

    cout << "\n10. Leer con [] : lista[1]" << endl;
    cout << "Dato: " << lista[1] << endl;

    cout << "\n11. Escribir con [] : lista[1] = 55" << endl;
    lista[1] = 55;
    lista.print();

    cout << "\n12. Igualar lista con otra" << endl;
    LinkedList<int> otra;
    otra.push_back(100);
    otra.push_back(200);
    otra.push_back(300);
    lista = otra;
    lista.print();

    cout << "\n13. Imprimir lista final" << endl;
    lista.print();
}

void probarString() {
    LinkedList<string> lista;

    cout << "\n=== PRUEBAS STRING ===" << endl;

    cout << "\n1. push_back(hola), push_back(mundo), push_back(c++)" << endl;
    lista.push_back("holiiii");
    lista.push_back("mundoooo");
    lista.push_back("ok prueba");
    lista.print();

    cout << "\n2. push_front(inicio)" << endl;
    lista.push_front("inicio");
    lista.print();

    cout << "\n3. insert(2, medio)" << endl;
    lista.insert(2, "medio");
    lista.print();

    cout << "\n4. deleteData(medio)" << endl;
    bool r1 = lista.deleteData("medio");
    lista.print();

    cout << "\n5. deleteAt(0)" << endl;
    bool r2 = lista.deleteAt(0);
    lista.print();

    cout << "\n6. getData(1)" << endl;
    cout << "Dato: " << lista.getData(1) << endl;

    cout << "\n7. updateData(mundo, tierra)" << endl;
    lista.updateData("mundo", "tierra");
    lista.print();

    cout << "\n8. updateAt(0, primero)" << endl;
    lista.updateAt(0, "primero");
    lista.print();

    cout << "\n9. findData(c++)" << endl;
    cout << "Posicion: " << lista.findData("c++") << endl;

    cout << "\n10. Leer con [] : lista[1]" << endl;
    cout << "Dato: " << lista[1] << endl;

    cout << "\n11. Escribir con [] : lista[1] = nuevo" << endl;
    lista[1] = "nuevo";
    lista.print();

    cout << "\n12. Igualar lista con otra" << endl;
    LinkedList<string> otra;
    otra.push_back("uno");
    otra.push_back("dos");
    otra.push_back("tres");
    lista = otra;
    lista.print();

    cout << "\n13. Imprimir lista final" << endl;
    lista.print();
}

int main() {
    probarInt();
    probarString();
    return 0;
}