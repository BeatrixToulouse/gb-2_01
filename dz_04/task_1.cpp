#include <iostream>
#include "task_1.hpp"

int main() {
    int size = 20;
    ArrayInt a(size);

    for (int i = 0; i < size; ++i) {
        a[i] = rand() % 50 + 1;
    }

    a.print();
    a.sort();
    a.print();
    a.push_back(30);
    a.print();
    a.pop_back();
    a.delete_before(3);
    a.pop_front();
    a.print();
    return 0;
}