#include "Coupe.h"
#include <iostream>

int Coupe::objCount = 0;

Coupe::Coupe(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "coupe", tractiune, echipare, putere)
{                                    
    ++objCount;

    if (objCount > COUPE_MAX_OBJ_COUNT)
    {
        throw std::logic_error("Error: Object creation exceeded for Coupe");
    }

    std::cout << "Coupe()" << std::endl;
}

Coupe::Coupe(const Coupe &obj) : Automobil(obj)
{
    std::cout << "Coupe(const Coupe &obj)" << std::endl;
}

Coupe::~Coupe()
{
    objCount--;
    std::cout << "~Coupe()" << std::endl;
}

void Coupe::printDetails() const
{
    std::cout << "Tip: Coupe (sport)" << std::endl;
    Automobil::printDetails();
}