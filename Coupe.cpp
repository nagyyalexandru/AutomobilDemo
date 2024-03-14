#include "Coupe.h"
#include <iostream>

Coupe::Coupe(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "coupe", tractiune, echipare, putere)
{
    std::cout << "Coupe()" << std::endl;
}

Coupe::Coupe(const Coupe &obj) : Automobil(obj)
{
    std::cout << "Coupe(const Coupe &obj)" << std::endl;
}

Coupe::~Coupe()
{
    std::cout << "~Coupe()" << std::endl;
}

void Coupe::printDetails() const
{
    std::cout << "Tip: Coupe (sport)" << std::endl;
    Automobil::printDetails();
}