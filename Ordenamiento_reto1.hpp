/*
    Situacion Problema - Ataques Cibernéticos
    Ordenamiento_reto1.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#ifndef Ordenamiento_hpp
#define Ordenamiento_hpp

#include <stdio.h>
#include <iostream>
#include <vector>


template <class T>
class Ordenamiento {
public:
    static std::vector<T> burbuja(std::vector<T>, bool(*)(T,T));
    static std::vector<T> insercion(std::vector<T>, bool(*)(T,T));
    static std::vector<T> seleccion(std::vector<T>, bool(*)(T,T));
    
    static std::vector<T> quicksort(std::vector<T>, int, int, bool(*)(T,T));
    static std::vector<T> mergesort(std::vector<T>, int, int, bool(*)(T,T));
    
    static bool asc(T,T);
    static bool desc(T,T);
    
    static bool ordena(T,T);
    
private:
    static std::vector<T> merge(std::vector<T>, int, int, int, bool (*) (T, T));
};



template <class T>
bool Ordenamiento<T>::asc(T a, T b)
{
    return a < b;
}

template <class T>
bool Ordenamiento<T>::desc(T a, T b)
{
    return a > b;
}

template <class T>
std::vector<T> Ordenamiento<T>::burbuja(std::vector<T> e, bool compara (T,T))
{
    int n = (int) e.size();
    
    for (int i = 0; i < n; ++i) {
        for (int j = n-1; j > i; --j) {
            if ( compara(e[j], e[j-1]) ) {
                std::swap(e[j], e[j-1]);
            }
        }
    }
    //copy(e.begin(), e.end(), ostream_iterator<T>(std::cout, " "));
    return e;
}


template <class T>
std::vector<T> Ordenamiento<T>::insercion(std::vector<T> e, bool compara (T,T))
{
    T index;
    
    int n = (int) e.size();
    
    for (int i = 1; i < n; i++)
    {
        index = e[i];
        
        int j = i-1;
        
        while ( j >= 0 && compara(index, e[j]) )
        {
            e[j + 1] = e[j];
            j--;
        }
        
        e[j+1] = index;
    }
    return e;
}

template <class T>
std::vector<T> Ordenamiento<T>::seleccion(std::vector<T> e, bool compara (T,T))
{
    int minimo = 0;
    
    int n = (int) e.size();

    for(int i = 0; i < n-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < n; j++)
        {
            if ( compara(e[j], e[minimo]) )
                minimo = j;
        }
        std::swap(e[minimo], e[i]);
    }
    copy(e.begin(), e.end(), std::ostream_iterator<T>(std::cout, " "));
    return e;
}

template <class T>
std::vector<T> Ordenamiento<T>::quicksort(std::vector<T> e, int primero, int ultimo, bool compara (T, T))
{
    int izquierdo = primero;
    int derecho = ultimo;
    
    //Se selecciona pivote
    T pivote = e[primero];
    
    if ( primero < ultimo) // Paso base
    {
        // particion
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && !compara(pivote, e[izquierdo])) izquierdo++; // <=
            while ( compara(pivote, e[derecho]) ) derecho--; // >
            
            if ( izquierdo < derecho) // se intercambian los contenidos
            {
                std::swap(e[izquierdo], e[derecho]);
            }
        }
        
        // Se intercambia el pivote con el elemento de la posición derecha
        std::swap(e[primero], e[derecho]);
        
        // Paso recursivo
        e = quicksort ( e, primero, derecho-1, compara);
        e = quicksort ( e, izquierdo, ultimo, compara);
    }
    return e;
}


template <class T>
std::vector<T> Ordenamiento<T>::mergesort(std::vector<T> e, int l, int n, bool compara (T, T))
{
    int m = (n + l) / 2;
    
    if (n > l)
    {
        e = mergesort (e, l, m, compara);
        e = mergesort (e, m+1, n, compara);
        e = merge (e, l, m, n, compara);
    }
    //copy(e.begin(), e.end(), std::ostream_iterator<T>(std::cout, " "));
    return e;
}

template <class T>
std::vector<T> Ordenamiento<T>::merge(std::vector<T> e, int l, int m, int n, bool compara (T, T))
{
    int i, j, k;
    
    /* Definir un vector auxiliar */
    std::vector<T> aux(e.size());
    
    /* Copiar elementos al vector auxiliar */
    for(i=m+1;i>l;i--)
        aux[i-1] = e[i-1];
    
    for (j=m; j<n; j++)
        aux[n+m-j] = e[j+1];
    
    /* Proceso de mezcla en el orden especificado */
    for(k=l;k<=n;k++)
        if (compara(aux[i], aux[j])) // <
            e[k] = aux[i++];
        else
            e[k] = aux[j--];
    return e;
}


#endif /* Ordenamiento_hpp */