#include <iostream>
#include <cmath>

class Fraction {
private:
    std::int16_t numerator;
    std::int16_t denumerator;
public:
    Fraction(std::int16_t _numerator, std::int16_t _denumerator) : 
        numerator(_numerator), denumerator(_denumerator) {
            if (_denumerator == 0) {
                std::cout << "ERROR!!!" << std::endl;
                // здесь надо бросить исключение
                // сейчас приложение просто упадёт
                delete this;
            }            
        };
    ~Fraction() {
        // std::cout << "Fraction deleted." << std:: endl;
    };
    friend std::ostream& operator<< (std::ostream& c, Fraction f) {
        if (f.numerator < 0 || f.denumerator < 0) {
            c << "-" << abs(f.numerator) << "/" << abs(f.denumerator);
        } else {
            c << f.numerator << "/" << f.denumerator;
        }
        return c;
    };
    std::int16_t get_numerator() { return this->numerator; };
    std::int16_t get_denumerator() { return this->denumerator; };
    Fraction operator+ (Fraction f) const {
        if (denumerator == f.denumerator) {
            return Fraction(numerator + f.numerator, denumerator);
        } else {
            std::int16_t temp_numerator = (numerator * f.denumerator) + (f.numerator * denumerator);
            return Fraction(temp_numerator, denumerator * f.denumerator);
        }
    };
    Fraction operator- (Fraction f) {
        if (denumerator == f.denumerator) {
            return Fraction(numerator - f.numerator, denumerator);
        } else {
            std::int16_t temp_numerator = (numerator * f.denumerator) - (f.numerator * denumerator);
            return Fraction(temp_numerator, denumerator * f.denumerator);
        }
    };
    Fraction operator* (Fraction f) {
        return Fraction(numerator * f.numerator, denumerator * f.denumerator);
    };
    Fraction operator/ (Fraction f) {
        return Fraction(numerator * f.denumerator, denumerator * f.numerator);
    };
    Fraction operator- () const {
        if (numerator < 0) {
            return Fraction(-numerator, denumerator);   
        } else {
            return Fraction(numerator, -denumerator);
        }
    };
};
bool operator== (Fraction &f1, Fraction &f2) {
    if (f1.get_denumerator() == f2.get_denumerator()) {
        return f1.get_numerator() == f2.get_numerator() ? true : false;
    } else {
        return (f1.get_numerator() * f2.get_denumerator()) == (f2.get_numerator() * f1.get_denumerator()) ? true : false;
    }        
};
bool operator!= (Fraction &f1, Fraction &f2) {
    return f1 == f2 ? false : true;
};
bool operator< (Fraction &f1, Fraction &f2) {
    if (f1.get_denumerator() == f2.get_denumerator()) {
        return f1.get_numerator() < f2.get_numerator() ? true : false;
    } else {
        return (f1.get_numerator() * f2.get_denumerator()) < (f2.get_numerator() * f1.get_denumerator()) ? true : false;
    }        
};
bool operator>= (Fraction &f1, Fraction &f2) {
    return f1 < f2 ? false : true;
};
bool operator> (Fraction &f1, Fraction &f2) {
    if (f1.get_denumerator() == f2.get_denumerator()) {
        return f1.get_numerator() > f2.get_numerator() ? true : false;
    } else {
        return (f1.get_numerator() * f2.get_denumerator()) > (f2.get_numerator() * f1.get_denumerator()) ? true : false;
    }        
};
bool operator<= (Fraction &f1, Fraction &f2) {
    return f1 > f2 ? false : true;
};
std::ostream& operator<< (std::ostream &c, bool *b) {
    if (*b > 0) {
        c << "TRUE";
    } else {
        c << "FALSE";
    }
    return c;
}

int main() {
    using namespace std;

    Fraction f0(1, 2);
    Fraction f1(-2, 3);
    Fraction f4(3, -5);

    cout << f0 + f1 << endl;
    cout << f0 - f1 << endl;
    cout << f0 * f1 << endl;
    cout << f0 / f1 << endl;
    cout << -f0 << endl;
    cout << -f4 << endl;

    Fraction f2(6, 9);
    Fraction f3(2, 3);
    bool t1 = f2 == f3; 
    cout << &t1 << endl;
    bool t2 = f2 != f3; 
    cout << &t2 << endl;
    bool t3 = f2 < f3; 
    cout << &t3 << endl;
    bool t4 = f2 > f3; 
    cout << &t4 << endl;
    bool t5 = f2 >= f3; 
    cout << &t5 << endl;
    bool t6 = f2 <= f3; 
    cout << &t6 << endl;

    return 0;
}