#include <iostream>

class Person {
private:
    std::string name;
    int age;
    char gendre;
    int weight;

public:
    Person(std::string name, int age, char gendre, int weight) :
        name(name), age(age), gendre(gendre), weight(weight) {};
    void set_name(std::string);
    std::string get_name();
    void set_age(int);
    int get_age();
    void set_gendre(char);
    char get_gendre();
    void set_weight(int);
    int get_weight();
};

void Person::set_name(std::string name) { this->name = name; };
std::string Person::get_name() { return name; };
void Person::set_age(int age) { this->age = age; };
int Person::get_age() { return age; };
void Person::set_gendre(char gendre) { this->gendre = gendre; };
char Person::get_gendre() { return gendre; };
void Person::set_weight(int weight) { this->weight = weight; };
int Person::get_weight() { return weight; };

class Student : public Person {
private:
    int year;
    int counter = 0;
public:
    Student(std::string name, int age, char gendre, int weight, int year) :
        Person(name, age, gendre, weight) {
            this->year = year;
        };
    void set_year(int);
    void print();
    friend int get_counter(const Student& st) { return st.counter; };
    friend void set_counter(Student&, int);
};

void Student::set_year(int year) {
    this->year = year;
};
void Student::print() {
    std::cout << "STUDENT " << this->counter << ": name -> " << get_name();
    std::cout << " age -> " << get_age();
    std::cout << " gendre -> " << get_gendre();
    std::cout << " weight -> " << get_weight();
    std::cout << " year - " << this->year << std::endl;
};
void set_counter(Student& st, int number) { st.counter = number; };

int main() {
    using namespace std;
    Student s1("Igor", 25, 'm', 82, 2018);
    Student s2("Anna", 20, 'f', 65, 2020);
    Student s3("Vladimir", 23, 'm', 79, 2020);

    Person* students[] = {
        &s1,
        &s2,
        &s3
    };

    for (int i = 0; i < 3; i++) {
        set_counter(*(Student *)students[i], ++i);
        static_cast <Student*> (students[--i])->print();
    }

    return 0;
}