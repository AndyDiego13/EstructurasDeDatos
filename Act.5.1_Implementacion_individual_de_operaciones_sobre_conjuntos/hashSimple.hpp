/*
    Actividad 5.1: Implementación de operaciones sobre conjuntos (Técnica de Hashing)

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 24 / 11 /2021

*/

#ifndef hashSimple_hpp
#define hashSimple_hpp

#include <iostream>
#include <vector>
#include <list>

class hashSimple
{
    //hash bucket chain 
    int bucket;
    //list
    std::list<int> *table;

    public:
        hashSimple(int v);

        
        void insertItem(int x);
        void deleteItem(int key);
        int hashBucket(int x)
        {
            return(x % bucket);
        }
        void displayHash();
};

hashSimple::hashSimple(int v)
{
    this->bucket = v;
    table = new std::list<int>[bucket];
}

void hashSimple::insertItem(int key)
{
    int index = hashBucket(key);
    table[index].push_back(key);
}

void hashSimple::deleteItem(int key)
{
    int index = hashBucket(key);

    std::list<int>::iterator it;

    for (it = table[index].begin(); it != table[index].end(); it++)
    {
        if (*it == key)
        {
            break;
        }
    }

    if (it != table[index].end())
    {
        table[index].erase(it);
    }
}

void hashSimple::displayHash()
{
    for (int i = 0; i < bucket; i++)
    {
        std::cout << i;
        for ( auto x : table[i])
        {
            std::cout << " --> " << x;
        }
        std::cout << std::endl;
    }
}

#endif // !hashSimple_hpp