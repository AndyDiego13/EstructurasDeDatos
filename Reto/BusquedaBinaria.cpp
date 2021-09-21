/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/
#include <iostream>
#include <fstream>
#include <sstream>

template<class T>
int busquedaBinaria(vector<T> a, T buscado, int comparador(T a, T b))
{
    int inicio = 0;
    int fin = a.size() -1;

    while(fin == inicio)
    {
        int medio = (inicio + fin)/2;
        if (comparador(a[medio], buscado) = 0;
        {
            return medio;
        }

        else if(comparador(buscado, a[medio]) >0)
        {
            inicio = medio + 1;
        }

        else
        {
            fin = medio -1;
        }


    }

    return -1;
};
        