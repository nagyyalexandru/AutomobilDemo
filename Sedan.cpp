#include "Sedan.h"
#include <iostream>

Sedan::Sedan(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "sedan", tractiune, echipare, putere)
{

}

Sedan::Sedan(const Sedan &obj) : Automobil(obj)
{

}

Sedan::~Sedan()
{

}

void Sedan::printDetails() const {
    std::cout << "Tip: Sedan" << std::endl;
    Automobil::printDetails();
}