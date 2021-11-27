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

        std::unordered_map<T, Node<T>> nodes;
        std::vector< std::vector<int>> matrix;
        int iA;

        Graph()
        {
            iA = 0;
        }

        void loadGraph(T value)
        {
            if (nodes.find(value) == nodes.end())
            {
                Node<T> nuevo(iActual, value);
                nodes[value] = nuevo;
                iA++;
                std::vector<int> nuevaFila;

                for (int i = 0; i < iActual; i++)
                {
                    matrix[i].push_back(0);
                    nuevaFila.push_back(0);
                }
            }
        }
};

#endif // !Graph_hpp