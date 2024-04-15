#include "Automobil.h"

// constructor
Automobil::Automobil(const std::string &combustibil, const std::string &caroserie, const std::string &tractiune, const std::string &echipare, int putere)
    : combustibil(combustibil), caroserie(caroserie), tractiune(tractiune), echipare(echipare), putere(putere), VIN(std::make_unique<int>())
{
    std::cout << "Automobil()" << std::endl;
}

// copy constructor
Automobil::Automobil(const Automobil &obj)
    : combustibil(obj.combustibil), caroserie(obj.caroserie), tractiune(obj.tractiune), echipare(obj.echipare), putere(obj.putere), VIN(std::make_unique<int>(*obj.VIN))
{
    std::cout << "Automobil(const Automobil &obj)" << std::endl;
}

// copy assignment operator
Automobil &Automobil::operator=(const Automobil &obj)
{
    std::cout << "Automobil operator=  // (copy assignment operator)" << std::endl;
    if (this != &obj)
    {
        combustibil = obj.combustibil;
        caroserie = obj.caroserie;
        tractiune = obj.tractiune;
        echipare = obj.echipare;
        putere = obj.putere;
        *VIN = *(obj.VIN);
    }
    return *this;
}

// move constructor
Automobil::Automobil(Automobil &&obj)
    : combustibil(std::move(obj.combustibil)), caroserie(std::move(obj.caroserie)), tractiune(std::move(obj.tractiune)),
      echipare(std::move(obj.echipare)), putere(obj.putere), VIN(std::move(obj.VIN))
{
    obj.VIN = nullptr;
}

// move assignment operator
Automobil &Automobil::operator=(Automobil &&obj)
{
    if (this != &obj)
    {
        combustibil = std::move(obj.combustibil);
        caroserie = std::move(obj.caroserie);
        tractiune = std::move(obj.tractiune);
        echipare = std::move(obj.echipare);
        putere = obj.putere;
        VIN = std::move(obj.VIN);
        obj.VIN = nullptr;
    }
    return *this;
}

// destructor
Automobil::~Automobil()
{
    std::cout << "~Automobil()" << std::endl;
}

// VIN setter
void Automobil::setVIN(int vin)
{
    *VIN = vin;
}

// VIN getter
int Automobil::getVIN() const
{
    return *VIN;
}

// print details method
void Automobil::printDetails() const
{
    std::cout << "Combustibil: " << combustibil << "\nCaroserie: " << caroserie << "\nTractiune: " << tractiune << "\nPutere: " << putere << "\nEchipare: " << echipare << std::endl;
}
