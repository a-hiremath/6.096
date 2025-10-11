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

    void push_back(const Point &p);

    ~PointArray();

    void resize(int n);

    void insert(const int position, const Point &pt);

    void remove(const int pos);

    const int getSize() const;

    void clear();

    Point* get(const int position);

    const Point* get(const int position) const;
};

class Polygon {
protected:
    PointArray pArray;
    static int instances;
public:

    Polygon(const Point pts[], int length);

    Polygon(const PointArray& ptA);


};