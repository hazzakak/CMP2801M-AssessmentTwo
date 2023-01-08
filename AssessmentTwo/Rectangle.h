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

	// Getter function for the height of the rectangle
	int getHeight() { return _height; }

	// Getter function for the width of the rectangle
	int getWidth() { return _width; }

	// Virtual function to calculate the points of the rectangle
	virtual void calculatePoints() override;

	// Virtual function to calculate the area of the rectangle
	virtual void calculateArea() override;

	// Virtual function to calculate the perimeter of the rectangle
	virtual void calculatePerimeter() override;

	// Virtual function to move the rectangle by a given x and y distance
	virtual void move(int, int) override;

	// Function to scale the rectangle by a given x and y factor
	void scale(float, float);

	// Virtual function to return a string representation of the rectangle
	virtual string toString();
};
