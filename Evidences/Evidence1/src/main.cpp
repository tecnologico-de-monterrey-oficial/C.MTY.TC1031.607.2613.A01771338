#include <iostream>
#include "Log.h"

int main() {
    Log registro;

    registro.anio = 2024;
    registro.mes = mesANumero("Sep");
    registro.dia = 15;
    registro.hora = 10;
    registro.minuto = 30;
    registro.segundo = 25;
    registro.ip = "10.14.19.188";
    registro.mensaje = "Unauthorized Access Attempts";

    std::cout << registro.anio << "-" << registro.mes << "-" << registro.dia << " " << registro.hora << ":" << registro.minuto << ":" << registro.segundo << "\n";

    std::cout << registro.ip << "\n";
    std::cout << registro.mensaje << "\n";

    return 0;
}