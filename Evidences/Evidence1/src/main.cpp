#include <iostream>
#include <fstream>
#include <string>
#include <sstream> //nos deja separar en pedacitos el texto
#include "../include/Log.h"
#include <vector>


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
    std::cout << "Total logs: " << logs.size() << "\n";

    return 0;
}



