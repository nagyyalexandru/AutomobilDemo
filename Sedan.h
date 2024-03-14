#pragma once

#include "Automobil.h"

class Sedan : public Automobil
{
public:
    Sedan(const std::string & combustibil, const std::string & tractiune, const std::string & echipare,
    int putere);
    Sedan(const Sedan & obj);   // copy constructor
    ~Sedan();   // destructor
    void printDetails() const override;
};