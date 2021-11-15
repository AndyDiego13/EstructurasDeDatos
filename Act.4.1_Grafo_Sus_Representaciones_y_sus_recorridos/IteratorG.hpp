/*
    "IteratorG.hpp"
    
    Created by:
    Serrano Diego Andrea - A01028728
    Garcia Puebla Diego Fernando - A01028597 

    Fecha: 14/11/2021
*/

#pragma once
#include <iostream>

class IteratorG
{
    public:
        virtual int next() = 0;
        virtual bool hNext() const = 0;
        virtual bool newConec() const = 0;
        virtual int beforeCur() const = 0;

};