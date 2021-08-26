/*
    Descripción:
    Este programa suma directa 1 hasta "n"

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021
*/

#include<iostream>

using namespace std;

// Esta función es la que va a realizar la suma directa, solo tiene un parametro entero "n" regresa el resultado
//Complejidad es de 4
// Orden constante O(1)
long int sumaDirecta (int n){       //1

    int resultado = n*(n + 1)/2;    //1

    cout << "Cuando n= " << n << endl;  //1
    cout << "El resultado de la suma de sus datos es: " << resultado << endl;   //1
}

int main(){

    cout << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;
    
    sumaDirecta(40);
    cout << "------------------------------------------------------------------" << endl;

    cout << "------------------------------------------------------------------" << endl;
    sumaDirecta(100);

    cout << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;
    sumaDirecta(230);

    cout << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;
    sumaDirecta(340);

    cout << "------------------------------------------------------------------" << endl;
    cout << "------------------------------------------------------------------" << endl;

    return 0; 
}