/*
Andrea Serrano Diego
16/Agosto/2021

Ejercicios de Recursividad

*/

#include <iostream>


using namespace std;

int num3;

void sumaDigitos()
{
    int w;
    int sumarDigitos = 0;

    while (num3 != 0)
    {
        w = num3 % 10;
        num3 /= 10;
        sumarDigitos += w;
    }

    std::cout << "La suma de los digitos es: " << sumarDigitos << std::endl;
}

void invertir()
{
    string pala;

    std::cout << "Ingresa la palabra que quieres invertir: " << std::endl;
    //getline(cin, fra);
    cin >> pala;

    reverse(pala.begin(), pala.end());

    std::cout << "Esta es la palabra invertida: " << pala << std::endl;
}

void palindromo()
{
    char palabra[50];
    int i;
    int j;

    std::cout << "Ingrese una palabra para saber si es palíndromo: " << std::endl;
    cin >> palabra;

    int lengthpal1 = strlen(palabra) - 1;
    char palabra2[50];

    for (i = lengthpal1, j = 0; i >= 0 ; i--, j++)
    {
        palabra2[j] = palabra[i];
    }

    if (strcmp(palabra, palabra2))
    {
        std::cout << "La palabra: " << palabra << " no es un palíndromo" << std::endl;
    }
    else
    {
        std::cout << "La palabra: " << palabra << " es un palíndromo" << std::endl;
    }
}	

int main()
{
    std::cout << "Ingresa el número al cual le quieres sumar los digitos: " << std::endl;
    cin>> num3;
    sumaDigitos();

    invertir();

    palindromo();
}