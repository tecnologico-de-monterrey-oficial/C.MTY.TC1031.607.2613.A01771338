//Elena María Barrios Jordan
//A01771338

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to sum odd numbers
int sumarImparesRecursivo(vector<int> vec, int posicion) {
    // caso base
    if (posicion == vec.size()) {
        return 0;  
    }
    
    int sumaActual = 0;
    if (vec[posicion] % 2 != 0) {  
        sumaActual = vec[posicion];  
    }
    
    int sumaRestante = sumarImparesRecursivo(vec, posicion + 1);

    return sumaActual + sumaRestante;
}

int main() {
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 
    int resultado = sumarImparesRecursivo(numeros, 0);

    // Muestra el resultado
    cout << "La suma de los números es: " << resultado << endl;

    return 0;
}