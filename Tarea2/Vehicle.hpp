/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

 ///se puede modelar con herencia
 // clases venta, clase autos, clase comprador
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
    private:
    string code;
    string brand;
    int model;
    int km;
    bool sold;

    public:
    Vehicle(string code, string brand, int model, int km);
    string getCode();
    string getBrand();
    int getModel();
    int getKm();
    bool itsSold();
    void display();

};

Vehicle::Vehicle(string _code, string _brand, int _model, int _km)
{
    code = _code;
    brand = _brand;
    model = _model;
    km = _km;
}

string Vehicle::getCode()
{
    return code;
}

string Vehicle::getBrand()
{
    return brand;
}

int Vehicle::getModel()
{
    return model;
}

int Vehicle::getKm()
{
    return km;
}

bool Vehicle::itsSold()
{
    sold = true;
}

void Vehicle::display()
{
    std::cout << "Code: " << code << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Km: " << km << std::endl;
    std::cout << "Status: " << sold << std::endl;
}