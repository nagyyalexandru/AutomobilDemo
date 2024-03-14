#include "SUV.h"
#include <iostream>

SUV::SUV(const std::string &combustibil, const std::string &tractiune,
         const std::string &echipare, int putere) : Automobil(combustibil,
                                                              "SUV", tractiune, echipare, putere)
{

}

SUV::SUV(const SUV &obj) : Automobil(obj)
{

}

SUV::~SUV()
{
    
}

void SUV::printDetails() const
{
    std::cout << "Tip: SUV (Sport Utility Vehicle)" << std::endl;
    Automobil::printDetails();
}