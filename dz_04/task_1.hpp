#ifndef TASK_1_HPP
#define TASK_1_HPP

#include <cassert>

class ArrayInt {
private:
    int length;
    int* data;
    void change(int, int);
public:
    ArrayInt() : length(0), data(nullptr) {}
    ArrayInt(int _length) : length(_length) {
        assert(length >= 0);

        if (length > 0) {
            data = new int[length];
        } else {
            data = nullptr;
        }        
    }
    ~ArrayInt() { delete[] data; }
    void erase();
    int get_length();
    int& operator[] (int);
    void resize(int);
    void insert_before(int, int);
    void push_back(int);
    void delete_before(int);
    void pop_back();
    void pop_front();
    void sort();
    void print();
};

void ArrayInt::erase() {
    delete[] data;

    data = nullptr;
    length = 0;
}
int ArrayInt::get_length() { return length; }
int& ArrayInt::operator[] (int index) {
    assert(index >= 0 && index < length);
    return data[index];
}
void ArrayInt::resize(int new_capacity) {
    if (new_capacity == length)
        return;
    if(new_capacity <= 0) {
        erase();
        return;
    }

    int* new_data = new int[new_capacity];
    if(length > 0) {
        int elements_to_copy = (new_capacity > length) ? length : new_capacity;
        for(int index = 0; index < elements_to_copy; ++index) {
            new_data[index] = data[index];
        }
    }

    delete[] data;
    data = new_data;
    length = new_capacity;
}
void ArrayInt::insert_before(int value, int index) {
    assert(index >= 0 && index <= length);

    int *new_data = new int[length + 1];
    for (int before=0; before < index; ++before)
        new_data[before] = data[before];
        
    new_data [index] = value;
    
    for (int after=index; after < length; ++after)
        new_data[after+1] = data[after];
        
    delete[] data;
    data = new_data;
    ++length;
}
void ArrayInt::push_back(int value) {
    insert_before(value, length);
}
void ArrayInt::print() {
    using namespace std;

    cout << "[";
    for (int i = 0; i < length; ++i) {
        cout << " " << data[i];
    }
    cout << " ]" << endl;
}
void ArrayInt::delete_before(int index) {
    assert(index >= 0 && index <= length);

    int *new_data = new int[length - 1];
    for (int before = 0; before < index; ++before) {
        new_data[before] = data[before];
    }

    for (int after = index; after < length - 1; ++after) {
        new_data[after] = data[after + 1];
    }

    delete[] data;
    data = new_data;
    --length;
}
void ArrayInt::pop_back() {
    delete_before(length);
}
void ArrayInt::pop_front() {
    delete_before(0);
}
void ArrayInt::change(int r, int l) {
    int tmp = data[r];
    data[r] = data[l];
    data[l] = tmp;
}
void ArrayInt::sort() {
    int r_index;
    int l_index;

    for (int i = 0; i < length - 1; ++i) {
        for (int j = i + 1; j > 0; --j) {
            r_index = j - 1;
            l_index = j;
            if (data[r_index] > data[l_index]) {
                change(r_index, l_index);
            } else {
                break;
            }
        }
    }
}

#endif