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

Moto::Moto(string _code, string _brand, int _model, int _km, string _cylinder)
{
    code = _code;
    brand  = _brand;
    model = _model;
    km = _km;
    cylinder = _cylinder;
}

string Moto::getCode()
{
    return code;
}

string Moto::getBrand()
{
    return brand;
}

int Moto::getModel()
{
    return model;
}

int Moto::getKm()
{
    return km;
}

string Moto::getCylinder()
{
    return cylinder;
}

bool Moto::itsSold()
{
    sold = true;
}

void Moto::display()
{
    std::cout << "Code: " << code << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Km: " << km << std::endl;
    std::cout << "Status: " << sold << std::endl;
}