/*
    "appGrafos.cpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 14/11/2021
*/

#include <iostream>
#include <fstream>
#include "Graph.hpp"
#include "IteratorG.hpp"

int main() 
{
    std::cout << "Grafos: sus representaciones y sus recorridos" << std::endl;

    Graph g;

    //BFT iterator
    std::cout << "Bft Iterator: \n" << std::endl;
    IteratorG *gBftIt = g.createBftIterator(0);

    std::cout << "Next " + gBftIt->next() <<std::endl;

    while (gBftIt->hNext() != 0)
    {
        std::cout << "Next " + gBftIt->next() << std::endl;
    }

    //DFT iterator
    std::cout << "Dft Iterator: \n" << std::endl;
    IteratorG *gDftIt = g.createDftIterator(0);

    std::cout << "Next " + gDftIt->next() << std::endl;

    while (gDftIt->hNext() != 0)
    {
        std::cout << "Next " + gDftIt->next() << std::endl;
    }
    
    return 0;
}