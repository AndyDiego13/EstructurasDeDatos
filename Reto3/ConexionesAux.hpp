/*
    Situacion Problema - Ataques Cibernéticos
    ConexionesAux.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#ifndef ConexionesAux_hpp
#define ConexionesAux_hpp

#include <iostream>
#include <string>

class ConexionesAux //Clase auxiliar (para las conexiones entre computadoras)
{

    public:
    std::string ip;
    int puerto;
    std::string conex;
    std::string fecha;

    /* Constructor reto2
    ConexionesAux(std::string ip, int puerto, std::string conex)
    {
        this -> ip = ip;
        this -> puerto = puerto;
        this -> conex = conex;
    }
    */

    ConexionesAux(std::string ip, int puerto, std::string conex, std::string fecha)
    {
        this -> ip = ip;
        this -> puerto = puerto;
        this -> conex = conex;
        this -> fecha = fecha;
    }
    ~ConexionesAux() {}; //Destructor

    std::string getIp()
    {
        return ip;
    }
};

#endif // !ConexionesAux_hpp