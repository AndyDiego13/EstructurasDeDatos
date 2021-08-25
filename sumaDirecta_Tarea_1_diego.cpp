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
long int sumaDirecta (int n){

    int resultado = n*(n + 1)/2;

    cout << "Cuando n= " << n << endl;
    cout << "El resultado de la suma de sus datos es: " << resultado << endl;   
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