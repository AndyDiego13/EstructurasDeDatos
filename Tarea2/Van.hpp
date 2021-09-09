/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <string>

using namespace std;

class Van
{
    private:
    string code;
    string brand;
    int model;
    int km;
    string traction;
    bool sold;

    public:
    Van(string code, string brand, int model, int km, string traction);
    string getCode();
    string getBrand();
    int getModel();
    int getKm();
    string getTraction();
    bool itsSold();
    void display();

};

Van::Van (string _code, string _brand, int _model, int _km, string _traction)
{
    code = _code;
    brand = _brand;
    model = _model;
    km = _km;
    traction = _traction;
}

string Van::getCode()
{
    return code;
}

string Van::getBrand()
{
    return brand;
}

int Van::getModel()
{
    return model;
}

int Van::getKm()
{
    return km;
}

string Van::getTraction()
{
    return traction;
}

bool Van::itsSold()
{
    sold = true;
}

void Van::display()
{
    std::cout << "Code: " << code << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Km: " << km << std::endl;
    std::cout << "Traction: " << traction << std::endl;
    std::cout << "Status: " << sold << std::endl;
}