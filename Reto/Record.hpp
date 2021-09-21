/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/
#include <iostream>


class Record{

    public:
    std::string fecha;
    std::string hora;
    std::string ipOrigen;
    int puertoOrigen;
    std::string nombreOrigen;
    std::string ipDestino;
    int puertoDestino;
    std::string nombreDestino;

    Record(std::string f, std::string h, std::string ipO, int pO, std::string nO, std::string ipD, int pD, std::string nD);
};