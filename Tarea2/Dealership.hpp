/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <string>
#include <vector>

class Dealership
{
    private:
    std::string name;
    std::string lastName;
    std::string ine;
    int earnings;

    public:
    Dealership();
    std::string getName();
    std::string getLastName();
    std::string getIne();
    int getEarnings();
    void menu();

};