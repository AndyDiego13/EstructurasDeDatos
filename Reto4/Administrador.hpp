/*
    Situacion Problema - Ataques Cibernéticos
    Administrador.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/

#ifndef Administrador_hpp
#define Administrador_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "UserFila.hpp"
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;

class Administrador
{
    public:

        
        Administrador(){}
        ~Administrador(){}

        std::vector<UserFila> file()
        {
            std::ifstream f("/Users/andydiego13/Downloads/Requipo7.csv");
            std::vector<UserFila> registros;

            if (!f.is_open())
            {
                std::cout << "Error: File Open" << std::endl;
            }

            std::string fecha;
            std::string hora;
            std::string ipOrigen;
            std::string puertoOrigen;
            std::string nombreOrigen;
            std::string ipDestino;
            std::string puertoDestino;
            std::string nombreDestino;

            while (f.good())
            {
                getline(f, fecha, ',');
                getline(f, hora, ',');
                getline(f, ipOrigen, ',');
                getline(f, puertoOrigen, ',');
                getline(f, nombreOrigen, ',');
                getline(f, ipDestino, ',');
                getline(f, puertoDestino, ',');
                getline(f, nombreDestino, '\n');

                registros.push_back(UserFila(fecha, hora, ipOrigen, puertoOrigen, nombreOrigen, ipDestino, puertoDestino, nombreDestino));
            }

            f.close();
            
            return registros;
        }
};

#endif /* Administrador_hpp */