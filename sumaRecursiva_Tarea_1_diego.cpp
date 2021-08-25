/*
    Descripción:
    Este programa suma recursiva 1 hasta "n"

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021
*/


/* La complejidad es lineal, debido a que se está presentando en un ciclo */
#include<iostream>


using namespace std;

//Esta función es la que va a realizar la suma recursiva, solo tiene un parametro entero "n" regresa el resultado recursivo siendo evaluado por dos condicioneles if
int sumaRecursiva(int n){

    if (n == 1){

        return 1;
    }
    else{

        return n + sumaRecursiva(n-1);
    }
}


int main (){

   int num;

   std::cout << "Favor ingresar el número: " << std::endl;
   cin >> num;

   std::cout << "La suma Recursiva es: " << sumaRecursiva(num) << std::endl;
    return 0;
}