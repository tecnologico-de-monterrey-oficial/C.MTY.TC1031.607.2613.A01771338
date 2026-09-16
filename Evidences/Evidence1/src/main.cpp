#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //nos deja separar en pedacitos el texto
#include "../include/Log.h"
#include <vector>
#include <ctime>

bool afterBefore(const Log& a, const Log& b) { 

    if (a.year < b.year) return true;
    if (a.year > b.year) return false;

    if (a.month < b.month) return true;
    if (a.month > b.month) return false;

    if (a.day < b.day) return true;
    if (a.day > b.day) return false;

    if (a.hour < b.hour) return true;
    if (a.hour > b.hour) return false;

    if (a.min < b.min) return true;
    if (a.min > b.min) return false;

    return a.sec < b.sec;
}

void insertionSort(std::vector<Log>& logs) {

    for (int i = 1; i < logs.size(); i++) {

        bool exit = false;

        for (int j = i; j > 0 && !exit; j--) {

            if (afterBefore(logs[j], logs[j - 1])) {

                std::swap(logs[j], logs[j - 1]);

            } else {

                exit = true;
            }
        }
    }
}



int getPivot(std::vector<Log>& logs, int left, int right) {

    int aux = left - 1;

    int pivot = right;

    for (int i = left; i < pivot; i++) {

        if (afterBefore(logs[i], logs[pivot])) {

            aux++;

            std::swap(logs[aux], logs[i]);
        }
    }

    aux++;

    std::swap(logs[aux], logs[pivot]);

    return aux;
}

void quickSort(std::vector<Log>& logs, int left, int right) {

    if (left < right) {

        int pivot = getPivot(logs, left, right);

        quickSort(logs, left, pivot - 1);

        quickSort(logs, pivot + 1, right);
    }
}

void merge(std::vector<Log>& logs, int left, int mid, int right) {

    std::vector<Log> leftList;

    for (int i = left; i <= mid; i++) {
        leftList.push_back(logs[i]);
    }

    std::vector<Log> rightList;

    for (int j = mid + 1; j <= right; j++) {
        rightList.push_back(logs[j]);
    }

    int index = left;

    int i = 0;
    int j = 0;

    while (i < leftList.size() && j < rightList.size()) {

        if (afterBefore(leftList[i], rightList[j])) {

            logs[index] = leftList[i];
            i++;

        } else {

            logs[index] = rightList[j];
            j++;
        }

        index++;
    }

    while (i < leftList.size()) {

        logs[index] = leftList[i];

        i++;
        index++;
    }

    while (j < rightList.size()) {

        logs[index] = rightList[j];

        j++;
        index++;
    }
}

void mergeSort(std::vector<Log>& logs, int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSort(logs, left, mid);

        mergeSort(logs, mid + 1, right);

        merge(logs, left, mid, right);
    }
}

void swapSort(std::vector<Log>& logs) {

    for (int i = 0; i < logs.size() - 1; i++) {

        for (int j = i + 1; j < logs.size(); j++) {

            if (afterBefore(logs[j], logs[i])) {

                std::swap(logs[i], logs[j]);
            }
        }
    }
}


void bubbleSort(std::vector<Log>& logs) {

    bool change = true;

    for (int i = logs.size() - 1; i > 0 && change; i--) {

        change = false;

        for (int j = 0; j < i; j++) {

            if (afterBefore(logs[j + 1], logs[j])) {

                change = true;

                std::swap(logs[j], logs[j + 1]);
            }
        }
    }
}


void selectionSort(std::vector<Log>& logs) {

    for (int i = 0; i < logs.size() - 1; i++) {

        int min = i;

        for (int j = i + 1; j < logs.size(); j++) {

            if (afterBefore(logs[j], logs[min])) {

                min = j;
            }
        }

        std::swap(logs[min], logs[i]);
    }
}




int main() {

    int fileSelection;

    std::cout << "Choose a file:\n";
    std::cout << "1. log607-1.txt\n";
    std::cout << "2. log607-2.txt\n";
    std::cin >> fileSelection;

    std::string fileName;

    if (fileSelection == 1) {
        fileName = "../data/log607-1.txt";
    } else if (fileSelection == 2) {
        fileName = "../data/log607-2.txt";
    } else {
        std::cout << "Choose between file 1 or file 2.\n";
        return 1;
    }

    std::ifstream file(fileName);     //lee el file 

    if (!file) {
       std::cout << "Error!! The file could no be opened.\n";
        return 1;
    }



    std::string line;
    std::vector<Log> logs;  // Vector para almacenar muchos logs

    while (std::getline(file, line)) { //mientras haya lineas que leer las lee
        std::stringstream ss(line); 


        //crear variables para convertir los pedacitos en un objeto Log
        std::string month;
        int day;
        int year;
        std::string time;
        std::string ip;
        std::string message;

        ss >> month >> day >> year >> time >> ip; // Extrae los primeros datos de la línea "Toma la primera palabra y ponla en month; toma la siguiente y ponla en day"

        std::getline(ss, message); // Toma el mensaje completo
        if (!message.empty() && message[0] == ' ') { 
        message.erase(0, 1);  //borra el espacio inicial
        }

        std::stringstream timeStream(time);
        int hour;
        int min;
        int sec;
        char colon; //guarda aparte el caracter ':'
        timeStream >> hour >> colon >> min >> colon >> sec; 


        //crear log

        Log event;
        event.month = mesANumero(month);
        event.day = day;
        event.year = year;
        event.hour = hour;
        event.min = min;
        event.sec = sec;
        event.ip = ip;
        event.message = message;

        //guardar log
        logs.push_back(event);

        

    }


    //creamos una copia para poder medir los tiempos simultamenamente probando todas los algoritmos

    std::vector<Log> logsInsertion = logs;
    std::vector<Log> logsQuick = logs;
    std::vector<Log> logsMerge = logs;
    std::vector<Log> logsBubble = logs;
    std::vector<Log> logsSelection = logs;
    std::vector<Log> logsSwap = logs;

   

    clock_t start = clock();
    insertionSort(logsInsertion);
    clock_t end = clock();
    double timeInsertion = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    quickSort(logsQuick, 0, logsQuick.size() - 1);
    end = clock();
    double timeQuick = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    mergeSort(logsMerge, 0, logsMerge.size() - 1);
    end = clock();
    double timeMerge = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    bubbleSort(logsBubble);
    end = clock();
    double timeBubble = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    selectionSort(logsSelection);
    end = clock();
    double timeSelection = double(end - start) / CLOCKS_PER_SEC;


    start = clock();
    swapSort(logsSwap);
    end = clock();
    double timeSwap = double(end - start) / CLOCKS_PER_SEC;



    std::cout << "Insertion Sort time: " << timeInsertion << " seconds\n";
    std::cout << "Quick Sort time: " << timeQuick << " seconds\n";
    std::cout << "Merge Sort time: " << timeMerge << " seconds\n";
    std::cout << "Bubble Sort time: " << timeBubble << " seconds\n";
    std::cout << "Selection Sort time: " << timeSelection << " seconds\n";
    std::cout << "Swap Sort time: " << timeSwap << " seconds\n";


    
    return 0;
}



