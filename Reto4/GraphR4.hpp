/*
    Situacion Problema - Ataques Cibernéticos
    GraphR4.hpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/

#ifndef GraphR4_hpp
#define GraphR4_hpp

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <map>

template <class T>
class VertexG
{
    private:
        T val;
        std::vector<int> adj;
    
    public:

        ~VertexG() {};
        VertexG() {};
        VertexG(T _val)
        {
            val = _val;
        }

        T getVal()
        {
            return val;
        }

        void setVal(T _val)
        {
            val = _val;
        }

        std::vector<int> getAdj()
        {
            return adj;
        }

        void addAdj(int idx)
        {
            adj.push_back(idx);
        }

        friend bool operator == (VertexG<T> vg, VertexG<T> vgg)
        {
            return(vg.getVal() == vgg.getVal());
        }
};

template <class T>
class Graph
{
    private:

        std::vector<VertexG<T>> nodes;
        bool isDirected;
    
    public:

        ~Graph() {};
        Graph()
        {
            isDirected = true;
        }

        void addNode(T val)
        {
            VertexG<T> node(val);
            nodes.push_back(node);
        }

        void addEdge(int src, int dst)
        {
            nodes[src].addAdj(dst);

            if (!isDirected)
            {
                nodes[dst].addAdj(src);
            }
        }

        void addEdgeElement(std::string s, std::string d)
        {
            VertexG<T> src(s);
            VertexG<T> dst(d);

            auto itSrc = std::find(nodes.begin(), nodes.end(), src);
            auto itDst = std::find(nodes.begin(), nodes.end(), dst);

            if (itSrc != nodes.end() && itDst != nodes.end())
            {
                int iSrc = itSrc - nodes.begin();
                int iDst = itDst - nodes.begin();

                addEdge(itSrc, iDst);
            }
            else
            {
                std::cout << "Error. No existen." << std::endl;
            }
        }

        void printVeci()
        {
            for (int i = 0; i < node.size(); i++)
            {
                if (nodes[i].getAdj().size() != 0)
                {
                    std::cout << nodes[i].getVal() << ":\t" << nodes[i].getAdj().size() << std::endl;
                }
            }
        }

        std::map<T, int> saveVeci()
        {
            std::map<T, int> count;
            for (int i = 0; i < nodes.size(); i++)
            {
                count[ nodes[i].getVal() ] = nodes[i].getAdj().size();
            }
            return count;
        }

        void Bfs(int startVer)
        {
            std::vector<int> visited(nodes.size(), 0);

            std::queue<int> veci;

            visited.at(startVer) = 1;

            std::cout << nodes.at(startVer).getVal() << " " << std::endl;

            std::vector<int> adjacents;
            adjacents = nodes.at(startVer).getAdj();

            for (int i = 0; i < adjacents.size(); i++)
            {
                veci.push(adjacents.at(i));
            }

            while (!veci.empty())
            {
                int temp = veci.front();

                if (visited.at(temp) == 0)
                {
                    visited.at(temp) = 1;
                    std::cout << nodes.at(temp).getVal() << " " << std::endl;

                    std::vector<int> adjacents;
                    adjacents = nodes.at(temp).getAdj();

                    for (int i = 0; i < adjacents.size(); i++)
                    {
                        veci.push(adjacents.at(i));
                    }
                }
                veci.pop();
            }
            std::cout << std::endl;
        }

        void Dfs(int startVer)
        {
            std::vector<int> visited(nodes.size(), 0);
            std::stack<int> veci;

            visited.at(startVer) = 1;
            std::cout << nodes.at(startVer).getVal() << " " <<std::endl;

            std::vector<int> adjacents;
            adjacents = nodes.at(startVer).getAdj();

            for (int i = 0; i < adjacents.size(); i++)
            {
                veci.push(adjacents.at(i));
            }

            while (!veci.empty())
            {
                int temp = veci.top();

                veci.pop();

                if (visited.at(temp) == 0)
                {
                    visited.at(temp) = 1;
                    std::cout << nodes.at(temp).getVal() << " " << std::endl;

                    std::vector<int> adjacents;
                    adjacents = nodes.at(temp).getAdj();

                    for (int i = 0; i < adjacents.size(); i++)
                    {
                        veci.push(adjacents.at(i));
                    }
                }
            }
            std::cout << std::endl;
        }

        int size()
        {
            return nodes.size();
        }
};

#endif // !GraphR4_hpp
