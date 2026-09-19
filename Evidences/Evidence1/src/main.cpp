#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //nos deja separar en pedacitos el texto
#include "../include/Log.h"
#include <vector>
#include <ctime>
using namespace std;



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

bool sameDateTime(const Log& a, const Log& b) {

    return a.year == b.year &&
           a.month == b.month &&
           a.day == b.day &&
           a.hour == b.hour &&
           a.min == b.min &&
           a.sec == b.sec;
}

int startBinarySearch(const vector<Log>& logs, const Log& target) { //lo usaremos para la busqueda binaria

    int left = 0;
    int right = logs.size() - 1;
    int answer = logs.size();

    while (left <= right) {

        int mid = (left + right) / 2;

        if (afterBefore(logs[mid], target)) {

            left = mid + 1;

        } else {

            answer = mid;    // aqui se guarda la respuesta para despues checar si hay duplicados
            right = mid - 1;
        }
    }

    return answer;
}

int endBinarySearch(const vector<Log>& logs, const Log& target) {

    int left = 0;
    int right = logs.size() - 1;
    int answer = logs.size();

    while (left <= right) {

        int mid = (left + right) / 2;

        if (afterBefore(target, logs[mid])) {

            answer = mid;
            right = mid - 1;

        } else {

            left = mid + 1;
        }
    }

    return answer;
}



void insertionSort(vector<Log>& logs) {

    for (int i = 1; i < logs.size(); i++) {

        bool exit = false;

        for (int j = i; j > 0 && !exit; j--) {

            if (afterBefore(logs[j], logs[j - 1])) {

                swap(logs[j], logs[j - 1]);

            } else {

                exit = true;
            }
        }
    }
    
}


int getPivot(vector<Log>& logs, int left, int right) {

    int aux = left - 1;

    int pivot = right;

    for (int i = left; i < pivot; i++) {

        if (afterBefore(logs[i], logs[pivot])) {

            aux++;

            swap(logs[aux], logs[i]);
        }
    }

    aux++;

    swap(logs[aux], logs[pivot]);

    return aux;
}

void quickSort(vector<Log>& logs, int left, int right) {

    if (left < right) {

        int pivot = getPivot(logs, left, right);

        quickSort(logs, left, pivot - 1);

        quickSort(logs, pivot + 1, right);
    }
}

