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
    std::cout << "-- Detalii SUV --" << std::endl;
    suv.printDetails();
    std::cout << "VIN : " << suv.getVIN() << std::endl
              << std::endl;

    return 0;
}