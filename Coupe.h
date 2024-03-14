#pragma once

#include "Automobil.h"

class Coupe : public Automobil
{
public:
    Coupe(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
          int putere);
    Coupe(const Coupe &obj); // copy constructor
    ~Coupe();                // destructor
    void printDetails() const override;
};