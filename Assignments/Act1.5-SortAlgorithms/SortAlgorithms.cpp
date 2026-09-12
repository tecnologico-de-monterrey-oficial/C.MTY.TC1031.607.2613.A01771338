//Elena MAría Barrios Jordan
//A01771338

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;



int comparaciones = 0;
int intercambios = 0;

//nuevo algoritmo para ordenar 
template <typename T>
void shellSort(vector<T> &list) {
    int size = list.size(); // Obtenemos el tamaño de la lista
    for (int gap = size/2; gap > 0; gap = gap/2) { // para cada intervalo hasta que gap < 1
        for (int i = gap; i < size; i++) {
            T temp = list[i]; // Guardamos el valor actual
            int j = i; // Inicializamos j con el valor de i
            while (j >= gap && list[j-gap] > temp) { // Comparamos el valor actual con el de la posición anterior
                list[j] = list[j-gap]; // Desplazamos el elemento hacia la derecha
                j = j - gap; // Actualizamos j
            }
            list[j] = temp; // Colocamos el valor actual en la posición correcta
        }
    }
}

template <typename T>
void swap(vector<T> &list, int i, int j) {
    comparaciones++; 
    if (i != j) {
        // creamos una variable temporal
        T aux = list[i];
        // cambiamos i por j
        list[i] = list[j];
        // cambiamos j por aux
        list[j] = aux;
    }
}

template <typename T>
void swapSort(vector<T> &list) {
    for (int i=0; i < list.size()-1; i++) {
        for (int j=i+1; j<list.size(); j++) {

            comparaciones++;
            if (list[j] < list[i]) {

                intercambios++;
                swap(list, i, j);
            }
        }
    }
}

template <typename T>
void bubbleSort(vector<T> &list) {

    bool change = true;  // definimos un booleano como verdadero
    
    for (int i=list.size()-1; i>0 && change; i--) { // iterar desde n hasta 1

        change = false; // cambio el valor de change a falso para que no se salga del ciclo
    
        for (int j=0; j<i; j++) {
    

            comparaciones++;
            if (list[j] > list[j+1]) {
                change = true; // si es mayor cambiamos change a verdadero


                intercambios++;
                swap(list, j, j+1);
            }
        }
    }
}

template <typename T>
void selectionSort(vector<T> &list) {
   
    for (int i=0; i<list.size()-1; i++) {
        
        int min = i;// hacemos el indice de la posición i como el más chico
        
        for (int j=i+1; j<list.size(); j++) { // iteramos desde el siguiente índice hasta el final
           


            comparaciones++;
            if (list[j] < list[min]) {  // comparamos el valor de j contra min
                
                min = j; // si es menor Actualizamos el valor de min
            }
        }
        intercambios++;
        swap(list, min, i); // intercambiamos el valor de min por el valor de i y hasta ahora acabamos un ciclo del gran for.
    }
}


template <typename T>
void insertionSort(vector<T> &list) {
    
    for (int i=1; i<list.size(); i++) {
        // iteramos desde i hasta 0
        bool exit = false;
        for (int j=i; j>0 && !exit; j--) {

            comparaciones++;
            if (list[j] < list[j-1]) {


                intercambios++;
               swap(list, j, j-1); 
            } else {
                exit = true;
            }
        }

    }
}

template <typename T>
int getPivot(vector<T> &list, int left, int right) {

    int aux = left - 1;     // creamos una variable auxiliar con el valor de left - 1 para que vaya al siguiente elemento

    int pivot = right;  // creamos una variable pivot con el valor de right para usarla como referencia

    for (int i=left; i<pivot; i++) {
       


        comparaciones++;
        if (list[pivot] > list[i]) {
            aux++; // incrementamos el valor de i para que vaya al siguiente elemento

            intercambios++;
            swap(list, aux, i); // intercambiamos aux con i
        }
    }

    aux++;  // se incrementa aux para que vaya al siguiente elemento

    intercambios++;
    swap(list, aux, pivot); // intercambiamos aux con pivot
   
    return aux;
}

