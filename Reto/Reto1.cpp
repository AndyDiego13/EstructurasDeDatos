/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include <iostream>
#include "Record.hpp"
#include "Datos.hpp"
#include "BusquedaBinaria.hpp"


int compararPorNombreDestino(Record a, std::string b)
{
    if (a.nombreDestino < b)
    {
        return -1;
    }
    else if(a.nombreDestino == b)
    {
        return 0;
    }
    else
    {
        return 1;
    } 
}

int compararPorNombreOrigen(Record a, Record b)
{
    if(a.nombreOrigen < b.nombreOrigen)
    {
        return -1;
    }
    else if (a.nombreOrigen == b.nombreOrigen)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int main()
{   
    Datos d;

    d.leerDatos("/Users/andydiego13/Downloads/equipo7.csv");
    //d.leerDatos("/Users/andydiego13/Downloads/equipo7.csv");

    //Pregunta 1
    std::cout << "Datos leídos" << std::endl; 
    d.imprimir();


    //Pregunta 2
    // 

    //Pregunta 3
    //std::string a = "jeffrey.reto.com";
    //std::string a = "betty.reto.com";
    //std::string a = "katherine.reto.com";
    //std::string a = "scott.reto.com";
    //std::string a = "benjamin.reto.com";
    //std::string a = "samuel.reto.com";
    //std::string a = "raymond.reto.com";

    //Pregunta 5
    //std::string a = "server.reto.com";

    //Pregunta 6
    std::string a = "freemailserver.com";
    
    int pos = busquedaBinaria(d.conexiones, a,compararPorNombreDestino);
    if(pos != -1)
    {
        std::cout << "Encontrado" << std::endl;
    }
    
    



    return 0;
}

