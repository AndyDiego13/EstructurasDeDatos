/*
    Situacion Problema - Ataques Cibernéticos
    ConexionesAux.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

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
    tm fechaTm;

    /* Constructor reto2
    ConexionesAux(std::string ip, int puerto, std::string conex)
    {
        this -> ip = ip;
        this -> puerto = puerto;
        this -> conex = conex;
    }
    */

    ConexionesAux(std::string ip, int puerto, std::string conex, tm fechaTm)
    {
        this -> ip = ip;
        this -> puerto = puerto;
        this -> conex = conex;
        this -> fechaTm = fechaTm;
    }
    ~ConexionesAux() {}; //Destructor

    std::string getIp()
    {
        return ip;
    }

    void printFecha()
    {
        std::cout << this->fechaTm.tm_mday << "/" << this->fechaTm.tm_mon + 1 << "/" << this->fechaTm.tm_year + 1900 <<std::endl;
    }
};

#endif // !ConexionesAux_hpp