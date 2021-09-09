/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <string>

using namespace std;

class Moto
{
    private:
    string code;
    string brand;
    int model;
    int km;
    string cylinder;
    bool sold;

    public:

    Moto(string code, string brand, int model, int km, string cylinder);
    string getCode();
    string getBrand();
    int getModel();
    int getKm();
    string getCylinder();
    bool itsSold();
    void display();
};