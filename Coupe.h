#pragma once

#include "Automobil.h"

#define COUPE_MAX_OBJ_COUNT 1

class Coupe : public Automobil
{
private:
    static int objCount;

public:
    Coupe();                            // default constructor
    Coupe(const std::string &combustibil, const std::string &tractiune, const std::string &echipare,
          int putere);                  // parametrized constructor
          
    // Rule - of - five
    Coupe(const Coupe &obj);            // copy constructor
    Coupe &operator=(const Coupe &obj); // copy-assignment operator
    Coupe(Coupe &&obj);                 // move constructor
    Coupe &operator=(Coupe &&obj);      // move assignment operator
    ~Coupe();                           // destructor

    void printDetails() const override;
};