/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021

Descripción:

*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "Data.hpp"
#include "Record.hpp"

using namespace std;

void Datos::leerDatos(string path)
{
    std::ifstream fileIn;
    fileIn.open(path); //Con path nos referimos al directorio
        
    std::string line, partes;
    std::vector<std::string> valores;
        
    while(fileIn.good())
    {
        getline(fileIn, line);
        istringstream sIn(line); // Es nuestro separador de comas

        while(getline(sIn, partes, ','))
        {
            valores.push_back(partes);
        }

        //Ya que los datos son generados en Windows, y Windows usa /r/n ponemos el siguiente "if"
        if(valores[7].find('\r') != valores[7].npos)
        {
            valores[7]= valores[7].substr(0, valores[7].size()-1);
        }
        Record r(valores[0], valores[1], valores[4], valores[7]);
        conexiones.push_back(r);
        valores.clear();
    }
}

void Datos::imprimirDatos()
{
    std::cout << "Número de registros en archivo: " << conexiones.size() << std::endl;
}

int Datos::compararPorFecha(Record a, Record b)
{
    if(a.fecha < b.fecha)
    {
        return -1;
    }
    else if(a.fecha == b.fecha)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int Datos::compararPorNombreOrigen(Record a, Record b)
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

int Datos::compararPornNombreDestino(Record a, Record b)
{
    if (a.nombreDestino < b.nombreDestino)
    {
        return -1;
    }
    else if(a.nombreDestino == b.nombreDestino)
    {
        return 0;
    }
    else
    {
        return 1;
    }
    
    
}