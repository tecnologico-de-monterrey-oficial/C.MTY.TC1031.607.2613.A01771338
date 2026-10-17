#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <map>
#include "../include/Log.h"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/DoublyLinkedList.h"
using namespace std;

DoublyLinkedList<Log> lista;
bool cargado = false;
bool ordenado = false;
string archivoActual = "";

string meses[13] = {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun","Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};


string claveDia(Log log) {
    return meses[log.month] + " " + to_string(log.day) + " " + to_string(log.year);
}

int stringAInt(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = num * 10 + (s[i] - '0');
    }
    return num;
}

void cargarArchivo() {
    cout << "\nQue archivo quieres cargar?" << endl;
    cout << "1. log607-1.txt" << endl;
    cout << "2. log607-2.txt" << endl;
    cout << "Opcion: ";

    int opcion;
    cin >> opcion;

    if (opcion == 1) archivoActual = "data/log607-1.txt";
    else if (opcion == 2) archivoActual = "data/log607-2.txt";
    else {
        cout << "Opcion invalida" << endl;
        return;
    }

    ifstream file(archivoActual);
    if (!file) {
        cout << "No se pudo abrir el archivo " << archivoActual << endl;
        return;
    }

    lista.clear();
    ordenado = false;

    // Leer y meter a la Fila
    Queue<string> fila;
    string linea;
    while (getline(file, linea)) {
        fila.push(linea);
    }
    file.close();

    // Sacar de la Fila, convertir y meter a la lista
    int cargados = 0, omitidos = 0;
    while (!fila.empty()) {
        string actual = fila.front();
        fila.pop();

        Log log;
        string error = LineToLog(actual, log);

        if (error == "") {
            lista.addLast(log);
            cargados++;
        } else {
            omitidos++;
        }
    }

    cargado = true;
    cout << "\nRegistros cargados: " << cargados << endl;
    cout << "Lineas omitidas: " << omitidos << endl;
    cout << "Total en la lista: " << lista.getSize() << endl;
}

void ordenarLista() {
    if (!cargado) {
        cout << "Primero carga un archivo (opcion 1)" << endl;
        return;
    }
    if (ordenado) {
        cout << "La lista ya esta ordenada" << endl;
        return;
    }

    cout << "\nTamaño de los datos: " << lista.getSize() << endl;
    cout << "Cuantas comparaciones esperas? ";
    int prediccion;
    cin >> prediccion;

    clock_t inicio = clock();
    lista.mergeSort();
    clock_t fin = clock();
    double tiempo = double(fin - inicio) / CLOCKS_PER_SEC;

    cout << "\n===== RESULTADO =====" << endl;
    cout << "Algoritmo: Merge Sort" << endl;
    cout << "Archivo: " << archivoActual << endl;
    cout << "Tamano: " << lista.getSize() << endl;
    cout << "Tiempo: " << tiempo << " segundos" << endl;
    cout << "Comparaciones: " << lista.getComparaciones() << endl;
    cout << "Profundidad maxima: " << lista.getProfundidadMaxima() << endl;
    cout << "Tu prediccion: " << prediccion << endl;

    int error = prediccion - lista.getComparaciones();
    if (error < 0) error = -error;
    double porcentaje = (double(error) / lista.getComparaciones()) * 100;

    if (porcentaje <= 20) cout << "Prediccion: coincidio" << endl;
    else cout << "Prediccion: NO coincidio" << endl;

    ordenado = true;

    ofstream output("out/output607.out");
    if (!output) {
        cout << "No se pudo crear out/output607.out" << endl;
        return;
    }

    NodeD<Log>* aux = lista.getHead();
    while (aux != nullptr) {
        Log log = aux->data;
        output << meses[log.month] << " ";
        if (log.day < 10) output << "0";
        output << log.day << " " << log.year << " ";
        if (log.hour < 10) output << "0";
        output << log.hour << ":";
        if (log.min < 10) output << "0";
        output << log.min << ":";
        if (log.sec < 10) output << "0";
        output << log.sec << " ";
        output << log.ip << " " << log.message << "\n";
        aux = aux->next;
    }
    output.close();
    cout << "Archivo guardado: out/output607.out" << endl;
}

