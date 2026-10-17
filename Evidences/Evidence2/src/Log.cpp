#include "../include/Log.h"

int mesANumero(const string& m) {
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

string parseLog(const string& linea, Log& resultado) {
    stringstream ss(linea);

    string monthStr;
    int day, year;
    string time;
    string ip;

    // Intentar leer los primeros 5 campos
    if (!(ss >> monthStr >> day >> year >> time >> ip)) {
        return "faltan campos";
    }

    // Validar el mes
    int mes = mesANumero(monthStr);
    if (mes == 0) return "mes invalido";

    // Validar el día y año
    if (day < 1 || day > 31) return "dia invalido";
    if (year < 2000 || year > 2100) return "año invalido";

    // Validar la hora (HH:MM:SS)
    stringstream timeStream(time);
    int hour, min, sec;
    char colon1, colon2;
    if (!(timeStream >> hour >> colon1 >> min >> colon2 >> sec)) {
        return "hora con formato invalido";
    }
    if (colon1 != ':' || colon2 != ':') return "hora con formato invalido";
    if (hour < 0 || hour > 23) return "hora invalida";
    if (min < 0 || min > 59) return "minuto invalido";
    if (sec < 0 || sec > 59) return "segundo invalido";

    
    string message;
    getline(ss, message);
    if (!message.empty() && message[0] == ' ') {
        message.erase(0, 1);
    }
    if (message.empty()) return "mensaje vacio";

    // Todo bien: llenamos el Log
    resultado.month = mes;
    resultado.day = day;
    resultado.year = year;
    resultado.hour = hour;
    resultado.min = min;
    resultado.sec = sec;
    resultado.ip = ip;
    resultado.message = message;

    return "";
}