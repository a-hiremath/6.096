//
// Created by adity on 10/6/2025.
//

class Point {
    int x,y;
public:

    Point(int x=0, int y=0);

    int getX() const;
    int getY() const;

    void setX(const int new_x);
    void setY(const int new_y);

};


class PointArray {
    Point *p;
    int len;
public:


    PointArray();

    PointArray(const Point points[], const int size);

    Point& getPointArray(int index = 1);

    int getLen();

    PointArray(const PointArray& pv);

    ~PointArray();

    void resize(int n);

};