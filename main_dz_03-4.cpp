#include <iostream>
#include <stdio.h>

#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define FALSE "HIDE"
#define TRUE "OPEN"


enum Suit { heart, diamond, club, spade};
enum Value { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack = 10, queen = 10, king = 10, aceG = 11};

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
    std::string get_back() const;
    void flip();
    friend std::ostream& operator<< (std::ostream& c, Value &v);
    friend std::ostream& operator<< (std::ostream& c, Suit s);
    friend std::ostream& operator<< (std::ostream &c, Card &card);
};

void Card::flip() {
    is_back = !is_back;
}
Value Card::get_value() { return value; };
Suit Card::get_suit() { return suit; };
std::ostream& operator<< (std::ostream& c, Value &v) {
    return c << v;
};
std::ostream& operator<< (std::ostream& c, Suit s) {
    switch (s) {
    case Suit::heart:
        return c << HEART;
    case Suit::diamond:
        return c << DIAMOND;
    case Suit::club:
        return c << CLUB;
    case Suit::spade:
        return c << SPADE;
    default:
        return c;
    }
}
std::string show (bool b) {
    if (b == 0) {
        return FALSE;
    } else {
        return TRUE;
    }
}
std::ostream &operator<< (std::ostream &c, Card &card) { 
    c << card.get_value() << " " << card.get_suit() << "  " << show(card.is_back);
    return c;
}

int main() {
    using namespace std;

    Card c(Suit::heart, Value::aceG, 0);
    cout << c << endl;
    c.flip();
    cout << c << endl;

    return 0;
}