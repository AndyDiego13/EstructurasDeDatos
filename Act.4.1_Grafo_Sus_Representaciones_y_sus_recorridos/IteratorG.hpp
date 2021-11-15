#pragma once
#include <iostream>

class IteratorG
{
    public:
        virtual int next() = 0;
        virtual bool hNext() const;
        virtual bool newConec() = 0;
        virtual int antesCur() = 0;

};