template <typename T>
void quickSort(vector<T> &list, int left, int right) {


    comparaciones++;
    if (left < right) { // condición de control
        int pivot = getPivot(list, left, right);
        // ordenamos la lista del lado izq de pivote
        quickSort(list, left, pivot - 1);
        // ordenamos la lista del lado der de pivote
        quickSort(list, pivot + 1, right);
    }
}

template <typename T>
void merge(vector<T> &list, int left, int mid, int right) {
    // generamos la lista de left a mid
    // creamos una list para los valores del lado izquierdo
    vector<T> leftList;
    // iteramos la lista de left hasta a mid
    for (int i=left; i<=mid; i++) {
        leftList.push_back(list[i]);
    }
    // generamos la lista de mid+1 a right
    vector<T> rightList;
    // iteramos la lista de left hasta a mid
    for (int j=mid+1; j<=right; j++) {
        rightList.push_back(list[j]);
    }
    // combinamos las dos listas
    // creamos una variable index que contenga el indice a actualizar
    int index = left;
    // inicializamos el indice del lado izquierdo
    int i=0;
    // inicializamos el indice del lado derecho
    int j=0;
    // iteramos mientras no se acaben las listas
    while (i<leftList.size() && j<rightList.size()) {

        comparaciones++;
        // comparamos el valor de i de la listaizq con el valor de j de la lista der
        if (leftList[i] < rightList[j]) {
            // actualizamos list en index con el valor de listLeft en i
            list[index] = leftList[i];
            // incrementamos i;
            i++;
        } else {
            // actualizamos list en index con el valor de listright en j
            list[index] = rightList[j];
            // incrementamos j;
            j++;
        }
        // incrementamos index
        index++;
    }
    // vaciamos la lista del lado izquierdo
    while (i<leftList.size()) {
        // actualizamos list en index con el valor de listLeft en i
        list[index] = leftList[i];
        // incrementamos i;
        i++;
        // incrementamos index
        index++;
    }
    // vaciamos la lista del lado derecho
    while (j<rightList.size()) {
        // actualizamos list en index con el valor de listLeft en i
        list[index] = rightList[j];
        // incrementamos i;
        j++;
        // incrementamos index
        index++;
    }
}

template <typename T>
void mergeSort(vector<T> &list, int left, int right) {

    comparaciones++;

    if (left < right) { // la condición de control 
     
        int mid = (left + right) / 2;

        mergeSort(list, left, mid);  // ordenamos de left a mid con recursividad

        mergeSort(list, mid+1, right); // ordenamos de mid+1 a right

        merge(list, left, mid, right); //usamos el merge para combinar las dos partes
    }
}


template <typename T>
void print(vector<T> &list) {
    for (int i=0; i<list.size(); i++) {
        cout << list[i] << " ";
    }
    cout << endl;
}

vector<int> generarListaInt(int cantidad) {
    vector<int> lista;
    for (int i = 0; i < cantidad; i++) {
        lista.push_back(rand() % 100000);
    }
    return lista;
}

vector<float> generarListaFloat(int cantidad) {
    vector<float> lista;
    for (int i = 0; i < cantidad; i++) {
        lista.push_back((float)(rand() % 100000) / 100.0);
    }
    return lista;
}

vector<char> generarListaChar(int cantidad) {
    vector<char> lista;
    for (int i = 0; i < cantidad; i++) {
        lista.push_back((char)(rand() % 26 + 65)); // letras A-Z
    }
    return lista;
}

