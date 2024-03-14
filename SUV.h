#pragma once

#include "Automobil.h"

class SUV : public Automobil
{
public:
    SUV(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
        int putere);
    SUV(const SUV &obj); // copy constructor
    ~SUV();              // destructor
    void printDetails() const override;
};