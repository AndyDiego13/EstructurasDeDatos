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
#include "Node.hpp"

int main() 
{
    std::cout << "Grafos: sus representaciones y sus recorridos" << std::endl;

    // loadGraph 
    std::vector< std::vector<int>> m;
    std::vector<int> n;

    n.push_back(0);
    n.push_back(1);

    m.push_back(n);

    for (auto fila : m)
    {
        for (int valor : fila)
        {
            std::cout << valor << ",";
        }
        std::cout << "          " << std::endl;
    }
    
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

    
    return 0;
}