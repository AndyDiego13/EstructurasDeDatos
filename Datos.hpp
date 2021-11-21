/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Record.hpp"

using namespace std;

class Datos
{
    public:
    std::string path;
    std::vector<Record> conexiones;
    Datos(){};
    //~Datos() = default;

    void leerDatos(std::string path)
    {
        std::ifstream fileIn;
        fileIn.open(path); //path es el directorio

        std::string line, partes;
        std::vector<std::string> valores;
        


        while(fileIn.good())
        {
            getline(fileIn, line);
            istringstream sIn(line); //separador de comas

            while(getline(sIn, partes, ','))
            {

                valores.push_back(partes);
            }
            //como los datos son generados en windows y windows usa /r/n ponemos este if 
            if(valores[7].find('\r')!= valores[7].npos)
            {
                valores[7] = valores[7].substr(0, valores[7].size()-1);
            }
            Record r(valores[0], valores[1], valores[2], valores[3],valores[4], valores[5], valores[6], valores[7]);
            conexiones.push_back(r);
            valores.clear();
        }
    }

    void imprimir()
    {
        std::cout << "Número de registros en archivo: " << conexiones.size() << std::endl;
    }

    int compararPorFecha(Record a, Record b)
	{
		if(a.fecha < b.fecha)
		{
			return -1;
		}
		else if (a.fecha == b.fecha)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

    int compararPorNombreFuente(Record a, Record b)
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

    int compararPorNombreDestino(Record a, Record b)
	{
		if(a.nombreDestino < b.nombreDestino)
		{
			return -1;
		}
		else if (a.nombreDestino == b.nombreDestino)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}	
};