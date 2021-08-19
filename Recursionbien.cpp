/*
Andrea Serrano Diego
19/Agosto/2021

Ejercicios de Recursividad

*/

#include <iostream>

using namespace std;

int suma_digitos(int);

int main(int argc, const char** argv)
{
    int numero;

    /* Pedir al usuario que ingrese un número entero */
    std::cout << "Entre el número entero: " << std::endl;
    cin>> numero;

    /* Sumar los dígitos del número e imprimir el resultado */
    std::cout << "La suma de los dígitos es = " << suma_digitos(numero) << std::endl;
    return 0;
}

/*
Paso 1:
n = 123
resto = 123 % 10 = 3
n = 123 / 10 = 12
suma_digitos(123)

Paso 2:
n = 12 
resto 12 % 10 = 2
n = 12/10 = 1
3 + suma_digitos(12)

Paso 3: 
n = 1
resto = 1 % 10 = 1
n = 1/ 10 = 0
1
2 + 1 = 3
3 + 3 = 6


*/
int suma_digitos(int n)
{
    int resto = n % 10;
    n = n / 10;
    if (n == 0)
    {
        return resto;
    }
    else
    {
        return resto + suma_digitos(n);  
    }  
}