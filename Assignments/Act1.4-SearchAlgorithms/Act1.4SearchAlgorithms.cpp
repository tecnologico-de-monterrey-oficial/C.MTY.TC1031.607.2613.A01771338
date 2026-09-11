//Elena María Barrios Jordan
//A01771338
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//caracter secuencial
char buscarUnicoSecuencial(string texto, int &comparaciones) {
    comparaciones = 0;  // Empezamos contando desde cero
    
    for(int i = 0; i < texto.length(); i++) { //vamos recorriendo el text
        bool Unico = true;  // Suponemos que es única
        
        // Comparamos con las demás letras
        for(int j = 0; j < texto.length(); j++) {
            comparaciones = comparaciones + 1;  // Contamos esta comparación

            // otra posición y la letra es igual
            if(i != j && texto[i] == texto[j]) {
                Unico = false;  // No es única
                break;  
            }
        }
        
        // Si después de comparar con todas, sigue siendo única
        if(Unico == true) {
            return texto[i];  
        }
    }

    return 'a';
}

//unicobinario
char buscarUnicoBinario(string texto, int &comparaciones) {
    comparaciones = 0;  // Empezamos contando desde cero
    
    // convertir el texto en una lista de letras
    vector<char> letras;
    for(int i = 0; i < texto.length(); i++) {
        letras.push_back(texto[i]); 
    }
    
    sort(letras.begin(), letras.end());  // ordenar la lista de letras como con los números
    
    for(int i = 0; i < texto.length(); i++) {
        char letraActual = texto[i];  
        int primeraPos = -1;  // aparece por primera vez
        int ultimaPos = -1;   // aparece por última vez
    
        int inicio = 0;
        int fin = letras.size() - 1;
        
        while(inicio <= fin) {
            comparaciones++;
            int medio = (inicio + fin) / 2;
            
            if(letras[medio] >= letraActual) {
                fin = medio - 1; 
                if(letras[medio] == letraActual) {
                    primeraPos = medio;  
                }
            } else {
                inicio = medio + 1; //a la derecha
            }
        }
        
        inicio = 0;
        fin = letras.size() - 1;
        
        while(inicio <= fin) {
            comparaciones++;
            int medio = (inicio + fin) / 2;
            
            if(letras[medio] <= letraActual) {
                inicio = medio + 1; 
                if(letras[medio] == letraActual) {
                    ultimaPos = medio; 
                }
            } else {
                fin = medio - 1;  //izq
            }
        }
        
        // Si aparece solo una vez (primera y última posición son iguales)
        if(primeraPos == ultimaPos && primeraPos != -1) {
            return letraActual; 
        }
    }
    return 'a';
}

int main() {
    int n; 

    cout << "numero de textos que vas a ingresar: ";
    cin >> n;
    cin.ignore();

    vector<string> textos;  // guardar los textos
    
    cout << "Escribe " << n << " textos:" << endl;
    
    // Leemos cada texto
    for(int i = 0; i < n; i++) {
        string temp;  // Variable temporal para almacenar el texto 
        getline(cin, temp);  // Leemos toda la línea 
        textos.push_back(temp);  // Guardamos el texto
    }
    
    for(int i = 0; i < textos.size(); i++) {
        string textoActual = textos[i];  // Tomamos un texto
        int comparacionesSec = 0; 
        int comparacionesBin = 0;  
        //buscar
        char unicoSec = buscarUnicoSecuencial(textoActual, comparacionesSec);
        char unicoBin = buscarUnicoBinario(textoActual, comparacionesBin);
        
        cout << unicoSec << " " << comparacionesSec << " ";
        cout << unicoBin << " " << comparacionesBin << endl;
    }
    
    return 0; 
}
