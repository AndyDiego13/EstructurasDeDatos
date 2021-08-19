/*
Andrea Serrano Diego
19/Agosto/2021

Ejercicios de Recursividad

*/

#include <iostream>
#include <string>
#include <regex>

using namespace std;

int suma_digitos(int);
bool palindromo(string cadena, unsigned long izquierda, unsigned int derecha);

int main(int argc, const char** argv)
{
    int numero;

    /* Pedir al usuario que ingrese un número entero */
    std::cout << "Entre el número entero: " << std::endl;
    cin>> numero;

    /* Sumar los dígitos del número e imprimir el resultado */
    std::cout << "La suma de los dígitos es = " << suma_digitos(numero) << std::endl;

    string cadena;

    std::cout << "Entra una cadena de caracteres: " << std::endl;
    getline(cin, cadena);
    std::cout << "Cadena: " << cadena << std::endl;

    /*Eliminar los espacios en blanco */
    auto cadena_sin_espacios = regex_replace(cadena, regex("\\s+"), "");

    /* Invocar a la función recursiva */
    bool es_palindromo = palindromo(cadena_sin_espacios, 0, cadena_sin_espacios.length()- 1);

    /* mostrar resultado */
    if (es_palindromo)
    {
        std::cout << "La frase es un palíndromo." << std::endl;
    }
    else
    {
        std::cout << "La frase no es palíndromo." << std::endl;
    }

    std::cout << std::endl;






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

bool palindromo(string cadena, unsigned long izquierda, unsigned int derecha)
{
    if (izquierda >= derecha)
    {
        return true;
    }
    else if (cadena[izquierda] != cadena[derecha])
    {
        return false;
    }
    else
    {
        return palindromo(cadena, izquierda + 1, derecha - 1);
    }
    
}