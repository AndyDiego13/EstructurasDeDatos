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
    std::string nombreOrigen;
    std::string nombreDestino;

    Record(std::string f, std::string h, std::string nO, std::string nD)
    {
        fecha = f;
        hora = h;
        nombreOrigen = nO;
        nombreDestino = nD;
    }
    
};

#endif // !Record_hpp