int main() {
    srand(time(0));

    // 9 listas: 3 tipos x 3 tamanos
    vector<int>   listaInt1000,   listaInt10000,   listaInt100000;
    vector<float> listaFloat1000, listaFloat10000, listaFloat100000;
    vector<char>  listaChar1000,  listaChar10000,  listaChar100000;

    // Bandera para saber si ya se crearon las listas
    bool listasCreadas = false;

    // Tabla para guardar los tiempos: [algoritmo][tipo][tamano]
    // Se llena de ceros automaticamente
    double tiempos[7][3][3] = {0};

    int opcion;
    do {
        cout << "1. Crear listas aleatorias\n";
        cout << "2. Swap Sort\n";
        cout << "3. Bubble Sort\n";
        cout << "4. Selection Sort\n";
        cout << "5. Insertion Sort\n";
        cout << "6. Merge Sort\n";
        cout << "7. Quick Sort\n";
        cout << "8. Shell Sort (extra)\n";
        cout << "9. Analisis comparativo (todos x tipos x tamanos)\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        // === OPCION 1: crear listas ===
        if (opcion == 1) {
            cout << "Creando listas...\n";

            // Listas de enteros
            listaInt1000   = generarListaInt(1000);
            listaInt10000  = generarListaInt(10000);
            listaInt100000 = generarListaInt(100000);

            // Listas de float
            listaFloat1000   = generarListaFloat(1000);
            listaFloat10000  = generarListaFloat(10000);
            listaFloat100000 = generarListaFloat(100000);

            // Listas de char
            listaChar1000   = generarListaChar(1000);
            listaChar10000  = generarListaChar(10000);
            listaChar100000 = generarListaChar(100000);

            listasCreadas = true;
            cout << "Listas creadas con exito.\n";
        }

        // === OPCIONES 2 a 8: ordenar la lista de int de 1000 ===
        else if (opcion >= 2 && opcion <= 8) {
            if (!listasCreadas) {
                cout << "Primero crea las listas (opcion 1).\n";
                continue;
            }

            // Hacemos una copia para no perder la original
            vector<int> copia = listaInt1000;

            // Reiniciamos contadores
            comparaciones = 0;
            intercambios = 0;

            string nombre = "";

            // Tomamos el tiempo antes de ordenar
            clock_t inicio = clock();

            if (opcion == 2) { nombre = "SwapSort";      swapSort(copia); }
            if (opcion == 3) { nombre = "BubbleSort";    bubbleSort(copia); }
            if (opcion == 4) { nombre = "SelectionSort"; selectionSort(copia); }
            if (opcion == 5) { nombre = "InsertionSort"; insertionSort(copia); }
            if (opcion == 6) { nombre = "MergeSort";     mergeSort(copia, 0, copia.size()-1); }
            if (opcion == 7) { nombre = "QuickSort";     quickSort(copia, 0, copia.size()-1); }
            if (opcion == 8) { nombre = "ShellSort";     shellSort(copia); }

            // Tomamos el tiempo despues de ordenar
            clock_t fin = clock();
            double segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;
            double nanosegundos = segundos * 1000000000.0;

            // Mostramos resultados
            cout << "\n--- " << nombre << " ---\n";
            cout << "Lista ordenada (primeros 20):\n";
            cout << "Tiempo: " << nanosegundos << " ns\n";


            if (opcion >= 2 && opcion <= 5) {
                cout << "Comparaciones: " << comparaciones << "\n";
                cout << "Intercambios: " << intercambios << "\n";
            }
        }

        else if (opcion == 9) {
            if (!listasCreadas) {
                cout << "Primero crea las listas (opcion 1).\n";
                continue;
            }

            string nombres[7] = {"SwapSort","BubbleSort","SelectionSort","InsertionSort", "MergeSort","QuickSort","ShellSort"};

            for (int alg = 0; alg < 7; alg++) {
                for (int tipo = 0; tipo < 3; tipo++) {
                    for (int tam = 0; tam < 3; tam++) {

        
                        int cantidad = 1000;
                        if (tam == 1) cantidad = 10000;
                        if (tam == 2) cantidad = 100000;

                        
                        clock_t inicio = clock(); // Tomamos el tiempo antes

                        if (tipo == 0) {
                            vector<int> ci;
                            if (tam == 0) ci = listaInt1000;
                            if (tam == 1) ci = listaInt10000;
                            if (tam == 2) ci = listaInt100000;

                            if (alg == 0) swapSort(ci);
                            if (alg == 1) bubbleSort(ci);
                            if (alg == 2) selectionSort(ci);
                            if (alg == 3) insertionSort(ci);
                            if (alg == 4) mergeSort(ci, 0, ci.size()-1);
                            if (alg == 5) quickSort(ci, 0, ci.size()-1);
                            if (alg == 6) shellSort(ci);
                        }

                        else if (tipo == 1) {
                            vector<float> cf;
                            if (tam == 0) cf = listaFloat1000;
                            if (tam == 1) cf = listaFloat10000;
                            if (tam == 2) cf = listaFloat100000;

                            if (alg == 0) swapSort(cf);
                            if (alg == 1) bubbleSort(cf);
                            if (alg == 2) selectionSort(cf);
                            if (alg == 3) insertionSort(cf);
                            if (alg == 4) mergeSort(cf, 0, cf.size()-1);
                            if (alg == 5) quickSort(cf, 0, cf.size()-1);
                            if (alg == 6) shellSort(cf);
                        }
                        else {
                            vector<char> cc;
                            if (tam == 0) cc = listaChar1000;
                            if (tam == 1) cc = listaChar10000;
                            if (tam == 2) cc = listaChar100000;

                            if (alg == 0) swapSort(cc);
                            if (alg == 1) bubbleSort(cc);
                            if (alg == 2) selectionSort(cc);
                            if (alg == 3) insertionSort(cc);
                            if (alg == 4) mergeSort(cc, 0, cc.size()-1);
                            if (alg == 5) quickSort(cc, 0, cc.size()-1);
                            if (alg == 6) shellSort(cc);
                        }

                        // Tomamos el tiempo despues
                        clock_t fin = clock();
                        double segundos = (double)(fin - inicio) / CLOCKS_PER_SEC;
                        double nanosegundos = segundos * 1000000000.0;

                        // Guardamos el tiempo en la tabla
                        tiempos[alg][tipo][tam] = nanosegundos;

                        cout << "Hecho: " << nombres[alg] << " tipo " << tipo
                        << " tam " << cantidad << " -> " << nanosegundos << " ns\n";
                    }
                }
            }

            string tipos[3] = {"int","float","char"};
            cout << "\nalgoritmo,tipoDato,tiempo1000,tiempo10000,tiempo100000\n";
            for (int alg = 0; alg < 7; alg++) {
                for (int tipo = 0; tipo < 3; tipo++) {
                    cout << nombres[alg] << "," << tipos[tipo] << ","
                         << tiempos[alg][tipo][0] << ","
                         << tiempos[alg][tipo][1] << ","
                         << tiempos[alg][tipo][2] << "\n";
                }
            }
        }

    } while (opcion != 0);

    cout << "bye";
    return 0;
}


