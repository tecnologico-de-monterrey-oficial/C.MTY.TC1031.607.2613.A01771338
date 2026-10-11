#ifndef LOG_H
#define LOG_H

#include <string>
#include <sstream>
using namespace std;

struct Log {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    string ip;
    string message;

    // Convierte el log a string 
    string toString() const {
        stringstream ss;
        ss << year << " " << month << " " << day << " "
           << hour << ":" << min << ":" << sec << " "
           << ip << " " << message;
        return ss.str();
    }
};

int mesANumero(const string& m);

#endif