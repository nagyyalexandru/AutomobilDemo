#pragma once

#include "Automobil.h"

class Sedan : public Automobil
{
public:
    Sedan();                            // default constructor
    Sedan(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
          int putere);                  // parametrized constructor

    // Rule - of - five
    Sedan(const Sedan &obj);            // copy constructor
    Sedan &operator=(const Sedan &obj); // copy-assignment operator
    Sedan(Sedan &&obj);                 // move constructor
    Sedan &operator=(Sedan &&obj);      // move assignment operator
    ~Sedan();                           // destructor
    void printDetails() const override;
};