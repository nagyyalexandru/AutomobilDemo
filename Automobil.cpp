#include "Automobil.h"

// constructor
Automobil::Automobil(const std::string &combustibil, const std::string &caroserie, const std::string &tractiune, const std::string &echipare, int putere)
{
    std::cout << "Automobil()" << std::endl;
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
    std::cout << "Automobil(const Automobil &obj)" << std::endl;
    combustibil = obj.combustibil;
    caroserie = obj.caroserie;
    tractiune = obj.tractiune;
    echipare = obj.echipare;
    putere = obj.putere;
    VIN = new int;
    *VIN = *(obj.VIN); // VIN copy
}

// copy-assignment operator
Automobil &Automobil::operator=(const Automobil &obj)
{
    std::cout << "Automobil operator=  // (copy assignment operator)" << std::endl;
    if (this != &obj)
    {
        delete VIN;
        combustibil = obj.combustibil;
        caroserie = obj.caroserie;
        tractiune = obj.tractiune;
        echipare = obj.echipare;
        putere = obj.putere;
        VIN = new int;
        *VIN = *(obj.VIN);
    }

    return *this;
}

// destructor
Automobil::~Automobil()
{
    std::cout << "~Automobil()" << std::endl;
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

void Automobil::printDetails() const
{
    std::cout << "Combustibil: " << combustibil << "\nCaroserie: " << caroserie << "\nTractiune: " << tractiune << "\nPutere: " << putere << "\nEchipare: " << echipare << std::endl;
}