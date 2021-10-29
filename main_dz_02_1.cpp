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
    std::string get_name() const;
    void set_age(int);
    int get_age() const;
    void set_gendre(char);
    char get_gendre() const;
    void set_weight(int);
    int get_weight() const;
};

void Person::set_name(std::string name) { this->name = name; };
std::string Person::get_name() const { return name; };
void Person::set_age(int age) { this->age = age; };
int Person::get_age() const { return age; };
void Person::set_gendre(char gendre) { this->gendre = gendre; };
char Person::get_gendre() const { return gendre; };
void Person::set_weight(int weight) { this->weight = weight; };
int Person::get_weight() const { return weight; };

class Student : public Person {
private:
    int year;
    std::int16_t student_id;
    static int counter;
public:
    Student(std::string name, int age, char gendre, int weight, int year) :
        Person(name, age, gendre, weight) {
            ++Student::counter;
            this->student_id = Student::counter;
            this->year = year;
        };
    void set_year(int);
    std::string print() const;
    static int get_counter() { return Student::counter; };
};
int Student::counter = 0;
void Student::set_year(int year) {
    this->year = year;
};
std::string Student::print() const {
    return "STUDENT " + std::to_string(student_id) + ": name -> " + get_name() +
    " age -> " + std::to_string(get_age()) +
    " gendre -> " + std::to_string(get_gendre()) +
    " weight -> " + std::to_string(get_weight()) +
    " year - " + std::to_string(this->year) + "\n";
};
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
        // static_cast <Student*> (students[i])->set_counter();
        std::cout << static_cast <Student*> (students[i])->print();
    }

    cout << "COUNTER: " << Student::get_counter() << endl;

    return 0;
}