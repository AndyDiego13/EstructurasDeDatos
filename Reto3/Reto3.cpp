/*
    Situacion Problema - Ataques Cibernéticos
    Reto3.cpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cwctype>
#include <ctime>
#include <string>

#include "Administrador.hpp"
#include "ConexionesComputadora.hpp"
#include "BSTr.hpp"
#include "Date.hpp"

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

/*
    Contenga una función llamada conexionesPorDia, la cual reciba una fecha (puede ser string, int o un objeto que hayas definido en la primera etapa del reto). 
    Dicha función debe regresar una estructura de tipo map<string, int> de las conexiones entrantes a cada sitio/página que no sea "-" y que no pertenezca al dominio "reto.com". 
    La llave del map será el nombre del sitio y el valor será la cantidad de conexiones entrantes que tuvo el día indicado.
*/
std::map<std::string, int> conexionesPorDia(tm date, std::vector<UserFila> registros)
{
    std::map<std::string, int> numRep;
    for (int i = 0; i < registros.size(); i++)
    {
        if (registros[i].fechaTm.tm_mday == date.tm_mday && registros[i].fechaTm.tm_mon == date.tm_mon && registros[i].fechaTm.tm_year == date.tm_year)
        {
            if (registros[i].nombreDestino.find(".reto.com") == string::npos && registros[i].nombreDestino.find("-") == string::npos )
            {
                numRep[registros[i].nombreDestino]++;
            }
        }
    }
    return numRep;
}

// Imprimir un mapa
void printMap(std::map<std::string, int> numRep)
{
    std::map<std::string,int>::iterator it;
    for (it = numRep.begin(); it != numRep.end(); it++)
    {
        std::cout << it->first << ":\t" << it->second << std::endl;
    }
    
}

/*
    Contenga una función llamada top, la cual recibe un parámetro n de tipo int y una fecha. 
    Esta función debe imprimir los n sitios con más accesos en esa fecha. Para ello, puedes usar la función conexionesPorDia y debes agregar los sitios a un BST utilizando como parámetro de ordenamiento la cantidad de conexiones entrantes
*/
void top(BSTr &arbol, int n, tm date, std::map<std::string, int> &numRep, std::map<std::string, int> &promDaily, std::vector<UserFila> registros)
{
    std::map<std::string, int> conexionesD = conexionesPorDia(date, registros);
    std::map<std::string, int>::iterator it;
    std::map<std::string, int>::iterator i;

    for ( it = conexionesD.begin(); it != conexionesD.end(); ++it)
    {
        arbol.insertNode(it->first, it->second);
    }

    std::cout << "El top " << n << " del día " << date.tm_mday << "/" << date.tm_mon + 1 << "/" << date.tm_year+1900 << " es: " <<std::endl;
    arbol.printKth(n);

    std::map<std::string, int> conexionesTemp;
    arbol.keepKth(n, conexionesTemp);

    for (i = conexionesTemp.begin(); i != conexionesTemp.end(); ++i)
    {
        if (i->second > 1)
        {
            i->second = 1;
        }
        i->second += numRep[i->first];
    }

    arbol.keepKth(n, promDaily);

    for (i = promDaily.begin(); i != promDaily.end(); ++i)
    {
        i->second += conexionesTemp[i->first];
    }
    
    numRep = conexionesTemp;
}


int main()
{
    Administrador admin(read_csv_USERFILA("/Users/andydiego13/Downloads/equipo7.csv"));

    std::vector <UserFila> registros = read_csv_USERFILA (  "/Users/andydiego13/Downloads/equipo7.csv" );

    std::map<std::string, ConexionesComputadora> computadoras;

    //Imprimir top 5 por día
    std::set<Date> allDates = takeDates(registros); 

    std::map<std::string, int> numRep;
    std::map<std::string, int> promDaily;

    for (std::set<Date>::iterator it = allDates.begin(); it != allDates.end(); ++it)
    {
        BSTr tops;
        top(tops, 5, it->date, numRep, promDaily, registros);
        
    }

    std::cout << "1. ¿Existe algún sitio que se mantenga en el top 5 todos los días?" << std::endl;
    std::cout << "Los que se mantuvieron en el top diario: " << std::endl;

    for (std::map<std::string, int>::iterator it = numRep.begin(); it != numRep.end(); ++it)
    {
        if (it->second == allDates.size())
        {
            std::cout << "\t" << it->first << "\t" << it->second << std::endl;
        }
    }

    std::cout << "2. ¿Existe algún sitio que entre al top 5 a partir de un día y de ahí aparezca en todos los días subsecuentes" << std::endl;
    std::cout << "Se mantuvieron en el top 5: " << std::endl;

    for (std::map<std::string, int>::iterator it = numRep.begin(); it != numRep.end(); ++it)
    {
        if (it->second > 1)
        {
            std::cout << "\t" << it->first << "\t : se mantuvo " << it->second << " días" << std::endl;
        } 
    }

    std::cout << "3. ¿Existe algún sitio que aparezca en el top 5 con una cantidad más alta de tráfico que lo normal?" << std::endl;
    std::cout << "Los siguientes sitios tiene más tráfico de lo normal: " << std::endl;

    for ( std::map<std::string, int>::iterator it = promDaily.begin(); it != promDaily.end(); ++it)
    {
        if ((it->second)/allDates.size() > 100)
        {
            std::cout << "\t" << it->first << "\t : " << it->second << std::endl;
        } 
    }
    
    return 0;
}
