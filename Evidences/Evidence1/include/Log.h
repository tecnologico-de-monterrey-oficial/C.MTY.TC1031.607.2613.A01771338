//Elena María Barrios Jordan
//A01771338


#ifndef LOG_H
#define LOG_H

#include <string>

struct Log {
    int anio;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    std::string ip;
    std::string mensaje;
};

int mesANumero(const std::string& m);

#endif