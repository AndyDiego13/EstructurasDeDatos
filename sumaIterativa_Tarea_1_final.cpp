/*

    Descripción
    Este programa calcula la sumatoria de 1 hasta "n" de manera Iterativa

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    25/Agosto/2021

*/

//Programa que suma n numeros enteros

#include<iostream>

using namespace std;

long int sumaIterativa (int n) // El nivel de complejidad es: O(n) (lineal)
{
    long int resultado = 0;

    for (int i = 1; i<= n ; i++){

        resultado = n*(n+1)/2;  
    }

    return resultado;

}

int main ()
{
    int n;

    cout << "___________________________________________________________________________" << endl;
    cout << "Favor de ingresar el numero total de datos (n): " << endl;
    cin >> n;

    cout << "___________________________________________________________________________" << endl;
    cout << "La suma Iterativa es: " << sumaIterativa(n) << endl;

    cout << "___________________________________________________________________________" << endl;
    


    return 0;
}