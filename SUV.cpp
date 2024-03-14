#include "SUV.h"
#include <iostream>

SUV::SUV(const std::string &combustibil, const std::string &tractiune,
         const std::string &echipare, int putere) : Automobil(combustibil,
                                                              "SUV", tractiune, echipare, putere)
{
    std::cout << "SUV()" << std::endl;
}

SUV::SUV(const SUV &obj) : Automobil(obj)
{
    std::cout << "SUV(const SUV &obj)" << std::endl;
}

SUV::~SUV()
{
    std::cout << "~SUV()" << std::endl;
}

void SUV::printDetails() const
{
    std::cout << "Tip: SUV (Sport Utility Vehicle)" << std::endl;
    Automobil::printDetails();
}