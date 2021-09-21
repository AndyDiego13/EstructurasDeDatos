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

    std::cout << "Datos leídos" << std::endl;
    d.imprimirDatos();

    Record r("","","jeffrey.reto.com","");
    Record r("", "", "betty.reto.com", "");



    return 0;
}

