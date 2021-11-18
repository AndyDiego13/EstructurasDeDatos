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
#include <cwctype>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include "ConexionesComputadora.hpp"
#include "ConexionesAux.hpp"
#include "Date.hpp"
#include "GraphR4.hpp"

auto  read_csv_strings(std::string filename)
{
    /* Crear un vector (matriz) de vector de strings (vectores internos o sea filas) donde se guardara cada linea del documento */
    vector <vector <std::string>> lineas;

    /* Crear un flujo de archivos de entrada para leer el archivo CSV, o sea objeti que reciba un input */
    ifstream file(filename);

    /* Lanzar excepción: Verificar si no hubo error al abrir el archivo */
    if (!file.is_open())throw std::runtime_error ( " No se puede abrir el archivo " );

    /* Definir variable que almacena cada línea del archivo */
    std::string linea;
    
    /* Leer datos línea a línea, fila a fila, ESTO SE REALIZA PARA CADA LINEA */
    while ( getline (file, linea,','))
    {
        /* Crear un stream de la línea */
       std::stringstream ss (linea);
    
        /* Variable que almacena cada campo leído, o sea cada columna creo */
        std::string campo;
        
        /* Cada elemento de la columna se agrega un vector, es decir cada fila se vuelve a un vector. Almacenar cada campo */
        vector <std::string> fila;
        
        /* Iterar sobre la línea para extraer cada campo */
        while ( std::getline (ss, campo))
        {
            // se agrega cada elemento al vector de cada fila
            fila.push_back (campo);
        }
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back (fila);
    }

    /* Cerrar el archivo */
    file.close ();

    /* Regresar el vector de líneas leídas */
    return lineas;
}

            
auto  read_csv_USERFILA (std::string filename)
{
    /* Crear un vector de vector de strings */
    vector <UserFila> lineas;

    /* Crear un flujo de archivos de entrada para leer el archivo CSV */
    std::ifstream file(filename);

    /* Verificar si no hubo error al abrir el archivo */
    if (! file.is_open ()) throw  std::runtime_error ( " No se puede abrir el archivo " );

    /* Definir variable que almacena cada línea */
    std :: string linea;
    
    /* Leer datos línea a línea */
    while ( std::getline (file, linea))
    {
        /* Crear un vapor de la línea */
        stringstream ss (linea);
    
        /*  Variables que almacenan cada campo leído */
        std::string f;
        std::string h;
        std::string iO;
        std::string pO;
        std::string nO;
        std::string iD;
        std::string pD;
        std::string nD;
        
        /* Iterar sobre la línea para extraer cada campo */
        getline (ss, f, ',');
        getline (ss, h, ',');
        getline (ss, iO, ',');
        getline (ss, pO,',');
        getline (ss, nO,',');
        getline (ss, iD,',');
        getline (ss, pD,',' );
        getline (ss, nD,',');
        
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back ( UserFila (f, h, iO, pO, nO, iD, pD, nD));
    }

    /* Cerrar el archivo */
    file.close ();

    /* Regresar el vector de líneas leídas */
    return lineas;
}

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
        if (anomalo(it->second.nombre))
        {
            return it->first;
        }
    }
    return "";
}

int main()
{
    Administrador admin(read_csv_USERFILA("/Users/andydiego13/Downloads/equipo7_usar.csv"));

    std::vector<UserFila> datos = read_csv_USERFILA (  "/Users/andydiego13/Downloads/equipo7_usar.csv" );

    std::map< std::string, ConexionesComputadora> allCompu;
    fillCompu(allCompu, datos);

    // Ip interna, llamada A, la cual esta en la red interna
    std::string ipInternaA = "172.22.162.7"; //Betty
    ConexionesComputadora A = allCompu[ipInternaA];

    // Sitio con nombre anómalo
    std::string ipAnomalaB = foundAnomalo(allCompu);
    ConexionesComputadora B = allCompu[ipAnomalaB];



    
    return 0;
}
