/*
    Descripción:
    Este programa suma recursiva 1 hasta "n"

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021
*/


/* La complejidad es lineal, debido a que se está presentando en un ciclo */
#include<iostream>
//#include<conio.h>

using namespace std;

//Esta función es la que va a realizar la suma recursiva, solo tiene un parametro entero "n" regresa el resultado siendo evaluado por dos condicioneles if
long int sumaRecursiva (int n){

    cout << " -----------------------------------------------------------------" << endl;
    cout << "La sumatoria de " << n << " es: " << endl;

    /* Condición de Parada */
    if (n == 0){  
        n = 0;
    }

    /* Paso Recursivo */
    else{
        n= n*(n+1)/2;
    
    }

    return n;
}

int main (){
    cout << sumaRecursiva(40) << endl;
    cout << " -----------------------------------------------------------------" << endl;
    
    cout << sumaRecursiva(100) << endl;
    cout << " -----------------------------------------------------------------" << endl;

    cout << sumaRecursiva(230) << endl;
    cout << " -----------------------------------------------------------------" << endl;

    cout << sumaRecursiva(340) << endl;
    cout << " -----------------------------------------------------------------" << endl;

    return 0;
}