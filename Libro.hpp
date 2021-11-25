/*
    Actividad 5.1: Implementación de operaciones sobre conjuntos (Técnica de Hashing)

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 24 / 11 /2021

*/

#ifndef Libro_hpp
#define Libro_hpp

#include <iostream>

class Libro {

    std::string isbn;
    std::string titulo;
    int paginas;
    
public:
    Libro()
    {
        Libro("sin definir", "sin definir", 0);
    }
    
    Libro(std::string _isbn, std::string _titulo, int _pags) :
    titulo(_titulo), isbn(_isbn), paginas(_pags)
    {
        
    }
    
    ~Libro() {}
    
    friend std::ostream & operator<<(std::ostream &os, const Libro &libro)
    {
        os << libro.isbn << "-" << libro.titulo << "(" << libro.paginas << ")" << std::endl;

        return os;
    }
};


#endif /* Libro_hpp */