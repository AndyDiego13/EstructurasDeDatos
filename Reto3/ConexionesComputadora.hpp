/*
    Situacion Problema - Ataques Cibernéticos
    ConexionesComputadora.hpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#ifndef ConexionesComputadora_hpp
#define ConexionesComputadora_hpp

#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "ConexionesAux.hpp"
#include "UserFila.hpp"

class ConexionesComputadora //Nuestra clase principal de conexiones entre las computadoras
{
    public:
        std::string ip;
        std::string nombre;
        std::list<ConexionesAux> conexionesEntrantes; //Decidimos manejar a "ConexionesEntrantes" como un lista
        std::list<ConexionesAux> conexionesSalientes; //Decidimos manejar a "ConexionesSalientes" como un lista

        ConexionesComputadora(std::string ip, std::string nombre)
        {
            this -> ip = ip;
            this -> nombre = nombre;
        }

        ~ConexionesComputadora() {}; //Destructor
        
        /* Funciones insertar conexiones del reto 2
        void insertConexionesEntrantes(std::string ip, int puerto, std::string conex);
        void insertConexionesSalientes(std::string ip, int puerto, std::string conex);
        */

       /* Funciones insertar conexiones para el reto 3*/
       void insertConexionesEntrantes(std::string ip, int puerto, std::string conex, tm fechaTm);
       void insertConexionesSalientes(std::string ip, int puerto, std::string conex, tm fechaTm);
       
       std::string ultimaConexionEntrante();

       void fill(std::vector<UserFila> datos);

};

void ConexionesComputadora::insertConexionesEntrantes(std::string ip, int puerto, std::string conex, tm fechaTm)
{
    ConexionesAux ca(ip, puerto, conex, fechaTm);
    conexionesEntrantes.push_front(ca);
}

void ConexionesComputadora::insertConexionesSalientes(std::string ip, int puerto, std::string conex, tm fechaTm)
{
    ConexionesAux ca(ip, puerto, conex, fechaTm);
    conexionesSalientes.push_back(ca);
}

std::string ConexionesComputadora::ultimaConexionEntrante() //Metodo que nos ayudara a obtener la ultima conexión 
{
    return conexionesEntrantes.front().getIp();
}

void ConexionesComputadora::fill(std::vector<UserFila> datos)
{
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].ip_Destino == this->ip)
        {
            this->insertConexionesEntrantes(
                datos[i].ip_Origen,
                datos[i].puerto_Origen,
                datos[i].nombre_Origen,
                datos[i].fecha
            );
        }

        if (datos[i].ip_Origen == this->ip)
        {
            this->insertConexionesSalientes(
                datos[i].ip_Destino,
                datos[i].puerto_Destino,
                datos[i].nombre_Destino,
                datos[i].fecha
            );
        }
    }
}

#endif // !ConexionesComputadora_hpp
