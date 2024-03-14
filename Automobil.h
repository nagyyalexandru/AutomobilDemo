#ifndef AUTOMOBIL_H
#define AUTOMOBIL_H

#include <iostream>
#include <string>

class Automobil
{
protected:
    std::string combustibil;
    std::string caroserie;
    std::string tractiune;
    std::string echipare;
    int putere;
    int *VIN;

public:
    Automobil(const std::string &combustibil, const std::string &caroserie, const std::string &tractiune,
              const std::string &echipare, int putere);     // constructor
    Automobil(const Automobil &obj);    // copy constructor
    ~Automobil();   // destructor
    void setVIN(int vin);
    int getVIN() const;
    virtual void printDetails() const;
};

#endif