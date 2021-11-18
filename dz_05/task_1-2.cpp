#include <iostream>

template<class T>
class Pair1 {
   T f;
   T s;
public:
   Pair1(T _first, T _second) : f(_first), s(_second) {}
   ~Pair1() {}
   T first() const {
       return this->f;
   }
   T second() const {
       return this->s;
   }
};

template<class T1, class T2>
class Pair {
   T1 f;
   T2 s;
public:
   Pair(T1 _first, T2 _second) : f(_first), s(_second) {}
   ~Pair() {}
   T1 first() const {
       return this->f;
   }
   T2 second() const {
       return this->s;
   }
};

int main() {
    using namespace std;

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

    Pair<int, double> pair(6, 7.8);
    cout << "Pair: " << pair.first() << ' ' << pair.second() << '\n';

    const Pair<double, int> pair2(3.4, 5);
    cout << "Pair: " << pair2.first() << ' ' << pair2.second() << '\n';
    return 0;
}