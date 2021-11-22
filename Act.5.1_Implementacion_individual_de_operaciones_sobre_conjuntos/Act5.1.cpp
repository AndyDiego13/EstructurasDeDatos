
/*
    Actividad 5.1: Implementación de operaciones sobre conjuntos (Técnica de Hashing)

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 22 / 11 /2021

*/
#include <iostream>
#include "HashMap.hpp"

int main(int argc, const char * argv[]) {
    
    int capacity = 5;
    
    /* Crear un HashMap */
    HashMap<int, int> * tabla = new HashMap<int, int>(capacity);
    
    /* Insertar elementos */
    std::cout << tabla->put(1, 1) << std::endl;
    std::cout << tabla->put(5, 5) << std::endl;
    std::cout << tabla->put(11, 11) << std::endl;
    std::cout << tabla->put(15, 15) << std::endl;
    std::cout << tabla->put(2, 2) << std::endl;
    std::cout << tabla->put(8, 8) << std::endl;
    
    std::cout << tabla->get(5) << std::endl;
    std::cout << tabla->get(15) << std::endl;
    std::cout << tabla->get(8) << std::endl;
    
    std::cout << *tabla;
    
    /* Eliminar la tabla */
    delete tabla;
    
    return 0;
}
