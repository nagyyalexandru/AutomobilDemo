#include "Coupe.h"
#include <iostream>

int Coupe::objCount = 0;

Coupe::Coupe() : Automobil("", "Coupe", "", "", 0)
{
    ++objCount;

    if (objCount > COUPE_MAX_OBJ_COUNT)
    {
        throw std::logic_error("Error: Object creation exceeded for Coupe");
    }

    std::cout << "Coupe()" << std::endl;
}

Coupe::Coupe(const std::string &combustibil, const std::string &tractiune,
             const std::string &echipare, int putere) : Automobil(combustibil,
                                                                  "coupe", tractiune, echipare, putere)
{
    ++objCount;

    if (objCount > COUPE_MAX_OBJ_COUNT)
    {
        throw std::logic_error("Error: Object creation exceeded for Coupe");
    }

    std::cout << "Coupe(const string, const string, const string, int)" << std::endl;
}

Coupe::Coupe(const Coupe &obj) : Automobil(obj)
{
    std::cout << "Coupe(const Coupe &obj)" << std::endl;
}

Coupe &Coupe::operator=(const Coupe &obj)
{
    if (this != &obj)
    {
        Automobil::operator=(obj); // call the copy-assignment operator of Base class
    }

    return *this;
}

// Move constructor
Coupe::Coupe(Coupe &&obj) : Automobil(obj)
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
Coupe &Coupe::operator=(Coupe &&obj)
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