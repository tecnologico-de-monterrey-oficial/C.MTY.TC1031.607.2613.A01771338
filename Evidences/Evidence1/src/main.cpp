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


int main() {

    std::ifstream file("../data/log607-1.txt");     //lee el file 

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

    clock_t start = clock(); //empezar el cronometro
    
    insertionSort(logs);

    clock_t end = clock(); //terminar el cronometro

    double time = double(end - start) / CLOCKS_PER_SEC;

    std::cout <<  "time: " << time << " sec\n";
    for (int i = 0; i < 5; i++) {

    std::cout << logs[i].year << "-" << logs[i].month << "-" << logs[i].day << " "<< logs[i].hour << ":"<< logs[i].min << ":"  << logs[i].sec << "\n";
}
    std::cout << "Total logs: " << logs.size() << "\n";

    return 0;
}



