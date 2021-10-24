#include <iostream>

class Fruit {
private:
    std::string name;
    std::string color;
public:
    Fruit();
    void setName(std::string);
    std::string getName();
    void setColor(std::string);
    std::string getColor();
    ~Fruit();
};

Fruit::Fruit() {};
Fruit::~Fruit() {};
void Fruit::setName(std::string name) { this->name = name; };
std::string Fruit::getName() { return name; };
void Fruit::setColor(std::string color) { this->color = color; };
std::string Fruit::getColor() { return color; };

class Apple : public Fruit {    
public:
    Apple(std::string);
};

Apple::Apple(std::string color) {
    this->setName("apple");
    this->setColor(color);
};

class Banana : public Fruit {
private:
    
public:
    Banana();
};

Banana::Banana() {
    this->setName("banana"); 
    this->setColor("yellow"); 
}

class GrannySmith : public Apple {
public:
    GrannySmith();
};

GrannySmith::GrannySmith() : Apple("green") {
    this->setName("Granny Smith " + this->getName());
}

int main() {
    using namespace std;

    Apple a("red");
    Banana b;
    GrannySmith c;

    cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

    return 0;
}