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


int main()
{
   

    Administrador admin ( read_csv_USERFILA ( "/Users/andydiego13/Downloads/Requipo7.csv" ));
    
    vector <UserFila> registros = read_csv_USERFILA (  "/Users/andydiego13/Downloads/Requipo7.csv" );

    //Pregunta 1
    admin.contarRegistros();

    //Pregunta 2 aparece 0
    std::cout << "Pregunta 2: ¿Cuantos registros hay en el segundo dia?" << std::endl;
    std::cout << admin.contarXdia("11-8-2020") << std::endl;

    /*Pregunta 3*/
    std::cout << "Pregunta 3: ¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond?" << std::endl;

    std::cout << "Busqueda para Jeffrey" << std::endl;
    admin.busqNombre("jeffrey");

    std::cout << "Busqueda para Betty" << std::endl;
    admin.busqNombre("betty");

    std::cout << "Busqueda para Katherine" << std::endl;
    admin.busqNombre("katherine");

    std::cout << "Busqueda para Scott" << std::endl;
    admin.busqNombre("scott");

    std::cout << "Busqueda para Benjamin" << std::endl;
    admin.busqNombre("benjamin");

    std::cout << "Busqueda para Samuel" << std::endl;
    admin.busqNombre("samuel");

    std::cout << "Busqueda para Raymond" << std::endl;
    admin.busqNombre("raymond");
    

    /*Pregunta 4*/

    std::cout << "Pregunta 4: ¿Cuál es la dirección de la red interna de la compañía?" << std::endl;
    admin.busqRedInterna();
    admin.busqNombreIp(registros);

    //Pregunta 5

    std::cout << "Pregunta 5: Busqueda para computadora: server.reto.com" << std::endl;
    admin.busqNombre("server");

    //Pregunta 6
    std::cout << "Pregunta 6: ¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)?" << std::endl;
    
    admin.mostrarMail();
    admin.busqNombreMail("freemailserver");
    admin.busqNombreMail("gmail");
    admin.busqNombreMail("hotmail");
    admin.busqNombreMail("outlook");
    admin.busqNombreMail("protonmail");
    admin.busqNombreMail("mail.yahoo");
    
    

    //Pregunta 7
    std::cout << "Pregunta 6: Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? Lista los puertos e investiga qué aplicación/servicio lo utiliza generalmente." << std::endl;
    admin.mostrarRangoPuertosD(0,1000);

   
    
    return 0;
}   













