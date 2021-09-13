
#include "Automovil.hpp"
#include <iostream>

Automovil::Automovil(std::string _code, std::string _brand, int _model, int _km)
{
    code = _code;
    brand = _brand;
    model = _model;
    km = _km;
    
}

void Automovil::addAutomovil(Automovil new_automovil)
{
    automoviles.push_back(new_automovil);
    automoviles_available++;
}

void Automovil::showCars()
{
    for (int i = 0; i < automoviles.size(); i++)
    {
        automoviles[i].display();
    }
}

void Automovil::showCarsByYear(int model)
{
    for (int i = 0; i < automoviles.size(); i++)
    {
        int autoYear = automoviles[i].getModel();
        if (autoYear == model)
        {
            automoviles[i].display();
        }   
    } 
}

void Automovil::display()
{
    std::cout << "Code: " << code << std::endl;
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Model: " << model << std::endl;
    std::cout << "Km: " << km << std::endl;
}
std::ostream & Automovil::print(std::ostream & os) const
{
    os << "Auto: " << code << std::endl;
    return os;
}

int Automovil::getEarnings()
{
    return earnings;
}

void Automovil::details()
{
    std::cout << "Model: " << model << "Brand: " << brand << "Code: " << code << "Km: " << km <<std::endl;
}


Automovil sale()
{
    auto dhip = new Automovil();
    std::cout << "What vehicle want: " << std::endl;
    int t;
    std::cin >> t;

    bool vehicleOut = false;

    for (int i = 0; i < 10; i++)
    {
        if (dhip[i].getEarnings() == t)
        {
            std::cout << "Vehicle selected." << std::endl;
            std::cout << "Vehicle purchase." << std::endl;

            vehicleOut = true;

            std::cout << "Details of your purchase." << std::endl;
            dhip[i].details();
            return dhip[i];
        }
        
    }
    
}

std::ostream & operator << (std::ostream & os, const Automovil & coche)
{
    return coche.print(os);
}
