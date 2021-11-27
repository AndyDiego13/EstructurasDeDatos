#include <iostream>
#include <unordered_map>

template <class T>
class Node
{
    public:
        T value;
        bool visited;
        std::unordered_map<Node<T> *, int> siguientes;
        int iA;

        Node(T val)
        {
            value = val;
            visited = false;
        }

        Node()
        {
            this->iA = 0;
            this->value = NULL;
        }

        Node(int iA, T value)
        {
            this->iA = iA;
            this->value = value;
        }

        void agregarArcoDirigidoConPeso(Node<T> *sig, int peso)
        {
            if (siguientres.find(sig) == siguientes.end())
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