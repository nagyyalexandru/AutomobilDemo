#pragma once

#include "Automobil.h"

#define COUPE_MAX_OBJ_COUNT 1

class Coupe : public Automobil
{
private:
    static int objCount;

public:
    Coupe(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
          int putere);
    Coupe(const Coupe &obj); // copy constructor
    ~Coupe();                // destructor
    void printDetails() const override;
};