//Reflexión sobre el uso de Copilot
//1. ¿Qué algoritmos lograste implementar con mayor facilidad gracias a Copilot?

//La verdad inguno fue tan fácil, los primeros cuatro (Swap, Bubble, Selection e Insertion) fueron más rápidos porque son más cortos cortos, pero aun así tuve que leer cada línea para entenderla Merge Sort y Quick Sort fueron los más difíciles por la recursividad y los índices que tengo que poner, copilot me ayudó mucho a completar cositas que no sabia que eran necesarias en mi codigo.

//2. ¿En qué casos Copilot te dio soluciones correctas de inmediato y en cuáles tuviste que corregir o ajustar?

//Cuando le pedí cosas específicas  sin mover o cambiar todo mi código porque aveces le pedia cosas pequeñas y me ponia código que no entendía o medir tiempo sin funciones raras, aveces tmb quitaba mis comments que puse para entender mejor todo, igual me gusta ir revisando linea a linea.

//3. ¿Consideras que Copilot te ayudó ahorrar tiempo o te obligó a pensar más?

//Las dos cosas Me ahorró tiempo escribiendo, pero me obligó a pensar más porque tuve que entender y corregir cada línea. Decidí usarlo para estudiar.

//4. Ejemplo concreto donde Copilot no resolvió el problema directamente:

//En todo el código fui teniendo yo la idea pero muchas veces copilot me ayudó a implementarla real y bien porque siempre me marcaba error y con correcta sintaxis ya que no siempre sabía cómo hacerlo o qué funciones usar..


//5. ¿Qué hubieras hecho diferente sin Copilot?

//La verdad en muchas situaciones no habría sabido como iniciar lo que quería hacer porque la idea ya la tenía pero no me sé muchas funciones o de que manera lo puedo lograr, pero habría razonado cada línea desde el principio. Lo que sí habría hecho igual es probar cada algoritmo con listas chiquitas antes de las grandes, porque eso me ayudó mucho a entender.
//Copilot fue útil para avanzar más rápido, pero no reemplazó mi estudio ni mi razonamiento. Tuve que dedicarle tiempo a entender, corregir y ajustar cada parte.