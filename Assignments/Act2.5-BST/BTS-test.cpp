//Elena MAría Barrios Jordan
//A01771338
#include <iostream>
using namespace std;

#include "BST.h"

int main() {

    BST<int> bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(40);
    bst.insert(20);
    bst.insert(80);
    bst.print();
    if (bst.find(40)) {
        cout << "si se encuentra el nodo" << endl;
    } else {
        cout << "no se encuentra el nodo" << endl;
    }


    return 0;
}
