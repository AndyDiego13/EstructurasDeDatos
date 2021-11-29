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
        if (condicion(d[i]))
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
        r.nombreOrigen == "jeffrey.reto.com" ||
        r.nombreOrigen == "betty.reto.com" ||
        r.nombreOrigen == "katherine.reto.com" ||
        r.nombreOrigen == "scott.reto.com" ||
        r.nombreOrigen == "benjamin.reto.com" ||
        r.nombreOrigen == "samuel.reto.com" ||
        r.nombreOrigen == "raymond.reto.com"
    );
}

bool callServer(UserFila r)
{
    return r.nombreOrigen == "server.reto.com" || r.nombreDestino == "server.com";
}

bool correo(UserFila r)
{
    if (r.puerto_Destino == 993)
    {
        mails[r.nombreDestino]++;
    }
    return false;
}

bool puerto(UserFila r)
{
    if (r.puerto_Destino < 1000 && r.puerto_Destino > 0)
    {
        puertos[r.puerto_Destino]++;
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

int main(void)
{
    Administrador admin;
    std::vector<UserFila> datos = admin.file();

    std::cout << "1. ¿Cuántos registros tiene tu archivo?" << std::endl
    << "El archivo tiene " << datos.size() << " registros." << endl << endl;

    std::cout << "2. ¿Cuántos récords hay del segundo día registrado? ¿Qué día es?" << std::endl;
    int primerDiaCount = busquedaSecuencial(datos, *esPosterior, datos[0]);
    int segundoDiaCount = busquedaSecuencial(datos, *esPosterior, datos[primerDiaCount]) - primerDiaCount;

    std::cout << "En el primer día (" << std::endl;
    datos[0].printDate();
    std::cout << ") hubieron " << primerDiaCount << "datos" << std::endl;

    std::cout << "En el segundo día (" << std::endl;
    datos[segundoDiaCount].printDate();
    std::cout << ") hubieron " << segundoDiaCount << "  datos." << std::endl << std::endl;

    std::cout << "3. ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?" << std::endl;
    int perteneceCount = busquedaSecuencial(datos, *perteneceA);
    std::cout << ( perteneceCount == 0 ? "No." : "Sí.") << std::endl;

    std::cout << "4. ¿Cuál es la dirección de la red interna de la compañía? " << std::endl;
    std::cout << "La direccion de la red interna es: " << obtenerIpBase(datos)<< std::endl;

    std::cout << "5. ¿Alguna computadora se llama server.reto.com? " << std::endl;
    int serverCount = busquedaSecuencial(datos, *callServer);
    std::cout << (serverCount < 0 ? "No." : "Sí.") << std::endl;

    std::cout << "6. ¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)?" << std::endl;
    int mailCount = busquedaSecuencial(datos, *correo);
    std::cout << "Mail" << "\t" << "Cantidad" << "\n" << std::endl;
    for ( const auto &z : mails)
    {
        std::cout << z.first << "\t" << z.second <<  "\n" <<std::endl;
    }
    
    std::cout << "7. Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente" << std::endl;
    int puertoCount = busquedaSecuencial(datos, *puerto);
    std::cout << "Puerto" << " \t" << "Cantidad" << "\n" << std::endl;
    for ( const auto &x : puertos)
    {
        std::cout << x.first << " \t" << x.second << "\n" << std::endl;
    }

    return 0;
}   













