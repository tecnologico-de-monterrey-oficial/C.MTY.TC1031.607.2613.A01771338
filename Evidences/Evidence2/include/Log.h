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
};

int mesANumero(const string& m);

// Compara dos logs por fecha y hora. Regresa true si 'a' es anterior a 'b'.
bool afterBefore(const Log& a, const Log& b);

// Compara dos logs por fecha y hora. Regresa true si son exactamente iguales.
bool sameDateTime(const Log& a, const Log& b);

// Intenta convertir una línea de texto en un Log.
// Regresa "" si todo está bien, o un mensaje de error si algo está mal.
string LineToLog(const string& linea, Log& resultado);

#endif