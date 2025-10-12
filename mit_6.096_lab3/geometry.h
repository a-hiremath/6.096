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

    // constructors

    Polygon(const Point pts[], int length);

    Polygon(const PointArray& ptA);

    // member functions

    virtual double area() const = 0;

    int getNumPolygons() const;

    int getNumSides() const;

    const PointArray* getPoints() const;

    void printAttributes(Polygon *);

};

class Rectangle : public Polygon {
public:

    // constructors

    Rectangle(Point pt1, Point pt2);

    Rectangle(int x1, int y1, int x2, int y2);

    // member functions

    double area() const override;

};

class Triangle : public Polygon {
public:

    // constructors

    Triangle(const Point& pt1, const Point& pt2, const Point& pt3);

    // member functions

    double area() const override;

};