/*
 Administrador.hpp

García Puebla Diego Fernando - A01028597
Serrano Diego Andrea - A01028728

Fecha de entrega: 23/09/2021
*/


#ifndef Administrador_hpp
#define Administrador_hpp

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include "UserFila.hpp"
#include "Ordenamiento_reto1.hpp"
#include <vector>
#include <iterator>
#include <algorithm>


using namespace std;

class Administrador{
    private:
        string fileName;
        vector<UserFila> registros;
        
    public:
        long int size = registros.size();
        Administrador(vector<UserFila> r): registros(r){};
        Administrador(){}
        ~Administrador(){}

        
        auto read_fila()
        {
            /* Crear un vector de vector de strings */
            vector<UserFila> lineas;

            /* Crear un input filestream para leer el archivo CSV */
            ifstream file(fileName);

            /* Verificar si no hubo error al abrir el archivo */
            if(!file.is_open()) throw runtime_error("No se puede abrir el archivo");

            /* Definir variable que almacena cada línea */
            string linea;
    
            /* Leer datos línea a línea */
            while(getline(file, linea))
            {
                /* Crear un steam de la línea */
                stringstream ss(linea);
    
                /* Variables que almacenan cada campo leído */
                string f;
                string h;
                string iO;
                string pO;
                string nO;
                string iD;
                string pD;
                string nD;
                
        
                /* Iterar sobre la línea para extraer cada campo */
                getline(ss, f, ',');
                getline(ss, h, ',');
                getline(ss, iO, ',');
                getline(ss, pO, ',');
                getline(ss, nO, ',');
                getline(ss, iD, ',');
                //esto no funciona porque yo quiero ingresar un int y getline no se ocupara ints
                getline(ss, pD, ',');
                getline(ss, nD, ',');
                
        
        
                /* Insertar la fila con los campos separados en un vector */
                lineas.push_back(UserFila( f, h, iO, pO, nO, iD, pD, nD));
            }
            

            /* Cerrar el archivo */
            file.close();
            

            /* Regresar el vector de líneas leídas */
            return lineas;
        }
        
        

        int contarRegistros(){
        //atributo de clase
    
            std::cout<< "Numero de registros: " << size << std::endl;
        }
        int contarXdia(string dia){
    
            int cont = 0;
    
            for (int i = 0; i < size; i++){
                if(registros[i].getFecha() == dia){
                    cont = cont +1;
                }
            }
    
            return cont;
        }

    void busqNombre(string nombre){
        int cont = 0;
    
        for (int i = 0; i < size; i++){
            if(registros[i].getNombreO() == nombre+".reto.com" ){
                //cout << registros[i];
                cont = cont +1;
            }
        }
        cout << " Valores encontrados : " << cont << " para : "<<  nombre << endl;
    }

    void busqNombreMail(string nombreDestino){
        int cont = 0;
    
        for (int i = 0; i < size; i++){
            if(registros[i].getNombreD() == nombreDestino + ".com" ){
                //cout << registros[i];
                cont = cont +1;
            }
        }
        cout << " Valores encontrados : " << cont << " para : "<<  nombreDestino << endl;
    }

    void busqRedInterna(){

        int i=0;
        //lo que ocurre es que se voltea la dirección IP de origin y todo lo que está en el útilmo octeto se borra

        while (i<size)
        {
            string ip_found=registros[i].getIpO();
            std::reverse(ip_found.begin(), ip_found.end());
            int pos = ip_found.find(".");
            string cut = ip_found.substr(pos + 1);
            std::reverse(cut.begin(), cut.end());
            cout<< cut<<endl;
            i++;
        }
    }

    int busquedaSecuencial( vector<UserFila> d, bool (*condicion)(UserFila r) )
    {
        for(int i = 0; i<d.size(); i++)
        {
            if( condicion(d[i]) ) return i;
        }
        return -1;
    }

    void busqNombreIp(vector<UserFila> d)
    {
        int h = busquedaSecuencial(d, [](UserFila r){return r.getIpO() != "-";});
        std::string iporigen = d[h+1].getIpO();
        for (int i = 0; i < 3; i++) iporigen.pop_back();
        iporigen.append(".212");
        std::cout<< "La ip de la red interna: " << iporigen << std::endl;
    }

    void mostrarMail(){
    
        for (int i = 0; i < size; i++){
                cout << registros[i].getNombreD() << endl;
        }
    
    }
    void busqNombreDestino(string nombre){
    
        int cont = 0;
    
        for (int i = 0; i < size; i++){
            if(registros[i].getNombreD() == nombre ){
                //cout << registros[i];
                cont = cont +1;
            }
        }
        cout << " Valores encontrados : " << cont << " para : "<<  nombre << endl;
    
    }

    void mostrarRangoPuertosD(int inf, int sup){
    
    
        int puertoDesINT;
        int cont = 0;

        for(int j = 0; j < size; j++)
        {
            std::cout << registros[j].getPuertoD() << std::endl;
        }

        for (int i = 0; i < size; i++){
            puertoDesINT =  atoi( registros[i].getPuertoD().c_str() ) ;
            if( inf < puertoDesINT && puertoDesINT < sup ){
                cont = cont + 1;
            }
        }
        cout << " Valores encontrados de los puertos menores a 1000 : " << cont << endl;

    }
      
};

#endif /* Administrador_hpp */