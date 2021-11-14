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

Graph::Graph(int choice, std::string filename)
{
    std::fstream file;

    // leer vertices
    if (choice == 1)
    {
        std::cout << "Número de vertices: " << std::endl;
        std::cin >> vertix;
    }
    else if (choice == 2)
    {
        file.open(filename, ios::in);
        file >> vertix;
        if (file.eof() || vertix == 0)
        {
            throw std::out_of_range("El grafo está vacío");
        } 
    }
    else
    {
        std::cout << "Número invalido. Intentalo de nuevo \n" << std::endl;
        throw std::invalid_argument("Opción invalida");
        return;
    }
    
    // control de memoria

    int **arrCheck;
    arrCheck = (int**)malloc(sizeof(int*) *vertix);

    if (!arrCheck)
    {
        throw std::out_of_range("Error de localización");
        return;
    }
    else
    {
        graphMatrix = arrCheck;
    }

    // leer grafo
    if (choice == 1)
    {
        for (int i = 0; i < vertix; i++)
        {
            arrCheck[i] = (int*)malloc(vertix *sizeof(int));
            if (!arrCheck[i])
            {
                throw std::out_of_range("Error de localización");
                return;
            }
            else
            {
                graphMatrix[i] = arrCheck[i];
            }
            
            for (int j = 0; j < vertix; j++)
            {
                int temp;
                std::cin >> temp;

                if (temp == 0 || temp == 1)
                {
                    graphMatrix[i][j] = temp;
                }
                else
                {
                    throw std::invalid_argument("Error de lectura");
                    for (int k = 0; k < i; k++)
                    {
                        free(graphMatrix[k]);
                    }
                    free(graphMatrix);
                    vertix = 0;
                }
                if (i == j)
                {
                    graphMatrix[i][j] = 0;
                }
            }  
        }

        std::cout << "Lectura correcta. \n" << std::endl;
    }
    else if (choice == 2)
    {
        for (int i = 0; i < vertix; i++)
        {
            arrCheck[i] = (int*)malloc(vertix *sizeof(int));
            if (!arrCheck[i])
            {
                throw std::out_of_range("Error de localización");
                return;
            }
            else
            {
                graphMatrix[i] = arrCheck[i];
            }

            for (int j = 0; j < vertix; j++)
            {
                if (file.eof())
                {
                    throw std::invalid_argument("Final del documento");
                }

                int temp;
                file >> temp;

                if (temp == 0 || temp == 1)
                {
                    graphMatrix[i][j] = temp;
                }
                else
                {
                    throw std::invalid_argument("Error de lectura");

                    for (int k = 0; k < i; k++)
                    {
                        free(graphMatrix[k]);
                    }
                    free(graphMatrix);
                    vertix = 0;
                }

                if (i == j)
                {
                    graphMatrix[i][j] = 0;
                }   
            }    
        }

        std::cout << "Lectura exitosa." << vertix << std::endl;
        file.close();
    }

    direct = directCheck();  
}

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

void Graph::ifEulerian()
{
    IteratorG *gDftIter = createDftIterator(0);
    int maxConnect = 0;
    int curConnect = 0;

    while (gDftIter->hNext())
    {
        gDftIter->next();

        if (!gDftIter->newConec())
        {
            curConnect++;
        }
        else
        {
            if (maxConnect > 1)
            {
                if (curConnect > 1)
                {
                    return false;
                }
            }

            if (curConnect > maxConnect)
            {
                maxConnect = curConnect;
            }
            
            curConnect = 0;
        } 
    }

    if (curConnect > 1 && maxConnect > 1)
    {
        return false;
    }
    
    int *countRows;
    int *countCols;

    countRows = new int[vertix];
    countCols = new int[vertix];

    for (int j = 0; j < vertix; j++)
    {
        countCols[j] = 0;
    }
    for (int i = 0; i < vertix; i++)
    {
        countRows[i] = 0;

        for (int j = 0; j < vertix; j++)
        {
            if (graphMatrix[i][j] == 1)
            {
                countRows[i]++;
                countCols[j]++;
            }  
        }
    }

    for (int i = 0; i < vertix; i++)
    {
        if (!direct && (countCols[i] + countRows[i]) % 2 != 0)
        {
            return false;
        }
        else if (!direct && (countCols[i] != countRows[i]))
        {
            return false;
        }
    }

    return true;  
}

bool Graph::ifBipartite()
{
    int *color = new int[vertix];

    for (size_t i = 0; i < vertix; i++)
    {
        color[i] = 2;
    }

    IteratorG *gBftIter = createBftIterator(0);
    int cur;

    while (gBftIter->hNext())
    {
        if (gBftIter->newConec())
        {
            cur = gBftIter->next();
            color[cur] = 1;
        }
        else
        {
            cur = gBftIter->next();
        }

        for (size_t i = 0; i < vertix; i++)
        {
            if (graphMatrix[cur][i] == 1)
            {
                switch (color[i])
                {
                case 2:
                    if (color[cur] == 1)
                    {
                        color[i] = 0;
                    }
                    else
                    {
                        color[i] = 1;
                    }
                    
                    break;
                
                default:
                    if (color[i] == color[cur])
                    {
                        return false;
                    }
                    
                    break;
                }
            }   
        }
    }
    
    return true;
}

