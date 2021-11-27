/*
    "appGrafos.cpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 14/11/2021
*/

#include <iostream>
#include <fstream>
#include <vector>
#include "Graph.hpp"
#include "GraphVertex.hpp"
#include "NodeAG.hpp"

int main() 
{
    std::cout << "Grafos: sus representaciones y sus recorridos" << std::endl;

    /*loadGraph */
    
    Graph<std::string> graph;

    graph.addNode("A");
    graph.addNode("B");
    graph.addNode("C");
    graph.addNode("D");
    graph.addNode("E");
    graph.addNode("F");
    graph.addNode("G");
    graph.addNode("H");

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(3, 6);
    graph.addEdge(5, 6);
    graph.addEdge(5, 7);
    graph.addEdge(4, 7);

    graph.BFS(0);
    graph.DFS(0);

    graph.agregarNodo("CDMX");
    graph.agregarNodo("Tlaxcala");
    graph.agregarNodo("Puebla");
    graph.agregarNodo("Toluca");
    graph.agregarArcoDirigidoConPeso("CDMX", "Tlaxcala", 50);
    graph.agregarArcoConPeso("CDMX", "CDMX", 20);
    graph.agregarArcoConPeso("CDMX", "Puebla", 100);
    graph.agregarArco("Puebla", "Puebla");
    graph.imprimirGrafo();

    
    return 0;
}