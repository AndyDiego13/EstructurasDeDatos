/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include <iostream>
#include "Record.hpp"
#include "Data.hpp"
#include "BusquedaBinaria.cpp"

int main(int argc, char const *argv[])
{   
    Datos d;
    d.leerDatos("/Users/andydiego13/Downloads/equipo7.csv");

    //Pregunta 1
    std::cout << "Datos leídos" << std::endl;
    d.imprimirDatos();

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

    Record r("","","","999");
    Record f("","","","1");
    Record g("","","","55");

    //int pos = busquedaBinaria(d.conexiones, g, d.compararPornNombreDestino(f,r));






    return 0;
}

