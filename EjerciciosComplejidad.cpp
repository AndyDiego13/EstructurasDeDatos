/*
Andrea Serrano Diego
23/Agosto/2021

Ejercicios de Complejidad

*/

#include <iostream>


using namespace std;

int Fibonacci (int n)
{
	if(n <= 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n-1) + Fibonacci(n-2);
	}
}
/*
int FibonacciIterativo(int n)
{
	int tabla[n];
	if (n <= 1)
	{
		return 1;
	}
	else
	{
		T[0] = 1;
		T[1] = 1;
		for(int i = 2; i < n; ++i)
		{
			T[i] = T[i-1] + T[i-2];
		}
		return T[n];
	}
}
*/
int FibonacciIterativo(int n)
{
	int suma, x, y;
	if (n <= 1) 
	{
		return 1;
	}
	else
	{
		x = 1;
		y = 1;
		for(int i=2; i<n; ++i)
		{
			suma = x + y;
			y = x;
			x = suma;
		}
		return suma;
	}
}


int main() {

    std::cout << Fibonacci(100) << std::endl;
    return 0;
}