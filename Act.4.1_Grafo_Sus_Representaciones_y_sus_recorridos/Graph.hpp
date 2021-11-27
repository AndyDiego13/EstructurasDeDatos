/*
    "Graph.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 14/11/2021
*/

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <unordered_map>
#include "GraphVertex.hpp"
#include "Node.hpp"

template <class T>
class Graph
{
    private:
        
        std::vector<GraphVertex<T>> nodes;
        bool isDirected;
        

    public:

        ~Graph() {};
        Graph()
        {
            isDirected = false;
        }

        void addNode(T val)
        {
            GraphVertex<T> node(val);
            nodes.push_back(node);
        }

        void addEdge(int src, int dst)
        {
            nodes[src].addToAdj(dst);

            if (!isDirected)
            {
                nodes[dst].addToAdj(src);
            }  
        };

        void BFS(int startVertex)
        {
            std::vector<int> visited(nodes.size(), 0);

            std::queue<int> vecinos;

            visited.at(startVertex) = 1;

            std::cout << nodes.at(startVertex).getVal() << "" <<std::endl;

            std::vector<int> adjacents;

            adjacents = nodes.at(startVertex).getAdj();

            for (int i = 0; i < adjacents; i++)
            {
                vecinos.push(adjacents.at(i));
            }

            while (!vecinos.empty())
            {
                int temp = vecino.front();

                if (visited.at(temp) == 0)
                {
                    visited.at(temp) = 1;
                    std::cout << nodes.at(temp).getVal() << " " << std::endl;
                    std::vector<int> adjacents;
                    adjacents = nodes.at(temp).getAdj();

                    for (int i = 0; i < adjacents.size(); i++)
                    {
                        vecinos.push(adjacents.at(i));
                    }
                }
                vecinos.pop();
            }
            std::cout << std::endl;
        }
        
        void DFS(int startVertex)
        {
            std::vector<int> visited(nodes.size(), 0);
            std::stack<int> vecinos;

            visited.at(startVertex) = 1;
            std::cout << nodes.at(startVertex).getVal() << " " << std::endl;

            std::vector<int> adjacents;
            adjacents = nodes.at(startVertex).getAdj();

            for (int i = 0; i < adjacents.size(); i++)
            {
                vecinos.push(adjacents.at(i));
            }

            while (!vecinos.empty())
            {
                int temp = vecinos.top();
                vecinos.pop();

                if (visited.at(temp) == 0)
                {
                    visited.at(temp) = 1;
                    std::cout << nodes.at(temp).getVal() << "  " << std::endl;
                    std::vector<int> adjacents;
                    adjacents = nodes.at(temp).getAdj();

                    for (int i = 0; i < adjacents.size(); i++)
                    {
                        vecinos.push(adjacents.at(i));
                    }
                }
            }
            std::cout << std::endl;
        }

        std::unordered_map<T, Node<T> *> nodes;

        void agregarNode(T value)
        {
            if (nodes.find(value) == nodes.end())
            {
                Node<T> *nuevo = new Node<T>(value);
                nodes[values] = nuevo;
            }
        }

        void agregarArcoDirigidoConPeso(T node1, T node2, int peso)
        {
            if (nodes.find(node1) != nodes.end() && nodes.find(node2) != nodes.end())
            {
                nodes[node1]->agregarArcoDirigidoConPeso(nodes[node2], peso);
            }
        }

        void agregarArcoDirigido(T node1, T node2)
        {
            agregarArcoDirigidoConPeso(node1, node2, 1);
        }

        void agregarArcoConPeso(T node1, T node2, 1);
        {
            agregarArcoDirigidoConPeso(node1, node2, peso);
            agregarArcoDirigidoConPeso(node2, node1, peso);
        }

        void agregarArco(T node1, T node2)
        {
            agregarArcoConPeso(node1, node2, 1);
        }

        void imprimirGrafo()
        {
            for (auto parValorNode : nodes)
            {
                parValorNode.second->imprimirNode();
            }
            
        }
};

#endif // !Graph_hpp