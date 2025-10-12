//
// Created by adity on 10/5/2025.
//

#include <iostream>
#include "geometry.h"
#include <cmath>



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


/*
 *
 * SECTION 5
 *
 */

Polygon::Polygon(const Point arr[], int arrLength)
: pArray(arr, arrLength) // initialize pArray with an array of points arr[] and the length of the array
{
    instances++; // increment the polygon instance tracker
}

Polygon::Polygon(const PointArray& ptA) // constructor taking a pre-existing pArr as an argument;
    : pArray(ptA) // member initialization
{
    instances++;
}

int Polygon::getNumPolygons() const {
    return instances;
}

int Polygon::getNumSides() const {


    return pArray.getSize();
}

const PointArray* Polygon::getPoints() const {
    return &pArray;
}



/*
 *
 *  Section 5.4: Rectangle
 *
 */



Point constructorPoints[4];

Point *updateConstructorPoints(const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0)) {
    constructorPoints[0] = p1;
    constructorPoints[1] = p2;
    constructorPoints[2] = p3;
    constructorPoints[3] = p4;
    return constructorPoints;
}

Rectangle::Rectangle(int x1, int y1, int x2, int y2) :
Polygon(updateConstructorPoints( Point(x1,y1), Point(x1,y2), Point(x2,y1), Point(x2,y2)), 4) {}

Rectangle::Rectangle(Point pt1, Point pt2)
: Polygon( updateConstructorPoints( Point(pt1.getX(), pt1.getY()), Point(pt1.getX(), pt2.getY()), Point(pt2.getX(), pt2.getY()), Point(pt2.getX(), pt1.getY()) ), 4 ) {}



double Rectangle::area() const {

    const Point* ll = pArray.get(0);
    const Point* ur = pArray.get(2);

    double width = abs(ll->getX() - ll->getX());
    double height = abs(ll->getY() - ll->getY());

    return width * height;
}

Point constructorPointsT[3];

Point *updateConstructorPointsT(const Point &p1, const Point &p2, const Point &p3 = Point(0,0)) {
    constructorPointsT[0] = p1;
    constructorPointsT[1] = p2;
    constructorPointsT[2] = p3;

    return constructorPointsT;
}

Triangle::Triangle(const Point &pt1, const Point &pt2, const Point &pt3) : Polygon(updateConstructorPointsT(pt1, pt2, pt3), 3) {

}



double Triangle::area() const {

}


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