void merge(vector<Log>& logs, int left, int mid, int right) {

    vector<Log> leftList;

    for (int i = left; i <= mid; i++) {
        leftList.push_back(logs[i]);
    }

    vector<Log> rightList;

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

void mergeSort(vector<Log>& logs, int left, int right) {

    if (left < right) {

        int mid = (left + right) / 2;

        mergeSort(logs, left, mid);

        mergeSort(logs, mid + 1, right);

        merge(logs, left, mid, right);
    }
}

void swapSort(vector<Log>& logs) {

    for (int i = 0; i < logs.size() - 1; i++) {

        for (int j = i + 1; j < logs.size(); j++) {

            if (afterBefore(logs[j], logs[i])) {

                swap(logs[i], logs[j]);
            }
        }
    }
}


void bubbleSort(vector<Log>& logs) {

    bool change = true;

    for (int i = logs.size() - 1; i > 0 && change; i--) {

        change = false;

        for (int j = 0; j < i; j++) {

            if (afterBefore(logs[j + 1], logs[j])) {

                change = true;

                swap(logs[j], logs[j + 1]);
            }
        }
    }
}


void selectionSort(vector<Log>& logs) {

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


    cout << "--------MENU--------\n";
    cout << "Hi!! Choose a file to sort:\n";

    int fileSelection; // Variable para seleccionar el archivo
    cout << "Choose a file:\n";
    cout << "1. log607-1.txt\n";
    cout << "2. log607-2.txt\n";
    cin >> fileSelection;

    string fileName;

    if (fileSelection == 1) {
        fileName = "../data/log607-1.txt";
    } else if (fileSelection == 2) {
        fileName = "../data/log607-2.txt";
    } else {
        cout << "Choose between file 1 or file 2.\n";
        return 1;
    }

    ifstream file(fileName);     //lee el file 

    if (!file) {
       cout << "Error!! The file could no be opened.\n";
        return 1;
    }


    int ChoosenAlgorithm; // Variable para seleccionar el algoritmo
    cout << "Choose the sorting algorithm we are going to use:\n";
    cout << "1. Insertion Sort\n";
    cout << "2. Quick Sort\n";
    cout << "3. Merge Sort\n";
    cout << "4. Bubble Sort\n";
    cout << "5. Selection Sort\n";
    cout << "6. Swap Sort\n";
    cin >> ChoosenAlgorithm;

    if (ChoosenAlgorithm < 1 || ChoosenAlgorithm > 6) {
        cout << "Invalid, choose a valid sorting algorithm."<< endl;
        return 1;
    }


    cout << "How long do you think it would take to sort your file in seconds? :" << endl;
    double predictedTime;
    cin >> predictedTime;


    cout << "Why do you think it will take that long?\n";
    string predictedReason;
    cin.ignore();
    getline(cin, predictedReason);

    cout <<"Sorting file...." << endl;


    string line;
    vector<Log> logs;  // Vector para almacenar muchos logs

    while (getline(file, line)) { //mientras haya lineas que leer las lee
        stringstream ss(line);


        //crear variables para convertir los pedacitos en un objeto Log
        string month;
        int day;
        int year;
        string time;
        string ip;
        string message;

        ss >> month >> day >> year >> time >> ip; // Extrae los primeros datos de la línea "Toma la primera palabra y ponla en month; toma la siguiente y ponla en day"

        getline(ss, message); // Toma el mensaje completo
        if (!message.empty() && message[0] == ' ') {
        message.erase(0, 1);  //borra el espacio inicial
        }

        stringstream timeStream(time);
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


    clock_t start = clock();

    string AlgorithmName;
    string bestCase;
    string worstCase;
    
    if (ChoosenAlgorithm == 1) {
        AlgorithmName = "Insertion Sort";
        bestCase = "O(n)";
        worstCase = "O(n^2)";
        insertionSort(logs);
    }
    else if (ChoosenAlgorithm == 2) {
        AlgorithmName = "Quick Sort";
        bestCase = "O(n log n)";
        worstCase = "O(n^2)";
        quickSort(logs, 0, logs.size() - 1);
    }
    else if (ChoosenAlgorithm == 3) {
        AlgorithmName = "Merge Sort";
        bestCase = "O(n log n)";
        worstCase = "O(n log n)";
        mergeSort(logs, 0, logs.size() - 1);
    }
    else if (ChoosenAlgorithm == 4) {
        AlgorithmName = "Bubble Sort";
        bestCase = "O(n)";
        worstCase = "O(n^2)";
        bubbleSort(logs);
    }
    else if (ChoosenAlgorithm == 5) {
        AlgorithmName = "Selection Sort";
        bestCase = "O(n^2)";
        worstCase = "O(n^2)";   
        selectionSort(logs);
    }
    else if (ChoosenAlgorithm == 6) {
        AlgorithmName = "Swap Sort";
        bestCase = "O(n^2)";
        worstCase = "O(n^2)";
        swapSort(logs);
    }

    clock_t end = clock();
    double sortingTime = double(end - start) / CLOCKS_PER_SEC;
    double difference = abs(sortingTime - predictedTime);
    double differencePercentage = (difference / sortingTime) * 100;





    cout << endl << "-------- Search an specific date and time --------" << endl;

    Log startDate;
    Log endDate;

    cout << "\nEnter the START date and time:\n";

    cout << "Year: ";
    cin >> startDate.year;

    cout << "Month: ";
    cin >> startDate.month;

    cout << "Day: ";
    cin >> startDate.day;

    cout << "Hour: ";
    cin >> startDate.hour;

    cout << "Minute: ";
    cin >> startDate.min;

    cout << "Second: ";
    cin >> startDate.sec;

    cout << "\nEnter the END date and time:\n";

    cout << "Year: ";
    cin >> endDate.year;

    cout << "Month: ";
    cin >> endDate.month;

    cout << "Day: ";
    cin >> endDate.day;

    cout << "Hour: ";
    cin >> endDate.hour;

    cout << "Minute: ";
    cin >> endDate.min;

    cout << "Second: ";
    cin >> endDate.sec;



    //funciones de la busqueda binaria
    int startIndex = startBinarySearch(logs, startDate);
    int endIndex = endBinarySearch(logs, endDate);



    if (startIndex == logs.size() || startIndex >= endIndex) {

        cout << "No records were found in this range, choose another one.";

    } else {



        //IA me lo ordenó 
    for (int i = startIndex; i < endIndex; i++) {

        cout << logs[i].year << "-";
        cout << logs[i].month << "-";
        cout << logs[i].day << " ";

        cout << logs[i].hour << ":";
        cout << logs[i].min << ":";
        cout << logs[i].sec << " ";

        cout << logs[i].ip << " ";
        cout << logs[i].message << "\n";
    }
}


    cout <<endl;
    cout << "--------Data and Results-------" << endl;
    cout << "File processed: " << fileName << endl;
    cout << "Algorithm used: " << AlgorithmName << endl;
    cout << "Sorting time: " << sortingTime << " seconds" << endl;
    cout << endl;
    cout << "Predicted time: " << predictedTime << " seconds" << endl;
    cout << "Predicted reason: " << predictedReason << endl;
    cout << "Prediction difference: " << difference << " seconds" << endl;
    cout << "Error in the prediction: " << differencePercentage << "%" << endl;
    if (differencePercentage <= 20) {
    cout << "Prediction matched the actual result.\n";
    } else {
    cout << "Prediction did not match the actual result.\n";
}
    cout << endl;
    cout << "Data size: " << logs.size() << endl;
    cout << "Best case: " << bestCase << endl;
    cout << "Worst case: " << worstCase << endl;

    return 0;
}




