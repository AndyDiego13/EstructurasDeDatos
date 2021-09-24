//
//  UserFila.hpp
//  Ataque
//
//  Created by Matías Méndez on 23/09/20.
//  Copyright © 2020 Matías Méndez. All rights reserved.
//

#ifndef UserFila_hpp
#define UserFila_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class UserFila {
private:
    string fecha;
    string hora;
    string ipOrigen;
    string puertoOrigen;
    string nombreOrigen;
    string ipDestino;
    string puertoDestino;
    string nombreDestino;
    
public:
    //constructor
    UserFila(string f, string h, string iO, string pO, string nO, string iD, string pD, string nD):
    fecha(f), hora(h), ipOrigen(iO), puertoOrigen(pO), nombreOrigen(nO), ipDestino(iD),puertoDestino(pD), nombreDestino(nD) {}
    
    //destructor
    ~UserFila(){}
    
    //sobrecarga de operador para imrimir y poder ser ocupado en otras clases
    friend std::ostream & operator<<(std::ostream & os, const UserFila & userFila);
           
    
string getFecha(){
    return fecha;
}

string getHora(){
    return hora;
}

string getIpO(){
    return ipOrigen;
}

string getPuertoO(){
    return puertoOrigen;
}

string getNombreO(){
    return nombreOrigen;
}

string getIpD(){
    return ipDestino;
}

string getPuertoD(){
    return puertoDestino;
}

string getNombreD(){
    return nombreDestino;
}

//para comparar todo por fecha

bool fecha_asc(UserFila co, UserFila b){
    return co.fecha < b.fecha;
}
};


#endif /* UserFila_hpp */