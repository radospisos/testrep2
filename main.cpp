#include <iostream>

using namespace std;

class Car {
public:
    string brakes, accelerator, tank;

    void info() {
        cout << "Brakes: " << brakes << "\nAccelerator: " << accelerator << "\nTank: " << tank << endl << endl << endl << endl;
    }
};

class CarBuilder {
protected:
    Car* c;

public:
    CarBuilder(): c(0) {}

    virtual ~CarBuilder() {}
    virtual void createCar() = 0;
    virtual void build_brakes() = 0;
    virtual void build_engine() = 0;
    virtual Car* getCar() { return c; }
};

class TeslaBuilder : public CarBuilder {
public:
    void createCar() { c = new Car; }
    void build_brakes() { c->brakes = "Well"; }
    void build_engine() { c->accelerator = "Perfect"; c->tank = "Charging"; }
};

class LanosBuilder : public CarBuilder {
public:
    void createCar() { c = new Car; }
    void build_brakes() { c->brakes = "Shit"; }
    void build_engine() { c->accelerator = "SHIT"; c->tank = "Petrol"; }
};

class Director {
public:
    Car* createCar(CarBuilder* builder) {
        builder->createCar();
        builder->build_brakes();
        builder->build_engine();
        return (builder->getCar());
    }
};

int main()
{
    Director* dir;

    Car* tesla = dir->createCar(new TeslaBuilder);
    tesla->info();

    Car* lanos = dir->createCar(new LanosBuilder);
    lanos->info();
    return 0;
}
