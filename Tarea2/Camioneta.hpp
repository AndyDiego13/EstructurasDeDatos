/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include <string>
#include "Automovil.hpp"

class Camioneta: public Automovil
{
    private:
    std::string traction;
    std::vector <Camioneta> camioneta;

    public:
    Camioneta();
    void showCamionetas();
    
    virtual std::ostream & print(std::ostream &) const;
    friend std::ostream & operator << (std::ostream &, const Camioneta &);
};