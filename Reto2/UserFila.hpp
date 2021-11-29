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

class UserFila
{
    public:

        UserFila(std::string fecha,
                 std::string hora,
                 std::string ipOrigen,
                 std::string puertoOrigen,
                 std::string nombreOrigen,
                 std::string ipDestino,
                 std::string puertoDestino,
                 std::string nombreDestino
        );

        UserFila();

        tm fecha;
        std::string fechaString;
        std::string hora;
        std::string ip_Origen;
        int puerto_Origen;
        std::string nombre_Origen;
        std::string ip_Destino;
        int puerto_Destino;
        std::string nombre_Destino;

        void print();
        void printDate(); 
};

UserFila::UserFila(std::string f, std::string h, std::string iO, std::string pO, std::string nO, std::string iD, std::string pD, std::string nD)
{
    struct tm tm;
    const char *fechas = f.c_str();
    strptime(fechas, "%d-%m-%y", &this->fecha);
    this->fechaString = f;
    this->hora = h;
    this->ip_Origen = iO;
    this->nombre_Origen = nO;
    this->ip_Destino = iD;
    this->nombre_Destino = nD;

    try
    {
        this->puerto_Origen = stoi(pO, nullptr, 10);
        this->puerto_Destino = stoi(pO,nullptr, 10);
    }
    catch(...)
    {
        this->puerto_Origen = -1;
        this->puerto_Destino = -1;
    }
};

void UserFila::print()
{
    this->printDate();
    std::cout << "\t" << this->hora 
    << "\t" << this->ip_Origen
    << "\t" << this->puerto_Origen
    << "\t" << this->nombre_Origen
    << "\t" << this->ip_Destino
    << "\t" << this->puerto_Destino
    << "\t" << this->nombre_Destino
    <<std::endl << "=======================" <<std::endl;
}

void UserFila::printDate()
{
    std::cout << this->fecha.tm_mday << "/" << this->fecha.tm_mon + 1 << "/" << this->fecha.tm_year + 1900 << std::endl;
}

#endif /* UserFila_hpp */