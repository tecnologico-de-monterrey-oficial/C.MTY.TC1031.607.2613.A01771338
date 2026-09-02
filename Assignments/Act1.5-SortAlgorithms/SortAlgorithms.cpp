//Elena MAría Barrios Jordan
//A01771338

#include <iostream>
#include <vector> 
using namespace std;



// Selection Sort
template <typename T> //siempre tener


void selectionSort(vector<T> &list) {
    // iteramos toda la lista desde el principio hasta uno antes del final
    for (int i=0; i<list.size()-1; i++) {
        // hacemos el indice de la posición i como el más chico
        int min = i;
        // iteramos desde el siguiente índice hasta el final
        for (int j=i+1; j<list.size(); j++) {
            // comparamos el valor de j contra min
            if (list[j] < list[min]) {
                // si es menor
                // Actualizamos el valor de min
                min = j;
            }
        }
        // intercambiamos el valor de min por el valor de i
        swap(list, min, i);
    }
}

//insertion sort 
template <typename T>
void insertionSort(vector<T> &list) {
    
}



