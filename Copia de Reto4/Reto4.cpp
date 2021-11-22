/*
    Situacion Problema - Ataques Cibernéticos
    Reto4.cpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cwctype>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include "ConexionesComputadora.hpp"
#include "ConexionesAux.hpp"
#include "Date.hpp"
#include "GraphR4.hpp"




/* Imprimir vectores */
void printVector( std::vector<UserFila> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].print();
        std::cout << std::endl;
    }
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

std::set<Date> takeDates(std::vector<UserFila> datos)
{
    std::set<Date> allDates;
    for (int i = 0; i < datos.size(); i++)
    {
        Date d(datos[i].fecha);
        allDates.insert(d);
    }
    return allDates;   
}

bool isInterna(std::string ipInput)
{
    std::string ipBase = "172.22.162.0";

    for (int i = 0; i < 10; i++)
    {
        if (ipBase[i] != ipInput[i])
        {
            return false;
        }
    }
    return true;
}

int computadorasConConexionesEntrantes( std::map< std::string, ConexionesComputadora> computadoras)
{
    int n = 0;
    std::map< std::string, ConexionesComputadora>::iterator it;

    for ( it = computadoras.begin(); it != computadoras.end(); it++)
    {
        if (it->second.nombre.find("reto.com") != std::string::npos && it->second.conexionesEntrantes.size() >= 1)
        {
            n++;
        } 
    }
    return n;
}

std::set< std::string> obtenerIpsEntrantes(std::map< std::string, ConexionesComputadora> computadoras)
{
    std::set<std::string> ipsUnicas;
    std::map< std::string, ConexionesComputadora>::iterator it;

    int n = 0;

    for ( it = computadoras.begin(); it != computadoras.end(); it++)
    {
        if (it->second.nombre.find(".reto.com") == std::string::npos)
        {
            n++;

            std::vector<ConexionesAux> conexionesV{begin(it->second.conexionesEntrantes), end(it->second.conexionesEntrantes)};
            std::set<std::string> nombresPorComputadoraUnicos;

            for (int i = 0; i < conexionesV.size(); i++)
            {
                if (conexionesV[i].puerto != 67)
                {
                    nombresPorComputadoraUnicos.insert(conexionesV[i].conex);
                    ipsUnicas.insert(conexionesV[i].ip);
                }
            }
        }
    }
    return ipsUnicas;
}

std::map< std::string, int> conexionesPorDia(tm date, std::vector<UserFila> datos)
{
    std::map< std::string, int> numeroDeOcurrencias;

    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].fecha.tm_mday == date.tm_mday && datos[i].fecha.tm_mon == date.tm_mon && datos[i].fecha.tm_year == date.tm_year)
        {
            if (datos[i].nombreDestino.find(".reto.com") == std::string::npos && datos[i].nombreDestino.find("-") == std::string::npos)
            {
                numeroDeOcurrencias[datos[i].nombreDestino]++;
            }
        }
    }
    return numeroDeOcurrencias;
}

void printMap(std::map<std::string, int> numeroDeOcurrencias)
{
    std::map< std::string, int>::iterator it;
    for ( it = numeroDeOcurrencias.begin(); it != numeroDeOcurrencias.end(); ++it)
    {
        std::cout << it->first << ":\t" << it->second << std::endl;
    }
}

