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

    // Convierte el log a string con el formato original
    string toString() const {
        stringstream ss;
        ss << year << " " << month << " " << day << " "
           << hour << ":" << min << ":" << sec << " "
           << ip << " " << message;
        return ss.str();
    }

    // Operador < para poder comparar dos Logs (lo usa el mergeSort)
    bool operator<(const Log& otro) const {
        if (year != otro.year) return year < otro.year;
        if (month != otro.month) return month < otro.month;
        if (day != otro.day) return day < otro.day;
        if (hour != otro.hour) return hour < otro.hour;
        if (min != otro.min) return min < otro.min;
        return sec < otro.sec;
    }
};

// Convierte el nombre del mes ("Jan", "Feb", ...) a número (1, 2, ...)
int mesANumero(const string& m);

// Compara dos logs por fecha y hora. Regresa true si 'a' es anterior a 'b'.
bool afterBefore(const Log& a, const Log& b);

// Compara dos logs por fecha y hora. Regresa true si son exactamente iguales.
bool sameDateTime(const Log& a, const Log& b);

// Convierte una línea de texto en un Log.
// Regresa "" si todo está bien, o un mensaje de error si algo está mal.
string LineToLog(const string& linea, Log& resultado);

#endif