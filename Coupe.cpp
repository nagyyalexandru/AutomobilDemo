#include "Coupe.h"
#include <iostream>

Coupe::Coupe(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "coupe", tractiune, echipare, putere)
{

}

Coupe::Coupe(const Coupe &obj) : Automobil(obj)
{

}

Coupe::~Coupe()
{

}

void Coupe::printDetails() const
{
    std::cout << "Tip: Coupe (sport)" << std::endl;
    Automobil::printDetails();
}