/*
    Descripción:
    Este programa calcula la sumatoria de 1 hasta "n" mediante un metodo directo

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021
*/
#include<iostream>

using namespace std;


//Complejidad temporal T(n) de 4

long int sumaDirecta (int n){ // El nivel de complejidad es: O(1) (Constante)
    int resultado = n*(n+1)/2;
    
    return resultado;
}

int main()
{
    
    int n;

    cout << "___________________________________________________________________________" << endl;
    
    cout << "Favor de ingresar el numero total de datos (n): " << endl;
    cin >> n;  

    cout << "___________________________________________________________________________" << endl;
    cout << "La Suma Directa es: " << sumaDirecta(n) << endl;

    cout << "___________________________________________________________________________" << endl;
    
    return 0;
}