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
        )

        UserFila();

        tm fecha;
        std::string fechaString;
        std::string hora;
        std::string ipOrigen;
        int puertoOrigen;
        std::string nombreOrigen;
        std::string ipDestino;
        int puertoDestino;
        std::string nombreDestino;

        void print();
        void printDate(); 
};

UserFila::UserFila(std::string f, std::string h, std::string iO, std::string pO, std::string nO, std::string iD, std::string pD, std::string nD)
{
    struct tm tm;
    const char *f = _fecha.c_str();
    strptime(f, "%d-%m-%y", &this->fecha);
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

void UserFila::print()
{
    this->printDate();
    std::cout << "\t" << this->hora 
    << "\t" << this->ipOrigen
    << "\t" << this->puertoOrigen
    << "\t" << this->nombreOrigen
    << "\t" << this->ipDestino
    << "\t" << this->puertoDestino
    << "\t" << this->nombreDestino
    <<std::endl << "=======================" <<std::endl;
}

void UserFila::printDate()
{
    std::cout << this->fecha.tm_mday << "/" << this->fecha.tm_mon + 1 << "/" << this->fecha.tm_year + 1900 << std::endl;
}

#endif /* UserFila_hpp */