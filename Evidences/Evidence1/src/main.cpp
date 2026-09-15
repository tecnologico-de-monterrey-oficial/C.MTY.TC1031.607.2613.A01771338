#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "../include/Log.h"
#include <vector>


int main() {

    std::ifstream file("../data/log607-1.txt");

    if (!file) {
        std::cout << "Error!! The file could no be opened.\n";
        return 1;
    }

    
    std::string line;
    std::vector<Log> logs;
    
    std::getline(file, line);

    std::stringstream ss(line); // Crea un stringstream a partir de la línea leída

    std::string month;
    int day;
    int year;
    std::string time;
    std::string ip;
    std::string message;
    ss >> month >> day >> year >> time >> ip; // Extrae los datos de la línea sin importar sus espacios gracias a ss

    std::getline(ss, message); // Extrae el mensaje completo
    if (!message.empty() && message[0] == ' ') { //borra el espacio inicial
        message.erase(0, 1);
    }

    std::stringstream timeStream(time);

    int hour;
    int min;
    int sec;
    char colon;
    timeStream >> hour >> colon >> min >> colon >> sec;

    
    Log event;
    event.month = mesANumero(month);
    event.day = day;
    event.year = year;
    event.hour = hour;
    event.min = min;
    event.sec = sec;
    event.ip = ip;
    event.message = message;

    std::cout << "Month: " << event.month << "\n";
    std::cout << "Day: " << event.day << "\n";
    std::cout << "Year: " << event.year << "\n";
    std::cout << "Hour: " << event.hour << "\n";
    std::cout << "Min: " << event.min << "\n";
    std::cout << "Sec: " << event.sec << "\n";
    std::cout << "IP: " << event.ip << "\n";
    std::cout << "Message: " << event.message << "\n";

    return 0;
}



