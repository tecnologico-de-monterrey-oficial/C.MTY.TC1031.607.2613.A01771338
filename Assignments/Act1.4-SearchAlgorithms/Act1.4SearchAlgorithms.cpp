#include <iostream> 
#include <vector> 
#include <algorithm> 
#include <ctime> // medir el tiempo
#include <cstdlib> // Para generar números aleatorios
using namespace std;

bool buscarSecuencial(vector<int> lista, int numero) {
    for(int i = 0; i < lista.size(); i++) {
        if(lista[i] == numero) {
            return true; 
        }
    }
    return false;  
}

bool buscarBinaria(vector<int> lista, int numero) {
    int inicio = 0;
    int fin = lista.size() - 1; // el final de la lista
    while(inicio <= fin) { //mientras aun no se acabe 
        int medio = (inicio + fin) / 2; //con esto calculamos la mitad

        // Si el medio es el que buscamos
        if(lista[medio] == numero) {
            return true;  
        }
        // Si el medio es más pequeño que el que buscamos
        else if(lista[medio] < numero) {
            inicio = medio + 1;  // nos vamos a la derecha
        }
        // Si el medio es más grande que el que buscamos
        else {
            fin = medio - 1;  // nos vamos a la izquierda
        }
    }
    return false;  
}

int main() {
    srand(time(0));  // sirve para que los números sean diferentes cada vez
    vector<int> numeros;  // Creamos una lista vacía para que se puedan guardar los números

    for(int i = 0; i < 1000; i++) {
        int aleatorio = rand() % 1000 + 1; // creamos un número entre 1 y 1,000
        numeros.push_back(aleatorio);  // Lo agregamos a la lista
    }
    
    sort(numeros.begin(), numeros.end());  // Ordenamos la lista de menor a mayor

    int buscar;  // variable para guardar lo que escriba el usuario para buscarlo
    do {
        cout << "\nDame un número o pon 0 para salir: ";
        cin >> buscar;  
        if(buscar == 0) {
            cout << "Saliste" << endl;
            break; 
        }
        //buscarSecuencial
        clock_t inicioSec = clock();  // se inicia el cronómetro
        bool encontradoSec = buscarSecuencial(numeros, buscar); 
        clock_t finSec = clock();  // Detenemos el cronómetro
        double tiempoSec = double(finSec - inicioSec) / CLOCKS_PER_SEC; // calcula el tiempo

        //buscarBinaria
        clock_t inicioBin = clock();  // se inicia el cronómetro
        bool encontradoBin = buscarBinaria(numeros, buscar);  
        clock_t finBin = clock();  // Detenemos el cronómetro
        double tiempoBin = double(finBin - inicioBin) / CLOCKS_PER_SEC; // calcula el tiempo
        
        // resultados
        cout << "Búsqueda secuencial: ";
        if(encontradoSec == true) {
            cout << "Si está el número";
        } else {
            cout << "No está el número";
        }
        cout << " tiempo: " << tiempoSec << " seg" << endl;

        cout << "Búsqueda binaria: ";
        if(encontradoBin == true) {
            cout << "Si está el número";
        } else {
            cout << "No está el número";
        }
        cout << " tiempo: " << tiempoBin << " seg" << endl;

    } while(true);  
    
    return 0; 
}