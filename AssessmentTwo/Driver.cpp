/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment 
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file. 
During marking, we will use the exact same notation 
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't 
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK! 

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"

#include <iostream>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <string>

using namespace std;

vector<std::string> splitString(const char in[])
{
	// This function takes a character array 'in' and splits it into a vector of strings.
	// It does this by creating an input string stream (iss) from the character array, 
	// creating an iterator that reads from the stream and constructs strings, and
	// copying the iterator's elements into a vector of strings.

	std::istringstream iss(in);
	std::istream_iterator<std::string> first(iss), last;

	std::vector<std::string> parts;
	std::copy(first, last, std::back_inserter(parts));
	return parts;
}

int main()
{
	// Initialize variables for user input and storage of shapes and command parameters.
	string userCommand;
	vector <Shape*> shapes;
	vector <string> parameters;

	// Continuously prompt the user for a command until they enter "exit".
	while (userCommand.compare("exit") != 0)
	{
		wrongCmd:
		cout << "Enter the command: ";
		getline(cin, userCommand);

		// Convert the user command string to a character array for use with strtok().
		char* cstr = new char[userCommand.length() + 1];
		strcpy_s(cstr, userCommand.length() + 1, userCommand.c_str());

		// Split the character array into a vector of strings using the splitString() function.
		parameters = splitString(cstr);

		// The first element in the vector will be the command.
		string command = parameters[0];

		// Check the command and execute the corresponding block of code.
		if (command.compare("addR") == 0) {
			// If the command is "addR", create a new rectangle with the given parameters.
			// First, check if the correct number of parameters were given.
			// If not, print an error message and exit the loop.
			if (parameters.size() != 5) {
				cout << "4 parameters are required: 'addR <x> <y> <height> <width>'" << endl;
				goto wrongCmd;
			}

			// Convert the string parameters to integers and use them to create a new rectangle object.
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int h = stoi(parameters[3].c_str());
			int w = stoi(parameters[4].c_str());
			Rectangle* r = new Rectangle(x, y, h, w);

			// Add the new rectangle to the shapes vector.
			shapes.push_back(r);

			// Calculate and print the area, perimeter, and points of the rectangle.
			r->calculateArea();
			r->calculatePerimeter();
			r->calculatePoints();
			cout << *r;
		}
		else if (command.compare("addS") == 0) {
			// If the command is "addS", create a new square with the given parameters.
			// First, check if the correct number of parameters were given.
			// If not, print an error message and exit the loop.
			if (parameters.size() != 4) {
				cout << "3 parameters are required: 'addS <x> <y> <edge>'" << endl;
				goto wrongCmd;
			}

			// Convert the string parameters to integers and use them to create a new square object.
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int e = stoi(parameters[3].c_str());
			Square* s = new Square(x, y, e);

			// Add the new square to the shapes vector.
			shapes.push_back(s);

			// Calculate and print the area, perimeter, and points of the square.
			s->calculateArea();
			s->calculatePerimeter();
			s->calculatePoints();
			cout << *s;
		}
		else if (command.compare("addC") == 0) {
			// If the command is "addC", create a new circle with the given parameters.
			// First, check if the correct number of parameters were given.
			// If not, print an error message and exit the loop.
			if (parameters.size() != 4) {
				cout << "3 parameters are required: 'addC <x> <y> <radius>'" << endl;
				goto wrongCmd;
			}

			// Convert the string parameters to integers and use them to create a new circle object.
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());
			Circle* c = new Circle(x, y, r);

			// Add the new circle to the shapes vector.
			shapes.push_back(c);

			// Calculate and print the area, perimeter, and points of the circle.
			c->calculateArea();
			c->calculatePerimeter();
			c->calculatePoints();
			cout << *c;
		}
		else if (command.compare("scale") == 0) {
			// If the command is "scale", scale the shape at the given index by the given amount.
			// First, check if the correct number of parameters were given.
			// If not, print an error message and exit the loop.
			if (parameters.size() != 4) {
				cout << "3 parameters are required: 'scale <index> <scaleX> <scaleY>'" << endl;
				goto wrongCmd;
			}

			// Convert the string parameters to integers and floats.
			int shapeIndex = stoi(parameters[1].c_str());
			float scaleX = stof(parameters[2].c_str());
			float scaleY = stof(parameters[3].c_str());

			// Check if the shape index is valid.
			// If not, print an error message and exit the loop.
			if (shapes.size() < shapeIndex || shapeIndex < 1) {
				cout << "Scale command requires 'scale <index> <scaleX> <scaleY>', index must be a correct value." << endl;
				goto wrongCmd;
			}

			Shape* shp = shapes[shapeIndex - 1];

			Rectangle* shpRect = dynamic_cast<Rectangle*> (shp);
			Square* shpSquare = dynamic_cast<Square*> (shp);
			Circle* shpCircle = dynamic_cast<Circle*> (shp);

			if (shpRect != NULL) {
				shpRect->scale(scaleX, scaleY);
			}
			if (shpSquare != NULL) {
				shpSquare->scale(scaleX);
			}
			if (shpCircle != NULL) {
				shpCircle->scale(scaleX);
			}

			cout << *shp;
		}
		else if (command.compare("move") == 0) {
			// If the command is "move", move the shape at the given index by the given amount.
			// First, check if the correct number of parameters were given.
			// If not, print an error message and exit the loop.
			if (parameters.size() != 4) {
				cout << "3 parameters are required: 'move <shapeIndex> <moveX> <moveY>'" << endl;
				goto wrongCmd;
			}

			// Convert the string parameters to integers.
			int shapeIndex = stoi(parameters[1].c_str());
			int moveX = stoi(parameters[2].c_str());
			int moveY = stoi(parameters[3].c_str());

			// Check if the shape index is valid.
			// If not, print an error message and exit the loop.
			if (shapes.size() < shapeIndex || shapeIndex < 1) {
				cout << "Move command requires 'move <shapeIndex> <moveX> <moveY>', index must be a correct value." << endl;
				goto wrongCmd;
			}

			// Get the shape at the given index.
			Shape* shp = shapes[shapeIndex - 1];

			Movable* m = dynamic_cast<Movable*> (shp);
			m->move(moveX, moveY);
			cout << *shp;
		}
		else if (command.compare("display") == 0) {
			for (int i = 0; i < shapes.size(); i++) {
				// Get the shape at the current index.
				Shape* shp = shapes[i];

				cout << "Index: " << i + 1 << endl << *shp << endl << endl;
			}
		} else if (command.compare("clear") == 0) {
			parameters.clear();
			command.clear();
			for (Shape* shape : shapes) {
				delete shape;
				shape = nullptr;
			}
			shapes.clear();
		} else if (command.compare("exit") == 0) {
			parameters.clear();
			command.clear();
			userCommand = "exit";
		} else {
			cout << "Incorrect command" << endl;
		}

		// destruct this as it is explicitly created with new.
		delete[] cstr;
	}

	userCommand.clear();

	for (Shape* shape : shapes) {
		delete shape;
		shape = nullptr;
	}

	shapes.clear();

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
