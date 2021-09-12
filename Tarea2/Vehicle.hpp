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

class Vehicle
{
    private:
    std::string code;
    std::string brand;
    int model;
    int km;
    bool sold;

    public:
    Vehicle(std::string code, std::string brand, int model, int km);
    std::string getCode();
    std::string getBrand();
    int getModel();
    int getKm();
    bool itsSold();
    void display();

};

Vehicle::Vehicle(std::string _code, std::string _brand, int _model, int _km)
{
    code = _code;
    brand = _brand;
    model = _model;
    km = _km;
}

std::string Vehicle::getCode()
{
    return code;
}

std::string Vehicle::getBrand()
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