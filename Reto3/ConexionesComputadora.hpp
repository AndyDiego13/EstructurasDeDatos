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
#include "ConexionesAux.hpp"

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
       void insertConexionesEntrantes(std::string ip, int puerto, std::string conex, std::string fecha);
       void insertConexionesSalientes(std::string ip, int puerto, std::string conex, std::string fecha);
       
       std::string ultimaConexionEntrante();

       void fill(vector<UserFila> datos);

};

void ConexionesComputadora::insertConexionesEntrantes(std::string ip, int puerto, std::string conex, std::string fecha)
{
    ConexionesAux ca(ip, puerto, conex, fecha);
    conexionesEntrantes.push_front(ca);
}

void ConexionesComputadora::insertConexionesSalientes(std::string ip, int puerto, std::string conex, std::string fecha)
{
    ConexionesAux ca(ip, puerto, conex, fecha);
    conexionesSalientes.push_back(ca);
}

std::string ConexionesComputadora::ultimaConexionEntrante() //Metodo que nos ayudara a obtener la ultima conexión 
{
    return conexionesEntrantes.front().getIp();
}

void ConexionesComputadora::fill(vector<UserFila> datos)
{
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].getIpD() == conexInput.ip)
        {
            conexInput.insertConexionesEntrantes(
                datos[i].ipOrigen,
                datos[i].origenPuerto,
                datos[i].nombreOrigen
            );
        }

        if (datos[i].getIpO() == conexInput.ip)
        {
            conexInput.insertConexionesSalientes(
                datos[i].ipDestino,
                datos[i].destinoPuerto,
                datos[i].nombreDestino
            );
        }
    }
}

#endif // !ConexionesComputadora_hpp
