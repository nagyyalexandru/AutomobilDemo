#include <iostream>
#include "Automobil.h"
#include "Sedan.h"
#include "Coupe.h"
#include "SUV.h"
#include "Utility.h"

int main(void)
{
    /* Crearea si afisarea unui automobil de tip Sedan */
    Sedan sedan1("Benzina", "Fata", "Standard", 170);
    sedan1.setVIN(123456);
    std::cout << "-- Detalii sedan1 --" << std::endl;
    sedan1.printDetails();
    std::cout << "VIN : " << sedan1.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    /* Crearea si afisarea unui automobil de tip Coupe */
    Coupe coupe1("Benzina", "Spate", "Sport-Line", 310);
    coupe1.setVIN(987123);
    std::cout << "-- Detalii coupe1 --" << std::endl;
    coupe1.printDetails();
    std::cout << "VIN : " << coupe1.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    /* Object of type Coupe is limited at 1 instance, so exception will be thrown 
       if we un-comment the following line */
    // Coupe coupe2("benzina", "integrala", "trend-line", 290);

    /* Crearea si afisarea unui automobil de tip SUV */
    SUV suv1("Motorina", "Integrala", "Premium", 290);
    suv1.setVIN(223344);
    std::cout << "-- Detalii suv1 --" << std::endl;
    suv1.printDetails();
    std::cout << "VIN : " << suv1.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    SUV suv2 = suv1;       // apelam copy constructor
    std::cout << "-- Detalii SUV (copy-object) --" << std::endl;
    suv2.printDetails();
    std::cout << "VIN : " << suv2.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    SUV suv3;        // cream obiectul suv3 pentru a exemplifica folosirea copy-assignment-operator
    suv3 = suv1;     // apelam copy-assignment operator
    std::cout << "-- Detalii SUV (folosind copy-assignment operator) --" << std::endl;
    suv3.printDetails();
    std::cout << "VIN : " << suv3.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    /* Mutarea unui obiect SUV */
    std::cout << "Mutarea unui obiect SUV:" << std::endl;
    SUV suv4 = std::move(suv1);
    std::cout << "VIN obiect Mutat SUV: " << suv4.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    /* Mutarea unui obiect Sedan folosind move-assignment operator */
    std::cout << "Mutarea unui obiect Sedan (folosind move-assignment operator):" << std::endl;
    Sedan sedan2;
    sedan2 = std::move(sedan1);
    std::cout << "VIN obiect Mutat Sedan (folosind move-assignment operator): " << sedan2.getVIN() << std::endl << std::endl;
    Utility::PrintCharacter('-');

    Utility::Hello("Hello from main.cpp !");

    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << "Average of numbers is : " << Utility::Average(nums) << std::endl << std::endl;

    return 0;
}