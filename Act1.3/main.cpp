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
    while ( getline (file, linea))
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
        getline (ss, f );
        getline (ss, h );
        getline (ss, iO );
        getline (ss, pO );
        getline (ss, nO );
        getline (ss, iD );
        getline (ss, pD );
        getline (ss, nD );
        
        
        /* Insertar la fila con los campos separados en un vector */
        lineas.push_back ( UserFila (f, h, iO, pO, nO, iD, pD, nD));
    }

    /* Cerrar el archivo */
    file.close ();

    /* Regresar el vector de líneas leídas */
    return lineas;
}


int main()
{
   

    Administrador admin ( read_csv_USERFILA ( "/Users/diego/OneDrive/Documentos/Tareas o trabajos de la escuela/TEC/Tercer Semestre/Programación de Estructura de Datos y Algoritmos Fundamentales/Act 1.3 (Def)/equipo7.csv " ));
    
    vector <UserFila> registros = read_csv_USERFILA ( "/Users/diego/OneDrive/Documento/Tareas o trabajos de la escuela/TEC/Tercer Semestre/Programación de Estructura de Datos y Algoritmos Fundamentales/Act 1.3 (Def)/equipo7.csv " );

    /*Administrador ad;
    ad.contarRegistros(); */
}













