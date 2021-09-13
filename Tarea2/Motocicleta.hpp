/*
    Actividad 1.2 Algoritmos de Busqueda y Ordenamiento

    Diego Fernando García Puebla    A01028597
    Andrea Serrano Diego            A01028728

    8/Sept/2021
*/

#include <iostream>
#include "Automovil.hpp"

class Motocicleta: public Automovil
{
    private:
    std::vector <Motocicleta> mts;
    public:
    Motocicleta();
    void showMotocicletas();
    virtual std::ostream & print(std::ostream &) const;
    friend std::ostream & operator << (std::ostream &, const Motocicleta &);
};