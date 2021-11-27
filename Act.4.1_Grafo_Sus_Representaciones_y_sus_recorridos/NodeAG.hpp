/*
    "NodeAG.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 26/11/2021
*/

#ifndef NodeAG_hpp
#define NodeAG_hpp

#include <iostream>
#include <unordered_map>

template <class T>
class Node
{
    public:
        T value;
        bool visited;
        std::unordered_map<Node<T> *, int> siguientes;

        Node(T val)
        {
            value = val;
            visited = false;
        }


        void agregarArcoDirigidoConPeso(Node<T> *sig, int peso)
        {
            if (siguientes.find(sig) == siguientes.end())
            {
                siguientes[sig] = peso;
            }  
        }

        void agregarArcoDirigido(Node<T> *sig)
        {
            agregarArcoDirigidoConPeso(sig, 1);
        }

        void imprimirNode()
        {
            std::cout << value << ":" <<std::endl;

            for (auto nodeSiguiente : siguientes)
            {
                std::cout << nodeSiguiente.first->value << "," << nodeSiguiente.second << ";" << std::endl;
            }
            std::cout << std::endl;
        }
};

#endif // !NodeAG_hpp