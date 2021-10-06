/*
    Situacion Problema - Ataques Cibernéticos
    UserFila.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#ifndef UserFila_hpp
#define UserFila_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

class UserFila {
private:
    string fecha;
    string hora;
    string ipOrigen;
    string puertoOrigen;
    string nombreOrigen;
    string ipDestino;
    string puertoDestino;
    string nombreDestino;
    
public:
    //constructor
    UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD):
    fecha(f), hora(h), ipOrigen(iO), puertoOrigen(pO), nombreOrigen(nO), ipDestino(iD),puertoDestino(pD), nombreDestino(nD) {}
    UserFila(){}
    
    //destructor
    ~UserFila(){}
    
    //sobrecarga de operador para imrimir y poder ser ocupado en otras clases
    friend std::ostream & operator<<(std::ostream & os, const UserFila & userFila)
    {
        
        os << userFila.fecha << " - ";
        os << userFila.hora << " - ";
        os << userFila.ipOrigen << " - ";
        os << userFila.puertoOrigen << " - ";
        os << userFila.nombreOrigen << " - ";
        os << userFila.ipDestino << " - ";
        os << userFila.puertoDestino << " - ";
        os << userFila.nombreDestino << " - ";
        os << endl;
    
    
        return os;

    }
           
    
    string getFecha()
    {
        return fecha;
    }

    string getHora()
    {
        return hora;
    }

    string getIpO()
    {
        return ipOrigen;
    }

    string getPuertoO()
    {
        return puertoOrigen;
    }

    string getNombreO()
    {
        return nombreOrigen;
    }

    string getIpD()
    {
        return ipDestino;
    }

    string getPuertoD()
    {
        return puertoDestino;
    }

    string getNombreD()
    {
        return nombreDestino;
    }

    //para comparar todo por fecha

    static bool fecha_asc(UserFila co, UserFila b)
    {
        return co.fecha < b.fecha;
    }
};


#endif /* UserFila_hpp */