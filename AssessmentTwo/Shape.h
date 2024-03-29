#pragma once
#include <string>
#include "Point.h";
#include <vector>
#include <iostream>

using namespace std;

// The Shape class represents a shape that has a position, an area, a perimeter, and a set of points that define its boundaries.
class Shape
{
protected:
    // The area of the shape.
    float area;

    // A flag indicating whether the shape is circular.
    bool isCircular = false;

    // The perimeter of the shape.
    float perimeter;

    // A vector of points that define the boundaries of the shape.
    vector<Point> points{ Point(0,0), Point(0,0), Point(0,0), Point(0,0) };

public:
    // The top-left point
    Point leftTop;

    // Sets the top-left point
    void setLeftTop(Point pnt) { leftTop = pnt; }

    // Calculates the area, gets overriden.
    virtual void calculateArea() = 0;

    // Calculates the perimeter, gets overriden.
    virtual void calculatePerimeter() {};

    // Calculates the points that define the boundaries, gets overriden.
    virtual void calculatePoints() {};

    // Returns a string representation, gets overriden.
    virtual string toString() = 0;

    // Returns a string representation of the points that define the boundaries, gets overriden.
    string pointsToString();

    // Deletes the shape.
    virtual ~Shape() {};

    friend ostream& operator<<(ostream&, Shape& shp);
};
