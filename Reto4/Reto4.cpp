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

void fillCompu( std::map< std::string, ConexionesComputadora> &computadoras, std::vector<UserFila> datos)
{
    for (size_t i = 0; i < datos.size(); i++)
    {
        /* Continuar si la ip origen no esta en el map*/
        if ( datos[i].ipOrigen != "-" && computadoras.find(datos[i].ipOrigen))
        {
            ConexionesComputadora cc(datos[i].ipOrigen, datos[i].nombreOrigen);
            cc.fill(datos);
            computadoras.insert(std::pair< std::string, ConexionesComputadora> (datos[i].ipOrigen,cc));
        }
        //Continuar si la ip destino no esta en el map
        if ( datos[i].ipDestino != "-" && computadoras.find(datos[i].ipDestino) == computadoras.end())
        {
            ConexionesComputadora cc(datos[i].ipDestino, datos[i].nombreDestino);
            cc.fill(datos);
            computadoras.insert( std::pair< std::string, ConexionesComputadora> (datos[i].ipDestino, cc));
        }
    }
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
                if (isInterna(conexion->ip) && (conexion->fechaTm == *hoy))
                {
                    grafoI.addEdgeElement(iIp, conexion->ip);

                    if (conexion->ip == ipA)
                    {
                        conexionesEntrantesPorDia[*hoy]++;
                    }
                    if (iIp == ipA)
                    {
                        conexionesSalientesPorDia[*hoy]++;
                    }
                }
            }
        }
        grafosPorDia[*hoy] = grafoI; 
    }
}

/* Obtener Ip con más conexiones por día*/
std::map< Date, std::string> maxConexionesPorDia( std::map< Date, Graph< std::string>> grafosPorDia)
{
    std::map< Date, std::string> maxConexionesPorDia;

    for ( std::map< Date, Graph< std::string>>::iterator it = grafosPorDia.begin(); it != grafosPorDia.end(); ++it)
    {
        Graph< std::string> grafoHoy = it->second;

        std::map< std::string, int> numeroConex = grafoHoy.saveVeci();
        std::string ipMaxConex = "";
        int maxConex = 0;

        //Iteramos ips en un mapa con la cantidad de ocurrencias diarias
        for ( std::map< std::string, int>::iterator ips = numeroConex.begin(); ips != numeroConex.end(); ++ips) 
        {
            if (ips->second >= maxConex)
            {
                ipMaxConex = ips->first;
                maxConex = ips->second;
            }
        }
        maxConexionesPorDia[it->first] = ipMaxConex; 
    }
    return maxConexionesPorDia;
}

void vertexMaxConexSalientes( std::map< Date, std::string> maxConexionesPorDia, std::string ipA)
{
    for ( std::map< Date, std::string>::iterator it = maxConexionesPorDia.begin(); it != maxConexionesPorDia.end(); ++it)
    {
        Date hoy = it->first;
        std::cout << hoy.toString() << ":\t" << (it->second == ipA ? "Si" : "No") << std::endl;
    } 
}

bool web(ConexionesAux ca)
{
    if (ca.puerto == 443)
    {
        return true;
    }
    return false;
}

void conexWebGrafo( std::map< Date, Graph< std::string>> &grafosPorDiaWeb, std::set<Date> allDates, std::string ipI, std::map< Date, int> &conexEntrantesPorDiaWeb, std::map< std::string, ConexionesComputadora> allCompu)
{
    for ( std::set<Date>::iterator hoy = allDates.begin(); hoy != allDates.end(); ++hoy)
    {
        Graph< std::string> grafoI;
        conexEntrantesPorDiaWeb[*hoy] = 0;

        //iteramos todas las computadoras para añadir los nodos
        for ( std::map< std::string, ConexionesComputadora>::iterator compu = allCompu.begin(); compu != allCompu.end(); ++compu)
        {
            grafoI.addNode(compu->first);
        }
        //Iteramos todas las computadoras para añadir los edges
        for ( std::map< std::string, ConexionesComputadora>::iterator compu = allCompu.begin(); compu != allCompu.end(); ++compu)
        {
            std::string iIp = compu->first;
            list<ConexionesAux> iConexSalientes = compu->second.conexionesSalientes;

            //Iteramos todas las conexiones salientes y si es web se agrega a conexion
            for ( list<ConexionesAux>::iterator conexion = iConexSalientes.begin(); conexion != iConexSalientes.end(); ++conexion)
            {
                if ( web(*conexion) && (conexion->fechaTm == *hoy))
                {
                    grafoI.addEdgeElement(iIp, conexion->ip);

                    if (conexion->ip == ipI)
                    {
                        conexEntrantesPorDiaWeb[*hoy]++;
                    }
                }
            }
        }
        grafosPorDiaWeb[*hoy] = grafoI;
    }
}

int main()
{
    Administrador ad;
    std::vector< UserFila> datos = ad.read_fila();
    std::map< std::string, ConexionesComputadora> allCompu;
    fillCompu(allCompu, datos);

    
    return 0;
}
