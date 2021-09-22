/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include <iostream>
#include "Record.hpp"
#include "Data.hpp"
#include "BusquedaBinaria.cpp"

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
    Datos datos;
    datos.leerDatos("/Users/andydiego13/Downloads/copiadeequipo7.csv");

    //Pregunta 1
    std::cout << "Datos leídos" << std::endl;
    datos.imprimirDatos();

    //Pregunta 2
    // 

    //Pregunta 3
    //Record r("","","jeffrey.reto.com","");
    //Record r("", "", "betty.reto.com", "");
    //Record r("", "", "katherine.reto.com","");
    //Record r("", "", "scott.reto.com", "");
    //Record r("", "", "benjamin.reto.com", "");
    //Record r("","","samuel.reto.com","");
    //Record r("", "", "raymond.reto.com","");

    //Pregunta 5
    //Record r("", "", "server.reto.com","");

    //Pregunta 6
    //Record r("", "", "freemailserver.com","");

    //Record r("","","","999");
    //Record f("","","","1");
    //Record g("","","","55");

    std::string a = "freemailserver.com";

    int pos = busquedaBinaria(datos.conexiones, a, compararPorNombreDestino);

    if (pos != -1)
    {
        std::cout << "Encontrado" << std::endl;
        
    }
    
    



    return 0;
}

