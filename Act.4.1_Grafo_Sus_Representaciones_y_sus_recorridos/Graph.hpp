#pragma once
#include "IteratorG.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include "DualList.hpp"
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

class Graph
{
    public:
        int **graphMatrix;
        int vertix;
        bool direct;
        bool directCheck();
        bool ifCycleNumDir();
    
    

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


        int getSize();
        DualList *strongConnect();

        friend std::ostream& operator << (std::ostream&, const Graph&);

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

        virtual IteratorG *createDftIterator(int);
        virtual IteratorG *createBftIterator(int);

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

bool Graph::directCheck()
{
    for (size_t i = 0; i < vertix; i++)
    {
        for (size_t j = 0; j < vertix; j++)
        {
            if (graphMatrix[i][j] != graphMatrix[j][i])
            {
                return true;
            }
        }
    }

    return false;
}

bool Graph::ifCycleNumDir()
{
    if (direct)
    {
        throw std::invalid_argument("Tipo de grafo invalido");
    }
    else
    {
        IteratorG *gDftIter = createDftIterator(0);
        bool *visited = new bool[vertix];

        for (size_t i = 0; i < vertix; i++)
        {
            visited[i] = false;
        }
        int cur;
        int bef;

        while (gDftIter->hNext())
        {
            bef = gDftIter->antesCur();
            cur = gDftIter->next();
            visited[cur] = true;

            for (size_t i = 0; i < vertix; i++)
            {
                if ((graphMatrix[cur][i] == 1) && (visited[i] == true) && (i != bef))
                {
                    return true;
                }  
            }
        }
    }

    return false;
}


//falta strong connected

int Graph::getSize()
{
    return vertix;
}


IteratorG *Graph::createDftIterator(int start = 0)
{
    return new DftIterator(graphMatrix, vertix, start);
}

std::ostream &operator << (std::ostream &out, const &Graph gr)
{
    std::cout << "Grafo: " << std::endl;

    for (int i = 0; i < gr.vertix; i++)
    {
        for (int j = 0; j < gr.vertix; j++)
        {
            std::cout << gr.graphMatrix[i][j] << " " << std::endl;
        }

        std::cout << std::endl; 
    }

    return out;
}

bool Graph::DftIterator::hasNext()
{
    if (!stack->isEmpty())
    {
        return true;
    }

    for (size_t i = 0; i < sizeVertix; i++)
    {
        if (visited[i] == false)
        {
            return true;
        }
    }

    return false;
}

int Graph::DftIterator::next()
{
    if (!hasNext())
    {
        throw std::out_of_range("No tiene más elemetos");
    }

    visited[iCurrent] = true;
    int temp = iCurrent;

    for (size_t i = 0; i < sizeVertix; i++)
    {
        if ((visited[i] == false) && (itrG[iCurrent][i] == 1))
        {
            before = iCurrent;
            iCurrent = i;
            stack->push(iCurrent);
            connection = false;
            break;
        }
    }

    int backcur;

    while ((temp == iCurrent) && !stack->isEmpty())
    {
        backcur = stack->popOut();

        for (size_t i = 0; i < sizeVertix; i++)
        {
            if ((visited[i] == false) && (itrG[backurr][i] == 1))
            {
                before = backcur;
                iCurrent = i;
                stack->push(backcur);
                stack->push(iCurrent);
                connection = false;
                break;
            } 
        }
    }

    if (temp == iCurrent)
    {
        for (size_t i = 0; i < sizeVertix; i++)
        {
            if (visited[i] == false)
            {
                before = -1;
                iCurrent = i;
                stack->push(iCurrent);
                connection = true;
                break;
            }
        }
        return temp;
    }
}

int Graph::DftIterator::beforeCurrent()
{
    return before;
}

bool Graph::DftIterator::newConnection()
{
    return connection;
}

// implementacion de BFT

IteratorG *Graph::createBftIterator(int start = 0)
{
    return new bftIterator(graphMatrix, vertix, start);
}

bool Graph::bftIterator::hasNext()
{
    if (!queue->isEmpty())
    {
        return true;
    }

    for (size_t i = 0; i < sizeVertix; i++)
    {
        if (visited[i] == false)
        {
            return true;
        }
    }

    return false;
}

int Graph::bftIterator::next()
{
    if (!hasNext())
    {
        throw std::out_of_range("No hay más elementos");
    }

    visited[iCurrent] = true;
    int temp = iCurrent;
    
    for (size_t i = 0; i < sizeVertix; i++)
    {
        if ((visited[i] == false) && (itrG[iCurrent][i] == 1))
        {
            queue->push(i);
        }
    }

    while (!queue->isEmpty() && (visited[iCurrent] == true))
    {
        iCurrent = queue->popOut();
        connection = false;
    }

    if (queue->isEmpty() && (visited[iCurrent] == true))
    {
        for (size_t i = 0; i < sizeVertix; i++)
        {
            if (visited[i] == false)
            {
                iCurrent = i;
                queue->push(iCurrent);
                connection = true;
                break;
            }  
        }
    }

    return temp;
}

int Graph::bftIterator::beforeCurrent()
{
    return before;
}

bool Graph::bftIterator::newConnection()
{
    return connection;
}