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

    //Dijkstra
    int *dij = new int[g.getSize()];

    dij = g.dijkstra(0);

    std::cout << "\n Shortest path from 0 to \n" << std::endl;

    for (int j = 0; j < g.getSize(); j++)
    {
        std::cout << j + ": " + dij[j] << std::endl;
    }

    std::cout << std::endl;
    
    return 0;
}