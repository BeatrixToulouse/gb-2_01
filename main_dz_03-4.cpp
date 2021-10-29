#include <iostream>

enum class Suit { heart, diamonds, club, spade};
enum class Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10, aceG = 11};

class Card {
private:
    Suit suit;
    Value value;
    bool is_back;
public:
    Card() {};
    Card(Suit _s, Value _v, bool _is_back) : suit(_s), value(_v), is_back(_is_back) {};
    ~Card() {};
    Suit get_suit();
    Value get_value();
    void flip();
    friend std::ostream& operator<< (std::ostream &c, const Card &card);
};

void Card::flip() {
    is_back = !is_back;
}
Value Card::get_value() { return value; };
Suit Card::get_suit() { return suit; };
std::ostream& operator<< (std::ostream &c, const Card &card) { 
    c << &card.value << " " << &card.suit << " " << card.is_back;
    return c;
}

int main() {
    using namespace std;

    Card c(Suit::club, Value::king, 0);
    cout << c << endl;

    return 0;
}