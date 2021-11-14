#pragma once
#include "IteratorG.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "DualList.hpp"
#include <iostream>
#include <stdlib.h>

class Graph
{
    private:
        int **graphMatrix;
        int vertix;
        bool direct;
        bool directCheck();
        bool ifCycleNumDir();
    
    public:

        ~Graph()
        {
            for (size_t i = 0; i < vertix; i++)
            {
                free(graphMatrix[i]);
            }
            free(graphMatrix); 
        }

        Graph(int **newGraph = NULL, int verNum = 0)
        {
            graphMatrix = newGraph;
            vertix = verNum;
            direct = directCheck();
        }

        Graph(int choice, std::string filename = "in.txt");

        int getSize();
        bool ifEulerian();
        bool ifBipartite();
        bool ifTree();
        int *pruferDeCode(int *, int);
        DualList *strongConnect();
        int *dijkstra(int);

        friend std::ostream &operator << (std::ostream &, const &Graph);

        friend bool operator == (Graph &left, int right[])
        {
            for (int i = 0; i < left.vertix; i++)
            {
                for (int j = 0; j < left.vertix; j++)
                {
                    if (left.graphMatrix[i][j] != right[i *left.vertix + j])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        IteratorG *createDftIterator(int);
        IteratorG *createBftIterator(int);

        class DftIterator : public IteratorG
        {
            private:
                bool *visited;
                int **itrG;
                Stack *stack;
                int iCurrent;
                int sizeVertix;
                int before;
                bool connection;
            
            public:
                DftIterator(int **gr, int max, int start = 0)
                {
                    stack = new Stack();
                    sizeVertix = max;
                    itrG = gr;
                    iCurrent = start;
                    visited = new bool[max];

                    stack->push(iCurrent);

                    for (size_t i = 0; i < max; i++)
                    {
                        visited[i] = false;
                    }

                    visited[iCurrent] = true;
                    before = -1;
                    connection = true;  
                }

                ~DftIterator()
                {
                    delete visited;
                    delete *itrG;
                }

                int next();
                bool hasNext();
                bool newConnection();
                int beforeCurrent();
        };

        class bftIterator : public IteratorG
        {
            private:
                bool *visited;
                int **itrG;
                Queue *queue;
                int iCurrent;
                int sizeVertix;
                int before = -1;
                bool connection;
            
            public:
                bftIterator(int **gr, int max, int start = 0)
                {
                    queue = new Queue();
                    sizeVertix = max;
                    itrG = gr;
                    iCurrent = start;
                    visited = new bool[max];

                    queue->push(iCurrent);

                    for (size_t i = 0; i < max; i++)
                    {
                        visited[i] = false;
                    }

                    visited[iCurrent] = false;
                    connection = true; 
                }

                ~bftIterator()
                {
                    delete visited;
                    delete *itrG;
                }

                int next();
                bool hasNext();
                bool newConnection();
                int beforeCurrent();
        };
};