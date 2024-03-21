#pragma once

#include "Automobil.h"

class Sedan : public Automobil
{
public:
    Sedan();
    Sedan(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
          int putere);

    // Rule - of - three
    Sedan(const Sedan &obj);        // copy constructor
    Sedan &operator=(const Sedan &obj); // copy-assignment operator
    ~Sedan();                       // destructor
    void printDetails() const override;
};