#include "Automobil.h"

// constructor
Automobil::Automobil(const std::string & combustibil, const std::string & caroserie, const std::string & tractiune,
        const std::string & echipare, int putere)
{
    this->combustibil = combustibil;
    this->caroserie = caroserie;
    this->tractiune = tractiune;
    this->echipare = echipare;
    this->putere = putere;
    VIN = new int;
}

// copy constructor
Automobil::Automobil(const Automobil &obj)
{
    combustibil = obj.combustibil;
    caroserie = obj.caroserie;
    tractiune = obj.tractiune;
    echipare = obj.echipare;
    putere = obj.putere;
    VIN = new int;
    *VIN = *(obj.VIN);  // VIN copy
}

// destructor
Automobil::~Automobil()
{
    delete VIN;
}

void Automobil::setVIN(int vin)
{
    *VIN = vin;
}

int Automobil::getVIN() const
{
    return *VIN;
}