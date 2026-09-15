#include "../include/Log.h"

//implementa

int mesANumero(const std::string& m) { // esta línea pide de parametro un string guardado en la variable m (mes) y regresa un número int
    if (m == "Jan") return 1;
    if (m == "Feb") return 2;
    if (m == "Mar") return 3;
    if (m == "Apr") return 4;
    if (m == "May") return 5;
    if (m == "Jun") return 6;
    if (m == "Jul") return 7;
    if (m == "Aug") return 8;
    if (m == "Sep") return 9;
    if (m == "Oct") return 10;
    if (m == "Nov") return 11;
    if (m == "Dec") return 12;

    return 0;
}