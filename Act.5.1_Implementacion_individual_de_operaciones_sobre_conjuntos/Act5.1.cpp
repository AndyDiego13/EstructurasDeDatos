
/*
    Actividad 5.1: Implementación de operaciones sobre conjuntos (Técnica de Hashing)

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 24 / 11 /2021

*/

#include <iostream>
#include <map>
#include <vector>
#include <list>
#include "Libro_Act5_1.hpp"
#include "hashSimple.hpp"


int main()
{
    std::cout << "Manejo de desbordamiento por encadenamiento (chain)" << std::endl;

    std::map<int, std::vector<std::string>> personas;

    personas[1].push_back("Lorena");
    personas[5].push_back("Yahir");
    personas[13].push_back("Gabriel");
    personas[24].push_back("Karla");

    for(auto iter = personas.begin(); iter != personas.end(); iter++)
    {
        std::cout << iter->first << ":" <<std::endl;

        for ( std::string per:personas[iter->first])
        {
            std::cout << per << std::endl;
        }
        std::cout << std::endl;
    }

    std::cout << "=== Manejo de desbordamiento lineal (lineal) ===" << std::endl;

    std::map< std::string, Libro> libros;
    libros["1"] = Libro("5","El corazón de las tinieblas",800);
    libros["3"] = Libro("8", "La dama de blanco", 550);
    libros["6"] = Libro("13", "El señor de las moscas", 900);
    libros["8"] = Libro("10", "Perdida", 760);

    for ( auto element : libros)
    {
        std::cout << "ISBN: " << element.first << ", Libro: " << element.second << std::endl;
    }
    
    std::cout << "=== Manejo de desbordamiento por encadenamiento (chain raw) ===" << std::endl;

    int lista[] = {15, 8, 9, 3, 21};
    int n = sizeof(lista)/sizeof(lista[0]);

    hashSimple hs(4);

    for (auto i = 0; i < n; i++)
    {
        hs.insertItem(lista[i]);
    }

    hs.displayHash();

    return 0;
}
