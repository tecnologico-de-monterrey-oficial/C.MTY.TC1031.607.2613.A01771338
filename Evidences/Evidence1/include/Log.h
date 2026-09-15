//Elena María Barrios Jordan
//A01771338

//define 
#ifndef LOG_H
#define LOG_H

#include <string>

struct Log {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    std::string ip;
    std::string message;
};

int mesANumero(const std::string& m);

#endif