#include "Sedan.h"
#include <iostream>

Sedan::Sedan(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "sedan", tractiune, echipare, putere)
{
    std::cout << "Sedan()" << std::endl;
}

Sedan::Sedan(const Sedan &obj) : Automobil(obj)
{
    std::cout << "Sedan(const Sedan &obj)" << std::endl;
}

Sedan::~Sedan()
{
    std::cout << "~Sedan()" << std::endl;
}

void Sedan::printDetails() const
{
    std::cout << "Tip: Sedan" << std::endl;
    Automobil::printDetails();
}