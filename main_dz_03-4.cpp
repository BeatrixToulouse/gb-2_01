#include <iostream>

enum class Suit { heart, diamond, club, spade};
enum class Value : int { ace = 1, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, aceG};

std::string suit_to_string(Suit s) {
    switch (s) {
    case Suit::heart:
        return "HEART";
    case Suit::diamond:
        return "DIAMOND";
    case Suit::club:
        return "CLUB";
    case Suit::spade:
        return "SPADE";
    default:
        return "";
    }
}

std::string value_to_string(Value v) {
    switch (v) {
        case Value::ace:
            return "ACE";
        case Value::two:
            return "2";
        case Value::three:
            return "3";
        case Value::four:
            return "4";
        case Value::five:
            return "5";
        case Value::six:
            return "6";
        case Value::seven:
            return "7";
        case Value::eight:
            return "8";
        case Value::nine:
            return "9";
        case Value::ten:
            return "10";
        case Value::jack:
            return "JACK";
        case Value::queen:
            return "qUEEN";
        case Value::king:
            return "KING";
        default:
            return "ACE(11)";
    }
}

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
    bool get_back();
    void flip();
    friend std::ostream& operator<< (std::ostream &c, Card card);
};

void Card::flip() {
    is_back = !is_back;
}
bool Card::get_back() { return is_back; };
Value Card::get_value() { return value; };
Suit Card::get_suit() { return suit; };
std::ostream& operator<< (std::ostream &c, bool *b) {
    if (*b > 0) {
        c << "TRUE";
    } else {
        c << "FALSE";
    }
    return c;
}
std::ostream &operator<< (std::ostream &c, Card card) { 
    c << value_to_string(card.get_value()) << " " << suit_to_string(card.get_suit()) << " " << card.get_back();
    return c;
}

int main() {
    using namespace std;

    Card c(Suit::club, Value::king, 0);
    cout << c << endl;

    return 0;
}