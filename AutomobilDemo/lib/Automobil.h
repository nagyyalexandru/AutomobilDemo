#pragma once

#include <iostream>
#include <string>
#include <memory>

class Automobil
{
public:
    Automobil(const std::string &combustibil, const std::string &caroserie, const std::string &tractiune,
              const std::string &echipare, int putere); // constructor

    // Rule - of - five :
    Automobil(const Automobil &obj);                    // copy constructor
    Automobil &operator=(const Automobil &obj);         // copy-assignment operator
    Automobil(Automobil && obj);                        // move constructor
    Automobil& operator=(Automobil && obj);             // move assignment operator
    ~Automobil();                                       // destructor

    void setVIN(int vin);
    int getVIN() const;
    virtual void printDetails() const;

protected:
    std::string combustibil;
    std::string caroserie;
    std::string tractiune;
    std::string echipare;
    int putere;
    std::unique_ptr<int> VIN;
};