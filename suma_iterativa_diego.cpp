/*

    Descripción
    Este programa suma iterativamente 1 hasta "n"

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021

*/

//Programa que suma n numeros enteros

//Orden Lineal O(n)
#include <iostream>
using namespace std;

int main(){
    //declaración de variables
    int n;
    int x;
    int suma;
    int i;

    std::cout << "Introducir el valor de n :" << std::endl;

    cin >> n;
    suma = 0;

    std::cout << "Introducir los numeros enteros: " << std::endl;

    for (i=0; i < n; i++){

        cin >> x;
        suma = suma + x; //acumulo x en la suma
    }   

    std::cout << "Resultado de la suma: " << suma << std::endl;

    return 0;
} 