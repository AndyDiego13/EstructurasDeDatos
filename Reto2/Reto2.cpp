/*
    Situacion Problema - Ataques Cibernéticos
    Reto2.cpp (Viene siendo nuestro main.cpp)
 
    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#include <iostream>
#include <vector>
#include <map>
#include "Administrador.hpp"
#include "UserFila.hpp"
#include "ConexionesComputadora.hpp"
#include <string>

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


std::string ipUsuario;

bool confirmarIp(UserFila uf)
{
    return uf.getIpO() == ipUsuario;
}

//Obtener la ip base
std::string takeIpBase(vector<UserFila> d)
{
    int i = busquedaSecuencial(d,[](UserFila r) {return r.getIpO() != "-";});
    std::string ip = d[i+1].getIpO();
    for (int i = 0; i < 3; i++)
    {
        ip.pop_back();
    }
    ip.append(".0");
    return ip; 
}

std::string takeIpUsuario(std::string base, int usuario)
{
    std::string ipUsuario = base;
    ipUsuario.pop_back();
    ipUsuario.append(std::to_string(usuario));
    return ipUsuario;
}

/*Sirve para preguntar al usuario un numero para poder generar la IP interna correpondiente, según la direccion de red*/

int askNumber(vector<UserFila> datos)
{ 
    std::string ipBase = takeIpBase(datos);
    int direcUsuario;

    while (direcUsuario < 1 || direcUsuario > 150)
    {
        std::cout << "Ingresa un numero entre 1 y 150" << std::endl;
        std::cin >> direcUsuario;
    }

    ipUsuario = takeIpUsuario(ipBase, direcUsuario);
    int usuarioIndex = busquedaSecuencial(datos, *confirmarIp);
    
    if(usuarioIndex == -1)
    {
        return askNumber(datos);
    }

    return usuarioIndex; 
}

void fill(vector<UserFila> datos, ConexionesComputadora &conexInput)
{
    for (int i = 0; i < datos.size(); i++)
    {
        if (datos[i].getIpD() == conexInput.ip)
        {
            conexInput.insertConexionesEntrantes(
                datos[i].ipOrigen,
                datos[i].origenPuerto,
                datos[i].nombreOrigen
            );
        }

        if (datos[i].getIpO() == conexInput.ip)
        {
            conexInput.insertConexionesSalientes(
                datos[i].ipDestino,
                datos[i].destinoPuerto,
                datos[i].nombreDestino
            );
        }
    }
}

bool interna(std::string ipBase, std::string ipInput)
{
    for (int i = 0; i < 10; i++)
    {
        if (ipBase[i] != ipInput[i])
        {
            return false;
        } 
    }
    return true;
}

bool tresSeguidas(ConexionesComputadora &conexInput)
{
    auto conx1 = conexInput.conexionesSalientes.begin();
    auto conx2 = std::next(conx1, 1);
    auto conx3 = std::next(conx2, 1);

    for (int i = 0; i < conexInput.conexionesSalientes.size() -3; i++)
    {
        if (conx1 -> getIp() == conx2 -> getIp() && conx2->getIp() == conx3->getIp())
        {
            return true;
        }
        conx1 = std::next(conx1, 1);
        conx2 = std::next(conx2, 1);
        conx3 = std::next(conx3, 1); 
    }

    return false;  
}

int main()
{
    Administrador admin (read_csv_USERFILA("/Users/andydiego13/Downloads/equipo7_usar.csv"));

    vector <UserFila> registros = read_csv_USERFILA (  "/Users/andydiego13/Downloads/equipo7_usar.csv" );

    int usuarioIndex = askNumber(registros);
    std::string ipBase = takeIpBase(registros);

    std::string nombreUsuario = registros[usuarioIndex].nombreOrigen;

    ConexionesComputadora conexUsuario = ConexionesComputadora(ipUsuario, nombreUsuario);
    std::cout << "La ip interna es: " << conexUsuario.ip << std::endl;

    fill(registros, conexUsuario);

    std::cout << std::endl;

    /* La conexion conocida que estamos usando para resolver las preguntas es la de betty*/
    ConexionesComputadora compuConocida = ConexionesComputadora("172.22.162.7","betty.reto.com");
    fill(registros, compuConocida);

    /* Pregunta 1 */
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "¿Qué dirección IP estás usando?" << std::endl;
    std::cout << "Se está utilizando la dirección ip: " << compuConocida.ip << std::endl;

    /* Pregunta 2 */
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "¿Cuál fue la dirección IP de la última conexión que recibió esta computadora?" << std::endl;
    std::string ultimaConex = compuConocida.ultimaConexionEntrante();
    std::cout << "La IP de la última conexión que recibio esta computadora es: " << ultimaConex << std::endl;
    std::cout << "¿Es interna o externa?" << std::endl;
    std::cout << "\t"<< (interna(ipBase, ultimaConex) ? "Es interna" : "Es externa") << std::endl;

    /* Pregunta 3 */
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std::cout << "¿Cuántas conexiones entrantes tiene esta computadora?" << std:: endl;
    std::cout << "Esta computadora tiene " << compuConocida.conexionesEntrantes.size() << " conexiones entrantes." <<std::endl;

    /* Pregunta 4 */
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std:: cout << "¿Cuántas conexiones salientes tiene esta computadora?" << std:: endl;
    std:: cout << "Esta computadora tiene " << compuConocida.conexionesSalientes.size() << " conexiones salientes." << std::endl;

    /* Pregunta 5 (Extra) */
    std::cout << "-------------------------------------------------------------------------" << std::endl;
    std:: cout << "¿Tiene esta computadora 3 conexiones seguidas a un mismo sitio web?" << std::endl;
    std:: cout << "\t" << (tresSeguidas(compuConocida) ? "Si tiene tres conexiones seguidas" : "No tiene tres conexiones seguidas") << std:: endl;
      
    return 0;
}
