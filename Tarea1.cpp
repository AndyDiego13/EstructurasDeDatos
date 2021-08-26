/*
    Actividad 1 - Funciones iterativas, recursivas y su análisis de complejidad
    
    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    26/Agosto/2021

*/
#include <iostream>

using namespace std;

/* Descripción
    Este programa calcula la sumatoria de 1 hasta "n" de manera Iterativa*/

long int sumaIterativa (int n) // El nivel de complejidad es: O(n) (lineal)
{
    long int resultado = 0;

    for (int i = 1; i<= n ; i++)
    {

        resultado = n*(n+1)/2;  
    }

    return resultado;
}

//Esta función es la que va a realizar la suma recursiva, solo tiene un parametro entero "n" regresa el resultado recursivo siendo evaluado por dos condicioneles if
int sumaRecursiva(int n)// El nivel de complejidad es: O(n) (lineal)
{

    if (n == 1)
    {

        return 1;
    }
    else
    {

        return n + sumaRecursiva(n-1);
    }
}

// Esta función es la que va a realizar la suma directa, solo tiene un parametro entero "n" regresa el resultado
long int sumaDirecta (int numero)// El nivel de complejidad es: O(1) (Constante)
{
    int resultado = numero * (numero + 1)/2;
    
    return resultado;
}

int main()
{
    int opcion;
    int n;
    int num;
    int numero;

    do
    {
        std::cout << "------Actividad 1------" << std::endl << std::endl;
        std::cout << "<1> Suma iterativa. " << std::endl;
        std::cout << "<2> Suma recursiva. " << std::endl;
        std::cout << "<3> Suma directa. " << std::endl;
        std::cout << "<0> Salir." << std::endl << std::endl;

        std::cout << "Elige una opcion: " << std::endl;
        std::cin >> opcion;

        switch (opcion)
        {
        case 1:
            std::cout << "Favor de ingresar el número total de datos(n): " << std::endl;
            cin >> n;

            std::cout << "La suma iterativa es: " << sumaIterativa(n) << std::endl;
            
            break;
        case 2:
            std::cout << "Favor de ingresar el número total de datos (n): " << std::endl;
            cin >> num;

            std::cout << "La suma recursiva es: " << sumaRecursiva(num) << std::endl;

            break;
        case 3:
            std::cout << "Favor de ingresar el número total de datos (n): " << std::endl;
            cin >> numero;

            std::cout << "La suma directa es: " << sumaDirecta(numero) <<std::endl;

            break;


        default:
            break;
        }

    } while (opcion != 0 );
    
    
    return 0;
}
