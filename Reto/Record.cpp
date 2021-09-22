/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Record.hpp"

Record::Record(std::string f, std::string h, std::string nO, std::string nD)
{
    fecha = f;
    hora = h;
    nombreOrigen = nO;
    nombreDestino = nD;
}

