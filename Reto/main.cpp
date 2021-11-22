/* main.cpp
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 23/09/2021
*/
#include <iostream>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include <string>
#include <iterator>
#include <map>

std::map< std::string, int> mails;
std::map<int, int> puertos;

/* Imprimir vectores */
void printVector( std::vector<UserFila> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i].print();
        std::cout << std::endl;
    }
}

/* Búsqueda Secuencial */
int busquedaSecuencial( std::vector<UserFila> d, bool (*condicion)(UserFila r))
{
    for (int i = 0; i < d.size(); i++)
    {
        if (condicion(d[i], r))
        {
            return i;
        }
    }
    return -1;
}

/* Búsqueda Secuencial Sobrecarga */
int busquedaSecuencial( std::vector<UserFila> d, bool (*condicion)(UserFila a, UserFila b), UserFila r)
{
    for (int i = 0; i < d.size(); i++)
    {
        if (condicion(d[i], r))
        {
            return i;
        }
    }
    return -1;
}

/* Búsqueda Binaria */
int busquedaBinaria( std::vector<UserFila> d, bool (*condicion)(UserFila r), int inicio, int final)
{
    int med = inicio + (final - inicio)/2;

    if (final <= inicio)
    {
        return -1;
    }
    if (condicion(d[med]))
    {
        return med;
    }
    int izq = busquedaBinaria(d, *condicion, inicio, med-1);

    if (izq != -1)
    {
        return izq;
    }

    int der = busquedaBinaria(d, *condicion, med+1, final);

    if (der != -1)
    {
        return der;
    }
    
    return -1;
}

bool esPosterior(UserFila a, UserFila b)
{
    return (
        a.fecha.tm_mday > b.fecha.tm_mday &&
        a.fecha.tm_mon >= b.fecha.tm_mon &&
        a.fecha.tm_year >= b.fecha.tm_year
    );
}

bool perteneceA(UserFila r)
{
    return(
        r.nombreOrigen == "amy.reto.com" ||
        r.nombreOrigen == "anna.reto.com" ||
        r.nombreOrigen == "betty.reto.com" ||
        r.nombreOrigen == "catherine.reto.com" ||
        r.nombreOrigen == "charles.reto.com" ||
        r.nombreOrigen == "christopher.reto.com" ||
        r.nombreOrigen == "cynthia.reto.com" ||
        r.nombreOrigen == "david.reto.com" ||
        r.nombreOrigen == "dennis.reto.com" ||
        r.nombreOrigen == "emma.reto.com" ||
        r.nombreOrigen == "george.reto.com" ||
        r.nombreOrigen == "jack.reto.com" ||
        r.nombreOrigen == "james.reto.com" ||
        r.nombreOrigen == "janet.reto.com" ||
        r.nombreOrigen == "jason.reto.com" ||
        r.nombreOrigen == "jerry.reto.com" ||
        r.nombreOrigen == "kathleen.reto.com" ||
        r.nombreOrigen == "kevin.reto.com" ||
        r.nombreOrigen == "kimberly.reto.com" ||
        r.nombreOrigen == "mark.reto.com" ||
        r.nombreOrigen == "michelle.reto.com" ||
        r.nombreOrigen == "nicole.reto.com" ||
        r.nombreOrigen == "rachel.reto.com" ||
        r.nombreOrigen == "raymond.reto.com" ||
        r.nombreOrigen == "scott.reto.com" ||
        r.nombreOrigen == "stephanie.reto.com"

    );
}

bool callServer(UserFila r)
{
    return r.nombreOrigen == "server.reto.com" || r.nombreDestino == "server.com";
}

bool correo(UserFila r)
{
    if (r.puertoDestino == 993)
    {
        mails[r.nombreDestino]++;
    }
    return false;
}

bool puerto(UserFila r)
{
    if (r.puertoDestino < 1000 && r.puertoDestino > 0)
    {
        puertos[r.puertoDestino]++;
    }
    return false;
}

std::string obtenerIpBase( std::vector<UserFila> d)
{
    int i = busquedaSecuencial(d, [](UserFila r) {return r.ipOrigen != "-";});
    std::string ip = d[i+1].ipOrigen;

    for (int i = 0; i < 3; i++)
    {
        ip.pop_back();
    }
    
    ip.append(".0");
    return ip;
}

int main()
{
    Administrador admin;
    std::vector<UserFila> datos = admin.file();

    std::cout << "1. ¿Cuántos registros tiene tu archivo?" << std::endl
    << "El archivo tiene " << datos.size() << " registros." << endl << endl;

    std::cout << "2. " << std::endl;
   

   
    
    return 0;
}   













