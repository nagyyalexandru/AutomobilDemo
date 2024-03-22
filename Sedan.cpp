#include "Sedan.h"
#include <iostream>

Sedan::Sedan() : Automobil("", "Sedan", "", "", 0)
{
    std::cout << "Sedan()" << std::endl;
}

Sedan::Sedan(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "sedan", tractiune, echipare, putere)
{
    std::cout << "Sedan(const string, const string, const string, int)" << std::endl;
}

Sedan::Sedan(const Sedan &obj) : Automobil(obj)
{
    std::cout << "Sedan(const Sedan &obj)" << std::endl;
}

Sedan &Sedan::operator=(const Sedan &obj)
{
    std::cout << "Sedan operator=  // (copy assignment operator)" << std::endl;
    if (this != &obj)
    {
        Automobil::operator=(obj); // call the copy-assignment operator of Base class
    }

    return *this;
}

// Move constructor
Sedan::Sedan(Sedan &&obj) : Automobil(obj)
{
    // Copy base class members
    combustibil = obj.combustibil;
    caroserie = obj.caroserie;
    tractiune = obj.tractiune;
    echipare = obj.echipare;
    putere = obj.putere;

    // Transfer ownership of VIN
    VIN = obj.VIN;
    obj.VIN = nullptr;
}

// Move assignment operator
Sedan &Sedan::operator=(Sedan &&obj)
{
    if (this != &obj)
    {
        // Copy base class members
        combustibil = obj.combustibil;
        caroserie = obj.caroserie;
        tractiune = obj.tractiune;
        echipare = obj.echipare;
        putere = obj.putere;

        // Release current resources
        delete VIN;

        // Transfer ownership of VIN
        VIN = obj.VIN;
        obj.VIN = nullptr;
    }
    return *this;
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