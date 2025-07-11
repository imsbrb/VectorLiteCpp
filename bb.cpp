#include<iostream>
using namespace std;

class Vector {
private:
    int* elements;
    int size_;
    int capacity_;

    void resizeVector(int newcapacity) {
        int* nArray = new int[newcapacity];
        for (int i = 0; i < size_; i++) {
            nArray[i] = elements[i];
        }
        delete[] elements;
        elements = nArray;
        capacity_ = newcapacity;
    }

public:
    Vector() {
        size_ = 0;
        capacity_ = 0;
        elements = nullptr;
    }

    Vector(int currentcapacity) {
        size_ = 0;
        capacity_ = currentcapacity;
        elements = new int[capacity_];
    }

    ~Vector() {
        delete[] elements;
    }

    int size() const {
        return size_;
    }

    int capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ == 0;
    }

    void push_back(int value) {
        if (size_ == capacity_) {
            resizeVector(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        elements[size_++] = value;
    }

    void pop_back() {
        if (size_ == 0) {
            cout << "Vector is Empty!!" << endl;
            return;
        }
        size_--;
        if (size_ < capacity_ / 2 && capacity_ > 10) {
            resizeVector(capacity_ / 2);
        }
    }

    int& front() {
        if (size_ == 0) {
            cout << "Vector is Empty!!" << endl;
            static int dummy;
            return dummy;
        }
        else {
            return elements[0];
        }
    }

    int& back() {
        if (size_ == 0) {
            cout << "Vector is Empty!!" << endl;
            static int dummy;
            return dummy;
        }
        else {
            return elements[size_ - 1];
        }
    }

    void insert(int index, int value) {
        if (index < 0 || index > size_) {
            cout << "Error: Invalid index" << endl;
            return;
        }
        if (size_ == capacity_) {
            resizeVector(capacity_ == 0 ? 1 : capacity_ * 2);
        }
        for (int i = size_; i > index; --i) {
            elements[i] = elements[i - 1];
        }
        elements[index] = value;
        size_++;
    }

    int& at(int index) {
        if (index < 0 || index >= size_) {
            cout << "Error: Index out of bounds" << endl;
            static int dummy;
            return dummy;
        }
        return elements[index];
    }

    void erase(int index) {
        if (index < 0 || index >= size_) {
            cout << "Error: Index out of bounds" << endl;
            return;
        }
        for (int i = index; i < size_ - 1; ++i) {
            elements[i] = elements[i + 1];
        }
        size_--;
        if (size_ < capacity_ / 2 && capacity_ > 10) {
            resizeVector(capacity_ / 2);
        }
    }

    void swap(Vector& other) {

        int* tempElements = elements;
        elements = other.elements;
        other.elements = tempElements;


        int tempSize = size_;
        size_ = other.size_;
        other.size_ = tempSize;


        if (size_ > capacity_) {
            int tempCapacity = capacity_;
            capacity_ = other.capacity_;
            other.capacity_ = tempCapacity;
        }
        else if (other.size_ > other.capacity_) {
            int tempCapacity = other.capacity_;
            other.capacity_ = capacity_;
            capacity_ = tempCapacity;
        }
    }

    void clear() {
        delete[] elements;
        elements = nullptr;
        size_ = 0;
        capacity_ = 10;
        elements = new int[capacity_];
    }

    int* begin() const {
        return elements;
    }

    int* end() const {
        return elements + size_;
    }
};

int main() {

    Vector v1(15);
    cout << "Adding elements 10,50,70" << endl;


    v1.push_back(10);
    v1.push_back(50);
    v1.push_back(70);


    cout << "Removing elements 50 and 70" << endl;
    v1.pop_back();
    return 0;
}
