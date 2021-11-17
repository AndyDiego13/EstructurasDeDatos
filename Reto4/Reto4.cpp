/*
    Situacion Problema - Ataques Cibernéticos
    ConexionesComputadora.hpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include "ConexionesComputadora.hpp"
#include "ConexionesAux.hpp"
#include "Date.hpp"
#include "GraphR4.hpp"

/* Imprimir vectores */
void printVector(std::vector<UserFila> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].print();
    }
    std::cout << std::endl;
}

/* Algoritmos de Busqueda (En este caso una Busqueda Secuencial (O(n)) ) */
int busquedaSecuencial(vector<UserFila> d, bool(*condicion)(UserFila r))
{
    for (int i = 0; i < d.size(); i++)
    {
        if (condicion(d[i]))
        {
            return i;
        } 
    }

    return -1;  
}

/* Busqueda Secuencial (sobrecarga) */
int busquedaSecuencial(vector<UserFila> d, bool(*condicion)(UserFila a, UserFila b), UserFila r)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (condicion(d[i],r))
        {
            return i;
        } 
    }
    return -1;  
}

std::set<Date> takeDates(std::vector<UserFila> registros)
{
    std::set<Date> allDates;
    for (int i = 0; i < registros.size(); i++)
    {
        Date d(registros[i].fechaTm);
        allDates.insert(d);
    }
    return allDates;
    
}

bool isInterna(std::string ipInput)
{
    std::string ipBase = "172.22.162.7";

    for (int i = 0; i < 10; i++)
    {
        if (ipBase[i] != ipInput[i])
        {
            return false;
        }
    }
    return true;
}

void conexionesDiariasGrafos( std::map<Date, Graph<std::string>> &grafosPorDia, std::set<Date> allDates, std::string ipA, std::map<Date, int> &conexionesEntrantesPorDia, std::map<Date, int> &conexionesSalientesPorDia, std::map<std::string, ConexionesComputadora> todasLasComputadoras)
{
    //Iteramos por día y creamos el grafo
    for ( std::set<Date>::iterator hoy = allDates.begin(); hoy != allDates.end(); ++hoy)
    {
        Graph<std::string> grafoI;

        //Iteramos todas las computadoras para añadir los nodos
        for ( std::map<std::string, ConexionesComputadora>::iterator compu = todasLasComputadoras.begin(); compu != todasLasComputadoras.end(); ++compu)
        {
            //Si es interna, añadir al grafo
            if (isInterna(compu->first))
            {
                grafoI.addNode(compu->first);
            }
        }

        //Iteramos todas las computadoras para añadir los edges
        for ( std::map< std::string, ConexionesComputadora>::iterator compu = todasLasComputadoras.begin(); compu != todasLasComputadoras.end(); ++compu)
        {
            std::string iIp = compu->first;

            list<ConexionesAux> iConexionesSalientes = compu->second.conexionesSalientes;

            //Iteramos todas las conexiones salientes
            for ( list<ConexionesAux>::iterator conexion = iConexionesSalientes.begin(); conexion != iConexionesSalientes.end(); ++conexion)
            {
                // Si es interna, agregamos conexion
                if (isInterna(conexion->ip))
                {
                    /* code */
                }
                

            }
            
        }
        
        
    }
    
}

