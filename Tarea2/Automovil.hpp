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
    Automovil();
    std::string getCode();
    std::string getBrand();
    int getModel();
    int getKm();
    bool itsSold();
    void addAutomovil(Automovil new_automovil);
    void showCarsByYear(int model);
    void showCars();
    void display();
    void details();
    void sale();
    int getEarnings();
    virtual std::ostream & print(std::ostream &) const;
    friend std::ostream & operator << (std::ostream &, const Automovil &);

};
#endif // !Automovil_hpp