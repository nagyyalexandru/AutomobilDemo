#pragma once

#include "Automobil.h"

class SUV : public Automobil
{
public:
    SUV();                          // default constructor
    SUV(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
        int putere);                // parametrized constructor

    // Rule - of - five
    SUV &operator=(const SUV &obj); // copy-assignment operator
    SUV(const SUV &obj);            // copy constructor
    SUV(SUV &&obj);                 // move constructor
    SUV &operator=(SUV &&obj);      // move assignment operator
    ~SUV();                         // destructor

    void printDetails() const override;
};