/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/
///se puede modelar con herencia
// clases venta, clase autos, clase comprador
#ifndef Automovil_hpp
#define Automovil_hpp

#include <iostream>
#include <string>
#include <vector>
#include <thread>

class Automovil
{
    protected:
    std::string tipo;

    private:
    std::string code;
    std::string brand;
    int model;
    int km;
    bool sold;
    int earnings;
    std::vector<Automovil> automoviles;
    int automoviles_available;

    public:
    Automovil(std::string _code, std::string _brand, int _model, int _km)
    {
        code = _code;
        brand = _brand;
        model = _model;
        km = _km;
    }
    Automovil();
    ~ Automovil();
    //std::thread automovil(std::string code, std::string brand, int model, int km);
    std::string getCode();
    std::string getBrand();
    int getModel();
    int getKm();
    bool itsSold()
    {
        return true;
    }
    void showCarsByYear(int model)
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

    void showCars()
    {
        for (int i = 0; i < automoviles.size(); i++)
        {
            automoviles[i].display();
        }
    }

    void display()
    {
        std::cout << "Code: " << code << std::endl;
        std::cout << "Brand: " << brand << std::endl;
        std::cout << "Model: " << model << std::endl;
        std::cout << "Km: " << km << std::endl;
    }

    void details()
    {
        std::cout << "Model: " << model << "Brand: " << brand << "Code: " << code << "Km: " << km <<std::endl;
    }
    void sale()
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
    int getEarnings()
    {
        return earnings;
    }

};

#endif // !Automovil_hpp