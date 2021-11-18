#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &a) {

    cout << "The length is: " << a.size() << '\n';

    for (int i=0; i<a.size(); i++)
        cout << a[i] << ' ';

    cout << endl;
}


int main() {

    vector<int> test;
    int size = 10;
    test.resize(size);
    int count = 1;

    for (int i = 0; i < size; i++) {
        test[i] = rand() % 5 + 1;
    }
    sort(test.begin(), test.end());
    for (int i = 0; i < test.size() - 1; ++i) {
        if (test[i] != test[i+1]) {
            count++;
        }
    }
    print(test);
    cout << "COUNT = " << count << endl;

    return 0;
}