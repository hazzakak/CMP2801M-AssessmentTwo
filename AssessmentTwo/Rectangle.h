#pragma once
#include "Shape.h"
#include "Movable.h"

// Rectangle class derived from the Shape and Movable base classes
class Rectangle : public Shape, public Movable
{
private:
	// Private member variables for the height and width of the rectangle
	int _height;
	int _width;

public:
	// Constructor that sets the left top point and the height and width of the rectangle
	Rectangle(int LTX, int LTY, int h, int w) {
		_height = h;
		_width = w;
		leftTop = Point(LTX, LTY);
	}

	// Destructor for the rectangle
	~Rectangle();

	// Overloaded stream insertion operator for printing the rectangle
	friend ostream& operator<<(ostream& output, Rectangle& rect) {
		output << "Shape: Rectangle\nWidth: " << rect._width << "\nHeight: " << rect._height << "\nArea: " << rect.area << "\nPerimeter: " << rect.perimeter << "\nPoints: " + rect.pointsToString() << endl;;
		return output;
	}

	// Getter function for the height
	int getHeight() { return _height; }

	// Getter function for the width
	int getWidth() { return _width; }

	// Virtual function to calculate the points
	virtual void calculatePoints() override;

	// Virtual function to calculate the area
	virtual void calculateArea() override;

	// Virtual function to calculate the perimeter
	virtual void calculatePerimeter() override;

	// Virtual function to move the rectangle by a given x and y distance
	virtual void move(int, int) override;

	// Function to scale the rectangle by a given x and y factor
	void scale(float, float);

	// function to return a string
	string toString();
};
