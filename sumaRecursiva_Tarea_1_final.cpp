/*
    Descripción:
    Este programa calcula la sumatoria de 1 hasta "n" de manera recursiva 

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021
*/

#include<iostream>


using namespace std;


//Esta función es la que va a realizar la suma recursiva, solo tiene un parametro entero "n" regresa el resultado recursivo siendo evaluado por dos condicioneles if

int sumaRecursiva(int n){ // El nivel de complejidad es: O(n) (lineal)

    if (n == 1){

        return 1;
    }
    else{

        return n + sumaRecursiva(n-1);
    }
}


int main (){
    
    int num;

    cout << "___________________________________________________________________________" << endl;
    cout << "Favor de ingresar el numero total de datos (n): " << endl;
    cin >> num;

    cout << "___________________________________________________________________________" << endl;
    cout << "La suma Recursiva es: " << sumaRecursiva(num) << endl;

    cout << "___________________________________________________________________________" << endl;
    
    return 0;
}
