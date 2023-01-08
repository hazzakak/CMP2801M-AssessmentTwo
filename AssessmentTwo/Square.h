#pragma once
#include "Shape.h"
#include "Movable.h"
#include "Rectangle.h"

// The Square class represents a square shape that can be moved and scaled.
class Square : public Shape, public Movable
{
private:
    // The length of the edge of the square.
    float edge;
public:
    // Constructs a new square with the given edge length and top-left position.
    Square(int x, int y, int e) {
        edge = e;
        Shape::leftTop._x = x;
        Shape::leftTop._y = y;
    }

    ~Square();

    // Overloads the stream insertion operator to print a string representation of the square.
    friend ostream& operator<<(ostream& output, Square& sqr) {
        output << "Shape: Square\nEdge: " << sqr.edge << "\nArea: " << sqr.area << "\nPerimeter: " << sqr.perimeter << "\nPoints: " + sqr.pointsToString() << endl;
        return output;
    }

    // Calculates the points that define the boundaries of the square.
    virtual void calculatePoints();
    // Calculates the area of the square.
    virtual void calculateArea();
    // Calculates the perimeter of the square.
    virtual void calculatePerimeter();

    // Moves the square to the specified position.
    virtual void move(int, int);
    // Scales the square by the specified amount in the x-direction.
    void scale(float scaleX);

    // Returns a string representation of the square.
    string toString();
};
