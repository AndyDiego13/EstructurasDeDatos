/*
García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 21/09/2021
*/

#include<iostream>
#include <fstream>
#include <sstream>
#include "Record.hpp"



class Datos
{
    public:
    string path;
    vector<Record> conexiones;
    Datos();

    void leerDatos(string path);

    void imprimirDatos();

    int compararPorFecha(Record a, Record b);
    int compararPorNombreOrigen(Record a, Record b);
    int compararPornNombreDestino(Record a, Record b);

}