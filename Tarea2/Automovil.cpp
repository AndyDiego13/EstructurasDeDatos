
#include "Automovil.hpp"
#include <iostream>

Automovil::Automovil()
{
    tipo = "Auto";
}

void Automovil::addAutomovil(Automovil new_automovil)
{
    automoviles.push_back(new_automovil);
    automoviles_available++;
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

std::ostream & operator << (std::ostream & os, const Automovil & coche)
{
    return coche.print(os);
}
