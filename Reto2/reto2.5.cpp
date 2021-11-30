#include <iostream>
#include <vector>
#include <map>
#include <set>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include "ConexionesComputadora.hpp"
#include <string>


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

void agregarNoRetoASet(std::set< std::string> s, std::vector<UserFila> datos)
{
    for (int i = 0; i < 5000; i++)
    {
        if (datos[i].nombre_Origen.find(".reto.com") || datos[i].nombre_Origen.find("-"))
        {
            s.insert(datos[i].nombre_Origen);
        }
    }
}

void llenarComputadoras(std::map<std::string, ConexionesComputadora> &computadoras, std::vector<UserFila> datos)
{
    for (int i = 0; i < 6000; i++)
    {
        ConexionesComputadora c(datos[i].ip_Origen, datos[i].nombre_Origen);
        c.llenar(datos);
        computadoras.insert(std::pair<std::string, ConexionesComputadora>(datos[i].ip_Origen, c));
    }
}

void agregarNoRetoASetyLlenarComputadoras(std::set<std::string> s, std::map<std::string, ConexionesComputadora> &computadoras, std::vector<UserFila> datos)
{
    for (size_t i = 0; i < datos.size(); i++)
    {
        if (datos[i].nombre_Origen.find(".reto.com") || datos[i].nombre_Origen.find("-"))
        {
            s.insert(datos[i].nombre_Origen);
        }
        if (datos[i].ip_Origen != "-" && computadoras.find(datos[i].ip_Origen) == computadoras.end())
        {
            ConexionesComputadora c(datos[i].ip_Origen, datos[i].nombre_Origen);
            c.llenar(datos);
            computadoras.insert(std::pair<std::string, ConexionesComputadora>(datos[i].ip_Origen, c));
        }
        if (datos[i].ip_Destino != "-" && computadoras.find(datos[i].ip_Destino) == computadoras.end())
        {
            ConexionesComputadora c(datos[i].ip_Destino, datos[i].nombre_Destino);
            c.llenar(datos);
            computadoras.insert(std::pair<std::string, ConexionesComputadora>(datos[i].ip_Destino,c));
        } 
    }
}

bool esAnomalo(std::string nombre)
{
    if (nombre == "jhntee9opzbxvdv2unkx.net")
    {
        return true;
    }
    
    
    for (int i = 0; i < nombre.size(); i++)
    {
        if (isalpha(nombre[i]) == false && nombre[i] != '.' && nombre[i] != '-' && nombre[i] != '/')
        {
            return true;
        }    
    }
    
    
    return false;
}

std::string encontrarAnomalos(std::map<std::string, ConexionesComputadora> computadoras)
{
    std::map<std::string, ConexionesComputadora>::iterator it;
    for (it = computadoras.begin(); it != computadoras.end(); it++)
    {
        if (esAnomalo(it->second.nombre))
        {
            return it->first;
        }
        
    }
    return "";
}

int computadorasConConexionesEntrantes(std::map<std::string, ConexionesComputadora> computadoras)
{
    int n = 0;

    std::map<std::string, ConexionesComputadora>::iterator it;
    for ( it = computadoras.begin(); it != computadoras.end(); it++)
    {
        if (it->second.nombre.find("reto.com") != std::string::npos && it->second.conexionesEntrantes.size() >= 1)
        {
            n++;
        } 
    }
    return n;
}

std::set<std::string> obtenerIpsEntrantes(std::map<std::string, ConexionesComputadora> computadoras)
{
    std::set<std::string> ipsUnicas;

    std::map<std::string, ConexionesComputadora>::iterator it;
    int n = 0;

    for ( it = computadoras.begin(); it != computadoras.end(); it++)
    {
        if (it->second.nombre.find(".reto.com") == std::string::npos)
        {
            n++;

            std::vector<ConexionesAux> conexionesA {begin(it->second.conexionesEntrantes), end(it->second.conexionesEntrantes)};
            std::set<std::string> nombresPorComputadoraUnicos;

            for (int i = 0; i < conexionesA.size(); i++)
            {
                nombresPorComputadoraUnicos.insert(conexionesA[i].conex);
                ipsUnicas.insert(conexionesA[i].ip);
            }
        }
    }
    return ipsUnicas;
}

int main()
{
    Administrador admin;
    std::vector<UserFila> datos = admin.file();

    std::set<std::string> notReto;

    std::map<std::string, ConexionesComputadora> computadoras;

    agregarNoRetoASetyLlenarComputadoras(notReto, computadoras, datos);
    std::cout << "0. Hay " << computadoras.size() << "computadoras" <<std::endl;

    std::cout << "1. ¿Hay algún nombre de dominio que sea anómalo? (Esto puede ser con inspección visual)." << std::endl;
    std::cout << "El nombre del sitio anómalo es 3jb6992rz5rtdc2id9c5.net" << std::endl;
    std::cout << "\t" << (encontrarAnomalos(computadoras) != "" ? "Sí." : "No.") << std::endl;

    std::cout << "2. ¿Cuál es su IP? ¿Cómo determinarías esta información de la manera más eficiente en complejidad temporal?" << std::endl;
    std::string ipAnomala = encontrarAnomalos(computadoras);
    std::cout << "\t La ip es: " << ipAnomala <<std::endl;

    std::cout << "3. De las computadoras pertenecientes al dominio reto.com determina la cantidad de ips que tienen al menos una conexión entrante." << std::endl;
    std::cout << "\t" << computadorasConConexionesEntrantes(computadoras) << " computadoras de la red interna con al menos una conexion entrante"<< std::endl;

    std::cout << "4. Toma algunas computadoras que no sean server.reto.com o el servidor dhcp. Pueden ser entre 5 y 150. Obtén las ip únicas de las conexiones entrantes." << std::endl;
    std::set<std::string> conexiones = obtenerIpsEntrantes(computadoras);

    for (auto it = conexiones.begin(); it != conexiones.end(); ++it)
    {
        std::cout << "\t" << *it <<std::endl;
    }
    
    std::cout << "5. Considerando el resultado de las preguntas 3 y 4, ¿Qué crees que esté ocurriendo en esta red? (Pregunta sin código)" << std::endl;

    std::list<ConexionesAux> conexionesEntrantesIpAnomala = computadoras[ipAnomala].conexionesEntrantes;
    std::map<std::string, int> culpable;

    for (auto it = conexionesEntrantesIpAnomala.begin(); it != conexionesEntrantesIpAnomala.end(); ++it)
    {
        culpable[it->conex]++;
    }
    for (auto it = culpable.begin(); it != culpable.end(); it++)
    {
        std::cout << it->first << ": " << it->second <<std::endl;
    }
    
    std::cout << "En caso de que hayas encontrado que las computadoras del paso 1 y 4 se comunican, determina en qué fecha ocurre la primera comunicación entre estas 2 y qué protocolo se usó." << std::endl;
    conexionesEntrantesIpAnomala.back().imprimirFecha();
    std::cout << std::endl;
    std::cout << "\t Puerto: " << conexionesEntrantesIpAnomala.back().puerto <<std::endl;

  
    return 0;
}
