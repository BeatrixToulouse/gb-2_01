#include <iostream>

class Car {
private:
    std::string company;
    std::string model;
public:
    Car(std::string _company, std::string _model) : company(_company), model(_model) {
        std::cout << "Car constructor" << std::endl;
    };
    ~Car() {
        std::cout << "Car destructor" << std::endl;
    };
};

class PassengerCar : virtual public Car {
public:
    PassengerCar(std::string _company, std::string _model) : Car(_company, _model) {
        std::cout << "PassengerCar constructor" << std::endl;
    };
    ~PassengerCar() {
        std::cout << "PassengerCar destructor" << std::endl;
    };
};

class Bus : virtual public Car {
public:
    Bus(std::string _company, std::string _model) : Car(_company, _model) {
        std::cout << "Bus constructor" << std::endl;
    };
    ~Bus() {
        std::cout << "Bus destructor" << std::endl;
    };
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(std::string _company, std::string _model) :
        PassengerCar(_company, _model), 
        Bus(_company, _model), 
        Car(_company, _model) {
            std::cout << "Minivan constructor" << std::endl;
        }
    ~Minivan() {
        std::cout << "Minivan destructor" << std::endl;
    };
};

int main() {
    using namespace std;

    PassengerCar p_car("Nissan", "XTrail");
    Bus bus("Ikarus", "Grand");
    Minivan van("Suzuki", "Delica");

    return 0;
}