/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#ifndef Record_hpp
#define Record_hpp

#include <iostream>


class Record{

    public:
    std::string fecha;
    std::string hora;
    std::string ipOrigen;
    std::string puertoOrigen;
    std::string nombreOrigen;
    std::string ipDestino;
    std::string puertoDestino;
    std::string nombreDestino;

    Record(std::string f, std::string h, std::string ipO, std::string puertoO, std::string nO, std::string ipD, std::string puertoD,std::string nD)
    {
        fecha = f;
        hora = h;
        ipOrigen = ipO;
        puertoOrigen = puertoO;
        nombreOrigen = nO;
        ipDestino = ipD;
        puertoDestino = puertoD;
        nombreDestino = nD;
    }

    
};

#endif // !Record_hpp