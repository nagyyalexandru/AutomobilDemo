#include <iostream>
#include "Automobil.h"
#include "Sedan.h"
#include "Coupe.h"
#include "SUV.h"

int main(void)
{
    // Crearea si afisarea unui automobil de tip Sedan
    Sedan sedan("benzina", "fata", "standard", 150);
    sedan.setVIN(123456);
    std::cout << "-- Detalii Sedan --" << std::endl;
    sedan.printDetails();
    std::cout << "VIN : " << sedan.getVIN() << std::endl
              << std::endl;

    // Crearea si afisarea unui automobil de tip SUV
    SUV suv("motorina", "integrala", "premium", 220);
    suv.setVIN(456321);
    std::cout << "-- Detalii SUV (1st object) --" << std::endl;
    suv.printDetails();
    std::cout << "VIN : " << suv.getVIN() << std::endl
              << std::endl;

    // Copiem obiectul 'suv' intr-o variabila 'suvCpy' de tip SUV
    SUV suvCpy = suv;       // apelam copy constructor
    std::cout << "-- Detalii SUV (copy-object) --" << std::endl;
    suvCpy.printDetails();
    std::cout << "VIN : " << suvCpy.getVIN() << std::endl
              << std::endl;

    SUV suv2;
    suv2 = suv;     // apelam copy-assignment operator

    // Crearea si afisarea unui automobil de tip Coupe
    Coupe coupe("benzina", "spate", "sports-line", 310);
    coupe.setVIN(987123);
    std::cout << "-- Detalii Coupe --" << std::endl;
    coupe.printDetails();
    std::cout << "VIN : " << coupe.getVIN() << std::endl
              << std::endl;

    // object of type Coupe is limited at 1 instance, so exception will be thrown
    // Coupe coupe2("benzina", "integrala", "trend-line", 290);
    return 0;
}