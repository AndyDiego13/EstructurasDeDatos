/*
    Situacion Problema - Ataques Cibernéticos
    Administrador.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

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
            std::ifstream f("equipo7.csv");
            std::vector<UserFila> registros;

            if (!f.is_open())
            {
                std::cout << "Error: File Open" << std::endl;
            }

            std::string fecha;
            std::string hora;
            std::string ip_Origen;
            std::string puertoOrigen;
            std::string nombre_Origen;
            std::string ip_Destino;
            std::string puertoDestino;
            std::string nombre_Destino;

            while (f.good())
            {
                getline(f, fecha, ',');
                getline(f, hora, ',');
                getline(f, ip_Origen, ',');
                getline(f, puertoOrigen, ',');
                getline(f, nombre_Origen, ',');
                getline(f, ip_Destino, ',');
                getline(f, puertoDestino, ',');
                getline(f, nombre_Destino, '\n');

                registros.push_back(UserFila(fecha, hora, ip_Origen, puertoOrigen, nombre_Origen, ip_Destino, puertoDestino, nombre_Destino));
            }

            f.close();
            
            return registros;
        }
};

#endif /* Administrador_hpp */