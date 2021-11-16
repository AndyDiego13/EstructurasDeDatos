/*
    Situacion Problema - Ataques Cibernéticos
    ConexionesComputadora.hpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/

#ifndef GraphR4_hpp
#define GraphR4_hpp

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>

template <class T>
class VertexG
{
    private:
        T val;
        std::vector<int> adj;
    
    public:

        ~VertexG() {};
        VertexG() {};
        VertexG(T _val)
        {
            val = _val;
        }

        T getVal()
        {
            return val;
        }

        void setVal(T _val)
        {
            val = _val;
        }

        std::vector<int> getAdj()
        {
            return adj;
        }

        

};

#endif // !GraphR4_hpp
