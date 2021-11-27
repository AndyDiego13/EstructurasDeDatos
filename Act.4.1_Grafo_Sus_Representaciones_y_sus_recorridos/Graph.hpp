/*
    "Graph.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 26/11/2021
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
#include "NodeAG.hpp"

template <class T>
class Graph
{
    private:
        
        std::vector<GraphVertex<T>> nodes;
        bool isDirected;
        std::unordered_map<T, Node<T> *> nodos;
        

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
        }

        void agregarNodo(T val)
        {
            if (nodos.find(val) == nodos.end())
            {
                Node<T> *nuevo = new Node<T>(val);
                nodos[val] = nuevo;
            }   
        }

        void BFS(int startVertex)
        {
            std::vector<int> visited(nodes.size(), 0);

            std::queue<int> vecinos;

            visited.at(startVertex) = 1;

            std::cout << nodes.at(startVertex).getVal() << "" <<std::endl;

            std::vector<int> adjacents;

            adjacents = nodes.at(startVertex).getAdj();

            for (int i = 0; i < adjacents.size(); i++)
            {
                vecinos.push(adjacents.at(i));
            }

            while (!vecinos.empty())
            {
                int temp = vecinos.front();

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

        void agregarArcoDirigidoConPeso(T nodo1, T nodo2, int peso)
        {
		    if(nodos.find(nodo1)!=nodos.end() && nodos.find(nodo2)!=nodos.end())
            {
			    nodos[nodo1]->agregarArcoDirigidoConPeso(nodos[nodo2], peso);
            }
		}

        void agregarArcoDirigido(T nodo1, T nodo2)
        {
		    agregarArcoDirigidoConPeso(nodo1, nodo2, 1);
	    }

        void agregarArcoConPeso(T nodo1, T nodo2, int peso)
        {
		    agregarArcoDirigidoConPeso(nodo1, nodo2, peso);
		    agregarArcoDirigidoConPeso(nodo2, nodo1, peso);
        }

        void agregarArco(T nodo1, T nodo2)
        {
		    agregarArcoConPeso(nodo1, nodo2, 1);
	    }

        void imprimirGrafo()
        {
		    for(auto parValorNodo: nodos)
            {
			    parValorNodo.second->imprimirNode();
		    }
	    }
};

#endif // !Graph_hpp