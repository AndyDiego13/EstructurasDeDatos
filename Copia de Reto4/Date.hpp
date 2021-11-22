/*
    Situacion Problema - Ataques Cibernéticos
    Date.hpp

    Created by: 
    - Serrano Diego Andrea (A01028728)
    - Garcia Puebla Diego Fernando (A01028597)
    
    Fecha de realizacion: 18 / 10 /2021

*/
#ifndef Date_hpp
#define Date_hpp

#include <iostream>
#include <ctime>

class Date
{
    public:
        tm date;

        Date(tm date)
        {
            this->date = date;
        }

        friend bool operator == (Date d1, Date d2)
        {
            return(
                d1.date.tm_mday == d2.date.tm_mday &&
                d1.date.tm_mon == d2.date.tm_mon &&
                d1.date.tm_year == d2.date.tm_year
            );
        }

        friend bool operator != (Date d1, Date d2)
        {
            return(
                d1.date.tm_mday != d2.date.tm_mday ||
                d1.date.tm_mon != d2.date.tm_mon ||
                d1.date.tm_year != d2.date.tm_year
            );
        }

        friend bool operator < (Date d1, Date d2)
        {
            return(
                d1.date.tm_mday < d2.date.tm_mday ||
                d1.date.tm_mon < d2.date.tm_mon ||
                d1.date.tm_year < d2.date.tm_year
            );
        }

        std::string toString()
        {
            return std::to_string(this->date.tm_mday) + "/" + std::to_string(this->date.tm_mon + 1) + "/" + std::to_string(this->date.tm_year+1990);
        }

};

#endif // !Date_hpp