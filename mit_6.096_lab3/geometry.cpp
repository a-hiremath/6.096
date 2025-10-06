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

PointArray::PointArray() : p(nullptr) {

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



int main() {

    Point a(1,1);
    Point b(1,2);
    Point c(1,3);

    Point boi[] = {a,b,c};

    PointArray jawn(boi, 3);

    cout << endl << jawn.getLen();

    // for (int i=0; i < jawn.getLen(); i++) {
    //     cout << jawn[i].getX();
    // }

    cout << endl << jawn.getPointArray(2).getY();

    PointArray d = jawn;

    cout << endl << d.getPointArray(2).getY();

    d.getPointArray(2).setY(1);

    cout << endl << d.getPointArray(2).getY();



    return 0;
}