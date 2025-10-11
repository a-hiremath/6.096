//
// Created by adity on 10/5/2025.
//

#include <iostream>
#include "geometry.h"


using namespace std;


// Point Methods

Point::Point(int x, int y) {
    this->x=x;
    this->y=y;
}

int Point::getX() const {
    return x;
}

int Point::getY() const {
    return y;
}

void Point::setX(const int new_x) {
    x = new_x;
}

void Point::setY(const int new_y) {
    y = new_y;
}


// PointArray Methods

PointArray::PointArray() : p(nullptr), len(0) {

}

PointArray::PointArray(const Point points[], const int size) : len(size)  {

     p = new Point[size];

    for (int i = 0; i < size; i++) {
        p[i] = points[i];
    }
}

int PointArray::getLen() {
    return len;
}

Point& PointArray::getPointArray(int index) {
    return p[index];
}

PointArray::PointArray(const PointArray &pv) {
    Point * points = new Point[pv.len];

    for (int i = 0; i < pv.len; i++) {
        points[i] = pv.p[i];
    }

    p = points;
    len = pv.len;
}

PointArray::~PointArray() {
    delete[] p;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void PointArray::resize(int n) {

    Point * pArray = new Point[n]; // new allocates in heap, requires manual deallocation after execution

    for (int i = 0; i < min(len, n); i++) {
        pArray[i] = p[i];
    }

    delete[] p;
    p = pArray;
    len = n;

}

void PointArray::push_back(const Point &pt) {

    int oldLen = len;
    resize(oldLen + 1); // increase the size of the array by one element
    p[oldLen] = pt;

}

void PointArray::insert(const int position, const Point &pt) {

    Point pt1 = pt;

    if (position < 0 || position > len) {
        cout << "i\'m not letting that slide lil bro watch your tone";
        return;
    }

    int oldLen = len; // save the original length of the array
    resize(oldLen + 1); // increase the size of the array by one element

    for (int i = oldLen - 1; i >= position; i--) {
        p[i + 1] = p[i]; // shift values in the array one element forward until reaching position passed in argument
    }

    p[position] = pt1;


    // int oldLen = len;
    // resize(len + 1); // increase the size of the array by one element
    //
    // for (int i = oldLen; i != position; i--) {
    //     p[oldLen - i] = p[oldLen - i - 1]; // move the values of the array forward by one until reaching the insert position
    // }
    //
    // p[position] = pt; // set the value of the array at position to be equal to the point passed in the argument

}


void PointArray::remove(const int pos) {

    // 0) boundary check

    if (pos < 0 || pos >= len) {
        cout << "hella nah boy";
        return;
    }

    // 1) starting from index position, shift elements to the left
    for (int i = pos; i < len - 1; i++) {
        p[i] = p[i+1]; // set the element at position i to be equal to the element at index i+1
    }

    // 2) decrease the length of the array by one element

    resize(len - 1);

}

const int PointArray::getSize() const {
    return len;
}

void PointArray::clear() {
    resize(0);
}

Point* PointArray::get(const int position) {

    // 1) return a null pointer if called with an index larger than the array size

    if (position < 0 || position >= len) {
        return nullptr;
    }

    return p + position;

}

const Point *PointArray::get(const int position) const {
    if (position < 0 || position >= len) {
        return nullptr;
    }

    return p + position;
}

    // 4.5.1: if PointArray is a const, then only its const member functions can be called, requiring the addition of an overloaded function of type const


int main() {

    Point a(1,1);
    Point b(1,2);
    Point c(1,3);

    Point boi[] = {a,b,c};

    PointArray jawn(boi, 3);
    jawn.push_back(Point(7,8));
    std::cout << "\nsize=" << jawn.getLen();                 // expect 4
    std::cout << "\nlast=("
              << jawn.getPointArray(3).getX() << ", "
              << jawn.getPointArray(3).getY() << ")";        // expect (7,8)




    return 0;
}