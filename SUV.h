#pragma once

#include "Automobil.h"

class SUV : public Automobil
{
public:
    SUV();
    SUV(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
        int putere);                // constructor

    // Rule - of - three
    SUV &operator=(const SUV &obj); // copy-assignment operator
    SUV(const SUV &obj);            // copy constructor
    ~SUV();                         // destructor

    void printDetails() const override;
};