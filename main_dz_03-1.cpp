#include <iostream>

#ifndef PI
#define PI 3.14;
#endif

class Figure
{
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure {
protected:
    double l_side;
    double s_side;
    double height;
public:
    Parallelogram(double _long_side = 0, double _height = 0) : l_side(_long_side), height(_height) {};
    ~Parallelogram() {};
    double area() override;
};

double Parallelogram::area() {
    return this->l_side * this->height;
}

class Circle : public Figure {
private:
    double radius;
public:
    Circle(double _radius) : radius(_radius) {};
    ~Circle() {};
    double area() override;
};

double Circle::area() {
    return (this->radius * this->radius) * PI;
}

class Rectangle : public Parallelogram {
public:
    Rectangle(double _width, double _height) : Parallelogram(_width, _height) {};
    double area() override;
};

double Rectangle::area() {
    return this->l_side * this->height;
}

class Square : public Parallelogram {
public:
    Square(double _side) : Parallelogram(_side) {};
    double area() override;
};

double Square::area() {
    return this->l_side * this->l_side;
}

class Rhombus : public Parallelogram {
public:
    Rhombus(double _long_diag, double _short_diag) : Parallelogram(_long_diag, _short_diag) {};
    double area() override;
};

double Rhombus::area() {
    return this->l_side * this->height;
}

int main() {
    using namespace std;

    Circle c0(2.0);
    cout << "AREA: " << c0.area() << endl;

    Rectangle r0(2.0, 1.0);
    cout << "AREA: " << r0.area() << endl;
    Square s0(2.0);
    cout << "AREA: " << s0.area() << endl;
    Rhombus rm0(2.0, 3.0);
    cout << "AREA: " << rm0.area() << endl;

    return 0;
}