// ============== OPCION 3: BUSCAR POR DIA ==============
void buscarPorDia() {
    if (!cargado) {
        cout << "Primero carga un archivo (opcion 1)" << endl;
        return;
    }
    if (!ordenado) {
        cout << "Primero ordena la lista (opcion 2)" << endl;
        return;
    }

    cout << "\nIngresa el dia (ejemplo: Sep 14 2024): ";
    string mesStr, diaStr, anioStr;
    cin >> mesStr >> diaStr >> anioStr;

    int mes = mesANumero(mesStr);
    if (mes == 0) {
        cout << "Mes invalido" << endl;
        return;
    }

    int dia = stringAInt(diaStr);
    int anio = stringAInt(anioStr);

    if (dia < 1 || dia > 31) {
        cout << "Dia invalido" << endl;
        return;
    }
    if (anio < 2000 || anio > 2100) {
        cout << "Año invalido" << endl;
        return;
    }

    cout << "\n===== REGISTROS DEL DIA " << mesStr << " " << dia << " " << anio << " =====" << endl;

    int total = 0;
    NodeD<Log>* aux = lista.getHead();
    while (aux != nullptr) {
        Log log = aux->data;

        if (log.year > anio) break;
        if (log.year == anio && log.month > mes) break;
        if (log.year == anio && log.month == mes && log.day > dia) break;

        if (log.year == anio && log.month == mes && log.day == dia) {
            cout << log.toString() << endl;
            total++;
        }
        aux = aux->next;
    }

    if (total == 0) cout << "No hay registros para ese dia" << endl;
    else cout << "Total encontrados: " << total << endl;
}

// ============== OPCION 4: DESCENDENTE CON PILA ==============
void mostrarDescendente() {
    if (!cargado) {
        cout << "Primero carga un archivo (opcion 1)" << endl;
        return;
    }
    if (!ordenado) {
        cout << "Primero ordena la lista (opcion 2)" << endl;
        return;
    }

    cout << "\nIngresa el dia (ejemplo: Sep 14 2024): ";
    string mesStr, diaStr, anioStr;
    cin >> mesStr >> diaStr >> anioStr;

    int mes = mesANumero(mesStr);
    if (mes == 0) {
        cout << "Mes invalido" << endl;
        return;
    }

    int dia = stringAInt(diaStr);
    int anio = stringAInt(anioStr);

    Stack<Log> pila;
    NodeD<Log>* aux = lista.getHead();
    while (aux != nullptr) {
        Log log = aux->data;

        if (log.year > anio) break;
        if (log.year == anio && log.month > mes) break;
        if (log.year == anio && log.month == mes && log.day > dia) break;

        if (log.year == anio && log.month == mes && log.day == dia) {
            pila.push(log);
        }
        aux = aux->next;
    }

    cout << "\n===== DIA " << mesStr << " " << dia << " " << anio << " (descendente) =====" << endl;

    int total = 0;
    while (!pila.empty()) {
        Log log = pila.getTop();
        pila.pop();
        cout << log.toString() << endl;
        total++;
    }

    if (total == 0) cout << "No hay registros para ese dia" << endl;
    else cout << "Total encontrados: " << total << endl;
}

// ============== OPCION 5: ESTADISTICAS ==============
void mostrarEstadisticas() {
    if (!cargado) {
        cout << "Primero carga un archivo (opcion 1)" << endl;
        return;
    }

    map<string, int> conteoDias;
    map<string, int> conteoEventos;
    map<string, int> conteoIPs;

    NodeD<Log>* aux = lista.getHead();
    while (aux != nullptr) {
        Log log = aux->data;
        conteoDias[claveDia(log)]++;
        conteoEventos[log.message]++;
        conteoIPs[log.ip]++;
        aux = aux->next;
    }

    cout << "\n===== ESTADISTICAS =====" << endl;
    cout << "Total de registros: " << lista.getSize() << endl;

    int maxDia = 0;
    for (auto& par : conteoDias) if (par.second > maxDia) maxDia = par.second;
    cout << "\nDia(s) con mas incidentes (" << maxDia << "):" << endl;
    for (auto& par : conteoDias) if (par.second == maxDia) cout << "  " << par.first << endl;

    int maxEvento = 0;
    for (auto& par : conteoEventos) if (par.second > maxEvento) maxEvento = par.second;
    cout << "\nEvento(s) mas frecuente(s) (" << maxEvento << "):" << endl;
    for (auto& par : conteoEventos) if (par.second == maxEvento) cout << "  " << par.first << endl;

    int maxIP = 0;
    for (auto& par : conteoIPs) if (par.second > maxIP) maxIP = par.second;
    cout << "\nIP(s) mas frecuente(s) (" << maxIP << "):" << endl;
    for (auto& par : conteoIPs) if (par.second == maxIP) cout << "  " << par.first << endl;
}


int main() {
    int opcion;

    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. Cargar archivo" << endl;
        cout << "2. Ordenar por fecha y hora" << endl;
        cout << "3. Buscar logs por dia" << endl;
        cout << "4. Mostrar logs por dia (descendente)" << endl;
        cout << "5. Estadisticas" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) cargarArchivo();
        else if (opcion == 2) ordenarLista();
        else if (opcion == 3) buscarPorDia();
        else if (opcion == 4) mostrarDescendente();
        else if (opcion == 5) mostrarEstadisticas();
        else if (opcion == 0) cout << "Adios!" << endl;
        else cout << "Opcion invalida" << endl;

    } while (opcion != 0);

    return 0;
}