#include <iostream>
#include <cmath>

// 1.
class Power {
private:
	double x = 1.0;
	double y = 1.0;
public:
	void set(double, double);
	void calculate();
};

void Power::set(double value1, double value2) {
	x = value1;
	y = value2;
};

void Power::calculate() {
	printf("\nResult value1 ^ value2 = %0.2f\n", pow(x, y));
};

// 2.
class RGBA {
private:
	std::uint8_t m_red;
	std::uint8_t m_green;
	std::uint8_t m_blue;
	std::uint8_t m_alpha;
public:
	RGBA() : m_red(0), m_green(0), m_blue(0), m_alpha(255) {};
	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) {
		this->m_red = red;
		this->m_green = green;
		this->m_blue = blue;
		this->m_alpha = alpha;
	};
	void print();
};

void RGBA::print() {
	printf("\nRED: %d", m_red);
	printf("\nGREEN: %d", m_green);
	printf("\nBLUE: %d", m_blue);
	printf("\nALPHA: %d", m_alpha);
	printf("\n");
};

// 3.
class Stack {
private:
	int stack_array[10] = {0};
	int stack_count = 0;
public:
	void reset();
	bool push(int);
	int pop();
	void print();
};

void Stack::reset() {
	for (int i = 0; i < 10; i++) {
		stack_array[i] = 0;
	}
	stack_count = 0;
};
void Stack::print() {
	if (stack_count == 0) {
		printf("()\n");
	} else {
		printf("( ");
		for (int i = 0; i < stack_count; i++) {
			printf("%d ", stack_array[i]);
		}
		printf(")\n");
	}
};
bool Stack::push(int value) {
	if (stack_count == 10) {
		return false;
	} else if (stack_count == 9) {
		stack_array[stack_count++] = value;
		return false;
	} else {
		stack_array[stack_count++] = value;
		return true;
	}
};
int Stack::pop() {
	return stack_array[--stack_count];
};
 
int main() {
	using namespace std;
	
	cout << "Homework #1" << endl;

	// 1.
	Power defaultP;
	defaultP.calculate();

	double value1;
	double value2;
	printf("\nEnter value1: ");
	std::cin >> value1;
	printf("\nEnter value2: ");
	std::cin >> value2;

	Power customP;
	customP.set(value1, value2);
	customP.calculate();

	// 2.
	cout << "\nObject default:";
	RGBA obj1;
	obj1.print();

	cout << "\nObject custom:";

	RGBA obj2(123,34,204,186);
	obj2.print();

	// 3.
	Stack stack;
    stack.reset();
    stack.print();
    
    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();
    
    stack.pop();
    stack.print();
    
    stack.pop();
    stack.pop();
    stack.print();

	return 0;
}