bool Graph::ifTree()
{
    IteratorG *gDftIter = createDftIterator(0);

    if (direct)
    {
        int countDeg;
        int count = 0;

        for (size_t i = 0; i < vertix; i++)
        {
            countDeg = 0;

            for (size_t j = 0; j < vertix; j++)
            {
                countDeg += graphMatrix[j][i];

                if (countDeg > 1)
                {
                    return false;
                }
                else if (countDeg == 0)
                {
                    count ++;
                    if (count > 1)
                    {
                        return false;
                    } 
                }
            }
        }

        if (count == 0)
        {
            return false;
        } 
    }
    else
    {
        if (ifCycleNumDir())
        {
            return false;
        }
        while (gDftIter->hNext())
        {
            gDftIter->next();
            if (gDftIter->newConec())
            {
                return false;
            }
        }
    }

    return true;
}

int *Graph::pruferDeCode()
{
    if (!ifTree() || direct)
    {
        throw std::invalid_argument("Tipo de grafo invalido");
    }
    if (vertix <= 2)
    {
        return NULL;
    }

    int *prufC = new int[vertix - 2];
    int **gCopy = new int*[vertix];

    for (int i = 0; i < vertix; i++)
    {
        gCopy[i] = new int[vertix];

        for (int j = 0; j < vertix; j++)
        {
            gCopy[i][j] = graphMatrix[i][j];
        }  
    }

    int curVer = 0;
    int connectNum = 0;
    int nextVer = 0;
    int curPruf = 0;

    bool exit = false;

    while (curPruf < vertix - 2)
    {
        for (int j = 0; j < vertix; j++)
        {
            if (gCopy[curVer][j] == 1)
            {
                connectNum++;

                if (connectNum > 1)
                {
                    curVer++;
                    exit = true;
                    break;
                }
                
                nextVer = j;
            }
        }

        if (connectNum == 0)
        {
            exit = true;
            curVer++;
        }

        if (!exit)
        {
            gCopy[nextVer][curVer] = 0;
            gCopy[curVer][nextVer] = 0;

            pruferDeCode[curPruf] = nextVer;

            if (nextVer < curVer)
            {
                curVer = nextVer;
            }
            else
            {
                curPruf++;
            }
        }

        connectNum = 0;
        nextVer = 0;
        exit = false; 
    }

    return prufC;  
}

void Graph::pruferDeCode(int *prufC, int prufLength)
{
    for (int i = 0; i < prufLength; i++)
    {
        if (prufC[i] >= prufLength + 2)
        {
            throw std::invalid_argument("Codigo de prufer invalido");
        }
    }

    vertix = prufLength + 2;
    int *verNum = new int[vertix];
    int **graphTemp = (int**)malloc(sizeof(int*) * vertix);
    int pos = 0;
    int posPruf = 0;

    for (int i = 0; i < vertix; i++)
    {
        verNum[i] = i;
        graphTemp[i] = (int*)malloc(vertix *sizeof(int));

        for (int j = 0; j < vertix; j++)
        {
            graphTem[i][j] = 0;
        }
    }

    for (; posPruf < vertix - 2; i++)
    {
        for (int i = posPruf; i < vertix - 2; i++)
        {
            if (verNum[pos] == prufC[i] || verNum[pos] == -1)
            {
                i = posPruf - 1;
                pos++;
            }  
        }

        graphTemp[verNum[pos]][prufC[posPruf]] = 1;
        graphTemp[prufC[posPruf]][verNum[pos]] = 1;
        verNum[pos] = -1;
        pos = 0;
    }

    int row = -1;
    int col = -1;

    for (int i = 0; i < vertix; i++)
    {
        if (verNum[i] != -1 && row == -1)
        {
            row = verNum[i];
        }
        else if (verNum[i] != -1)
        {
            col = verNum[i];
            break;
        }
    }

    graphTemp[row][col] = 1;
    graphTemp[col][row] = 1;
    graphMatrix = (int**)realloc(graphMatrix, sizeof(int*) * vertix);
    graphMatrix = graphTemp; 
}

//falta strong connected

int *Graph::getSize()
{
    return vertix;
}

int *Graph::dijkstra(int startPoint)
{
    int *distance = new int[vertix];
    bool *visited = new bool[vertix];
    int **gCopy = new int *[vertix];

    for (int i = 0; i < vertix; i++)
    {
        gCopy[i] = new int[vertix];

        for (int j = 0; j < vertix; j++)
        {
            if (graphMatrix[i][j] == 0)
            {
                gCopy[i][j] = intMax;
            }
            else
            {
                gCopy[i][j] = graphMatrix[i][j];
            }   
        }
    }

    for (size_t i = 0; i < vertix; i++)
    {
        distance[i] = gCopy[startPoint][i];
        visited[i] = false;
    }

    int u = 0;
    int index = 0;
    int min;

    distance[startPoint] = 0;

    for (size_t i = 0; i < vertix; i++)
    {
        min = intMax;

        for (size_t j = 0; j < vertix; j++)
        {
            if ((visited[j] == false) && (distance[j] < min))
            {
                min = distance[i];
                index = j;
            }
        }

        u = index;
        visited[u] = true;

        for (size_t j = 0; j < vertix; j++)
        {
            if ((visited[j] == false) && (gCopy[u][j] != intMax) && (distance[u] != intMax) && ((distance[u] + gCopy[u][j]) < distance[j]))
            {
                distance[j] = distance[u] + gCopy[u][j];
            }
        }  
    }

    for (size_t i = 0; i < vertix; i++)
    {
        delete gCopy[i];
    }

    delete gCopy;
    return distance;
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

