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
#include <ctime>

using namespace std;

class UserFila {
public:
    string fecha;
    string hora;
    string ipOrigen;
    string puertoOrigen;
    string nombreOrigen;
    string ipDestino;
    string puertoDestino;
    string nombreDestino;
    tm fechaTm;
    std::string fechaString;
    

    int origenPuerto;
    int destinoPuerto;
    
    //Constructor
    UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD);

    //UserFila(){}
    
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
           
    //Obtener Fecha
    string getFecha()
    {
        return fecha;
    }

    //Obtener Hora
    string getHora()
    {
        return hora;
    }

    //Obtener Ip Origen
    string getIpO()
    {
        return ipOrigen;
    }

    string getPuertoO()
    {
        return puertoOrigen;
    }

    //Obtener nombre del puerto origen
    string getNombreO()
    {
        return nombreOrigen;
    }

    //Obtener ip Destino
    string getIpD()
    {
        return ipDestino;
    }

    //Obtener nombre del puerto destino
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

    void printDate()
    {
        std::cout << this->fechaTm.tm_mday << "/" << this->fechaTm.tm_mon +1 << "/" << this->fechaTm.tm_year <<std::endl;
    }

    void print()
    {
        this->printDate();
        std::cout << "\t" << this->hora
        << "\t" << this->ipOrigen
        << "\t" << this->puertoOrigen
        << "\t" << this->nombreOrigen
        << "\t" << this->ipDestino
        << "\t" << this->puertoDestino
        << "\t" << this->nombreDestino
        <<std::endl<< "========================"<<std::endl;
    }
};

UserFila::UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD)
{
    struct tm tm;
    const char *_fecha = f.c_str();
    strptime(_fecha, "%d-%m,%y", &this->fechaTm);
    this->fechaString = _fecha;
    this->hora = h;
    this->ipOrigen = iO;
    this->nombreOrigen = nO;
    this->ipDestino = iD;
    this->nombreDestino = nD;

    try
    {
        this->origenPuerto = stoi(pO, nullptr, 10);
        this->destinoPuerto = stoi(pO,nullptr, 10);
    }
    catch(...)
    {
        this->origenPuerto = -1;
        this->destinoPuerto = -1;
    }
}


#endif /* UserFila_hpp */