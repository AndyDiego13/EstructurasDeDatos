/*
    Andrea Serrano Diego

    27/Agosto/2021
*/

#include <iostream>
#include "Node.hpp"
#include "Linkedlist.hpp"

int main(int argc, char const *argv[])
{
    /* creacion de nodos */
    std::cout << "--- Creacion y eliminacion de nodos ---" << std::endl;
    std::cout << std::endl;

    /* uso de constructor predeterminado Node<T>()*/
    Node<int> n1;
    std::cout << "-> Nodo creado con constructor predeterminado: " << n1 <<std::endl;

    /* uso de constrcutor con parametros Node<T>(T) */
    Node<float> n2(3.14);
    std::cout << "-> Nodo creado con constructor con parametros: " << n2 << std::endl;

    /* uso de constrcutor copia Node<T> (Node<T> &) */
    Node<int> n3 = n1;
    std::cout << "-> Nodo creado con constructor copia: " << n3 << std::endl;

    /* crear un nodo con memoria dinamica */
    Node<int> * nodeptr = new Node<int>(10);
    std::cout << "-> Nodo creado con memoria dinamica: " << *nodeptr << std::endl;

    /* liberar la memoria ocupada por el nodo */
    std::cout << "<- Nodo eliminado con delete: " << *nodeptr << std::endl;
    delete nodeptr;








    return 0;
}
