#include <iostream>
#include <string>

// Abstract Product: Car
class Car
{
public:
    virtual void getInfo() = 0;
    virtual void getDoors() = 0;
    virtual void start() = 0;
    virtual ~Car() {}
};

// Concrete Products: Sedan, SUV, Coupe
class Sedan : public Car
{
public:
    void getInfo() override { std::cout << "This car is a Sedan." << std::endl; }
    void getDoors() override { std::cout << "Sedan has 4 doors." << std::endl; }
    void start() override { std::cout << "Starting Sedan." << std::endl << std::endl; }
};

class SUV : public Car
{
public:
    void getInfo() override { std::cout << "This car is a SUV." << std::endl; }
    void getDoors() override { std::cout << "SUV has 5 doors." << std::endl; }
    void start() override { std::cout << "Starting SUV." << std::endl << std::endl; }
};

class Coupe : public Car
{
public:
    void getInfo() override { std::cout << "This car is a Coupe." << std::endl; }
    void getDoors() override { std::cout << "Coupe has 2 doors." << std::endl; }
    void start() override { std::cout << "Starting Coupe." << std::endl << std::endl; }
};

// Abstract Factory: Car Factory
class CarFactory
{
public:
    virtual Car* createCar() = 0;
    virtual ~CarFactory() {}    
};

// Concret Factories: SedanFactory, SuvFactory, CoupeFactory
class SedanFactory : public CarFactory
{
public:
    Car *createCar() override { return new Sedan(); }
};

class SuvFactory : public CarFactory
{
public:
    Car *createCar() override { return new SUV(); }
};

class CoupeFactory : public CarFactory
{
public:
    Car *createCar() override { return new Coupe(); }
};


int main(void)
{
    // Create Factories
    CarFactory *sedanFactory = new SedanFactory();
    CarFactory *suvFactory = new SuvFactory();
    CarFactory *coupeFactory = new CoupeFactory();

    // Create Cars
    Car *sedanCar = sedanFactory->createCar();
    Car *suvCar = suvFactory->createCar();
    Car *coupeCar = coupeFactory->createCar();

    // Use Cars
    sedanCar->getInfo();
    sedanCar->getDoors();
    sedanCar->start();

    suvCar->getInfo();
    suvCar->getDoors();
    suvCar->start();

    coupeCar->getInfo();
    coupeCar->getDoors();
    coupeCar->start();

    // Cleanup Resources
    delete sedanCar;
    delete suvCar;
    delete coupeCar;
    delete sedanFactory;
    delete suvFactory;
    delete coupeFactory;
    return 0;
}
