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
    std::cout << "VIN : " << sedan.getVIN() << std::endl << std::endl;

    return 0;
}