void fillCompu( std::map< std::string, ConexionesComputadora> &computadoras, std::vector<UserFila> datos)
{
    for (size_t i = 0; i < datos.size(); i++)
    {
        /* Continuar si la ip origen no esta en el map*/
        if ( datos[i].ipOrigen != "-" && computadoras.find(datos[i].ipOrigen) == computadoras.end())
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


void conexionesDiariasGrafos( std::map<Date, Graph<std::string>> &grafosPorDia, std::set<Date> allDates, std::string ipA, std::map<Date, int> &conexionesEntrantesPorDia, std::map<Date, int> &conexionesSalientesPorDia, std::map<std::string, ConexionesComputadora> allCompu)
{
    //Iteramos por día y creamos el grafo
    for ( std::set<Date>::iterator hoy = allDates.begin(); hoy != allDates.end(); ++hoy)
    {
        Graph<std::string> grafoI;

        //Iteramos todas las computadoras para añadir los nodos
        for ( std::map<std::string, ConexionesComputadora>::iterator compu = allCompu.begin(); compu != allCompu.end(); ++compu)
        {
            //Si es interna, añadir al grafo
            if (isInterna(compu->first))
            {
                grafoI.addNode(compu->first);
            }
        }

        //Iteramos todas las computadoras para añadir los edges
        for ( std::map< std::string, ConexionesComputadora>::iterator compu = allCompu.begin(); compu != allCompu.end(); ++compu)
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

bool anomalo(std::string nombre)
{
    if (nombre.size() >= 20)
    {
        return true;
    }

    for (int i = 0; i < nombre.size(); i++)
    {
        if (isalpha(nombre[i]) == false && nombre[i] != '.' && nombre[i] != '.' && nombre[i] != '/')
        {
            return true;
        }
    }
    return false;
}

std::string foundAnomalo( std::map< std::string, ConexionesComputadora> computadoras)
{
    std::map< std::string, ConexionesComputadora>::iterator it;

    for ( it = computadoras.begin(); it != computadoras.end(); ++it)
    {
        if (anomalo(it->second.ip))
        {
            return it->first;
        }
    }
    return "";
}

int main()
{
    Administrador admin;

    std::vector<UserFila> datos = admin.file();

    std::map< std::string, ConexionesComputadora> allCompu;
    fillCompu(allCompu, datos);

    // Ip interna, llamada A, la cual esta en la red interna
    /*
        Betty - 172.22.162.70
    */
    std::string ipInternaA = "172.22.162.70"; 
    ConexionesComputadora A = allCompu[ipInternaA];

    // Sitio con nombre anómalo
    //Los nombres de los sitios raros son: 3jb6992rz5rtdc2id9c5.net y jhntee9opzbxvdv2unkx.net solo que son diferentes ip a la que me salio como anomala

    // Sitio con nombre anómalo
    std::string ipAnomalaB = foundAnomalo(allCompu);
    ConexionesComputadora B = allCompu[ipAnomalaB];
    //std::cout << "\t" << (foundAnomalo(allCompu) != "" ? "Sí." : "No.") << std::endl;
    //std::cout << ipAnomalaB << std::endl;

    //Sitio con mucho tráfico en un dia 
    std::string ipTraficoC = "73.227.113.60"; //fandom
    ConexionesComputadora C = allCompu[ipTraficoC];

    /* 1. Utilizando un grafo con las conexiones entre las ip de la red interna, 
    determina la cantidad de computadoras con las que se ha conectado A por día. 
    ¿Es el vértice que más conexiones salientes tiene hacia la red interna? 
    */

    std::map< Date, Graph< std::string>> grafosPorDia;
    std::set<Date> allDates = takeDates(datos);
    std::map< Date, int> conexionesEntrantesPorDia;
    std::map< Date, int> conexionesSalientesPorDia;

    conexionesDiariasGrafos(grafosPorDia, allDates, ipInternaA, conexionesEntrantesPorDia, conexionesSalientesPorDia, allCompu);
    
    std::cout << "1. Utilizando un grafo con las conexiones entre las ip de la red interna, determina la cantidad de computadoras con las que se ha conectado A por día." << std::endl;
    for ( std::map<Date, int>::iterator it = conexionesSalientesPorDia.begin(); it != conexionesSalientesPorDia.end(); ++it)
    {
        Date hoy = it->first;
        std::cout << hoy.toString() << ":\t" << it->second << std::endl;
    }
    
    std::cout << "¿Es el vértice que más conexiones salientes tiene hacia la red interna?" << std::endl;
    std::map<Date, std::string> maxConexionesDia = maxConexionesPorDia(grafosPorDia);
    vertexMaxConexSalientes(maxConexionesDia, ipInternaA); 
    
    /*
        2. Utilizando el grafo del punto anterior, ubica la cantidad de computadoras que se han conectado hacia A por día. 
        ¿Existen conexiones de las demás computadoras hacia A? 
    */

    std::cout << "Utilizando el grafo del punto anterior, ubica la cantidad de computadoras que se han conectado hacia A por día. ¿Existen conexiones de las demás computadoras hacia A? " << std::endl;
    
    for ( std::map< Date, int>::iterator it = conexionesEntrantesPorDia.begin(); it != conexionesEntrantesPorDia.end(); ++it)
    {
        Date hoy = it->first;
        std::cout << hoy.toString() << ":\t" << it->second << std::endl;
    }
    std::cout << "Sí existen conexiones entrantes a la computadora con ip: " << ipInternaA << std::endl;
    
    /*
        3. Utilizando un grafo de conexiones a sitios web, determina cuántas computadoras se han conectado a B por día. 
    */

   std::map< Date, Graph<std::string>> grafosPorDiaWeb;
   std::map< Date, int> conexionesEntrantesPorDiaWeb;
   conexWebGrafo(grafosPorDiaWeb, allDates, ipAnomalaB, conexionesEntrantesPorDiaWeb, allCompu);
   std::cout << "3.Utilizando un grafo de conexiones a sitios web, determina cuántas computadoras se han conectado a B por día. " << std::endl;
   for ( std::map< Date, int>::iterator it = conexionesEntrantesPorDiaWeb.begin(); it != conexionesEntrantesPorDiaWeb.end(); ++it)
   {
       Date hoy = it->first;
       std::cout << hoy.toString() << ":\t" << it->second << std::endl;
   }

   /*
        4. Utilizando el mismo grafo del punto anterior, indica cuántas computadoras se han conectado a C por día.  
   */
    conexWebGrafo(grafosPorDiaWeb, allDates, ipTraficoC, conexionesEntrantesPorDiaWeb, allCompu);
    std::cout << "4.Utilizando el mismo grafo del punto anterior, indica cuántas computadoras se han conectado a C por día. " << std::endl;
    for ( std::map< Date, int>::iterator it = conexionesEntrantesPorDiaWeb.begin(); it != conexionesEntrantesPorDiaWeb.end(); ++it)
    {
        Date hoy = it->first;
        std::cout << hoy.toString() << ":\t" << it->second << std::endl;
    }
    std::cout << ipAnomalaB << std::endl;
    
    return 0;
}
