#include "SUV.h"

// constructor
SUV::SUV() : Automobil("", "SUV", "", "", 0) {
    std::cout << "SUV()" << std::endl;
}

// parametrized constructor
SUV::SUV(const std::string &combustibil, const std::string &tractiune, const std::string &echipare, int putere)
    : Automobil(combustibil, "SUV", tractiune, echipare, putere) {
    std::cout << "SUV(const string, const string, const string, int)" << std::endl;
}

// copy constructor
SUV::SUV(const SUV &obj) : Automobil(obj) {
    std::cout << "SUV(const SUV &obj)" << std::endl;
}

// copy assignment operator
SUV& SUV::operator=(const SUV &obj) {
    std::cout << "SUV operator=  // (copy assignment operator)" << std::endl;
    if (this != &obj) {
        Automobil::operator=(obj);
    }
    return *this;
}

// move constructor
SUV::SUV(SUV &&obj) : Automobil(std::move(obj)) {
    std::cout << "SUV(SUV &&obj)" << std::endl;
}

// move assignment operator
SUV& SUV::operator=(SUV &&obj) {
    std::cout << "SUV operator=(&&obj)" << std::endl;
    if (this != &obj) {
        Automobil::operator=(std::move(obj));
    }
    return *this;
}

// destructor
SUV::~SUV() {
    std::cout << "~SUV()" << std::endl;
}

void SUV::printDetails() const {
    std::cout << "Tip: SUV (Sports Utility Vehicle)" << std::endl;
    Automobil::printDetails();
}
