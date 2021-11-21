/*
    Situacion Problema - Ataques Cibernéticos
    UserFila.hpp

    Created by:  
    - Serrano Diego Andrea (A01028728)
    - García Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 05 / 10 /2021

*/

#ifndef UserFila_hpp
#define UserFila_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <ctime>


class UserFila 
{
    public:

        std::string fecha;
        std::string hora;
        std::string ipOrigen;
        std::string puertoOrigen;
        std::string nombreOrigen;
        std::string ipDestino;
        std::string puertoDestino;
        std::string nombreDestino;
    

        int origenPuerto;
        int destinoPuerto;
    
        //Constructor
        UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD)
        {
            fecha = f;
            hora = h;
            ipOrigen = iO;

            if (pO == "-")
            {
                origenPuerto = 0;
            }
            else
            {
                try
                {
                    origenPuerto = stoi(pO);
                }
                catch(const std::invalid_argument& ia)
                {
                    origenPuerto = 0;
                    std::cout << "error" << pO << std::endl;
                }
            
            }

            nombreOrigen = nO;
            ipDestino = iD;

            if (pD == "-")
            {
                destinoPuerto = 0;
            }
            else
            {
                try
                {
                    destinoPuerto = stoi(pD);
                }
                catch(const std::invalid_argument& ia)
                {
                    destinoPuerto = 0;
                    std::cout << "error" << pD <<std::endl;
                }
            }
            nombreDestino = nD;
        }
        //UserFila(){}
    
        //destructor
        ~UserFila(){}
    
        //sobrecarga de operador para imrimir y poder ser ocupado en otras clases
        friend std::ostream & operator<<(std::ostream & os, const UserFila & userFila)
        {
        
            os << userFila.fecha << " - ";
            os << userFila.hora << " - ";
            os << userFila.ipOrigen << " - ";
            os << userFila.puertoOrigen << " - ";
            os << userFila.nombreOrigen << " - ";
            os << userFila.ipDestino << " - ";
            os << userFila.puertoDestino << " - ";
            os << userFila.nombreDestino << " - ";
            os << endl;
    
    
            return os;

        }
           
        //Obtener Fecha
        string getFecha()
        {
            return fecha;
        }

        //Obtener Hora
        string getHora()
        {
            return hora;
        }   

        //Obtener Ip Origen
        string getIpO()
        {
            return ipOrigen;
        }

        string getPuertoO()
        {
            return puertoOrigen;
        }

        //Obtener nombre del puerto origen
        string getNombreO()
        {
            return nombreOrigen;
        }

        //Obtener ip Destino
        string getIpD()
        {
            return ipDestino;
        }

        //Obtener nombre del puerto destino
        string getPuertoD()
        {
            return puertoDestino;
        }

        string getNombreD()
        {
            return nombreDestino;
        }

        //para comparar todo por fecha

        static bool fecha_asc(UserFila co, UserFila b)
        {
            return co.fecha < b.fecha;
        }
};


#endif /* UserFila_hpp */