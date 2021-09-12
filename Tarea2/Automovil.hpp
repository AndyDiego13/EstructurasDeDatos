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

    public:
    Automovil();
    std::string getCode();
    std::string getBrand();
    int getModel();
    int getKm();
    bool itsSold();
    virtual std::ostream & print(std::ostream &) const;
    friend std::ostream & operator << (std::ostream &, const Automovil &);

};