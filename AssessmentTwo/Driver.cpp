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

// https://stackoverflow.com/questions/12704337/splitting-a-string-with-strtok-s
vector<std::string> splitString(const char in[])
{
	std::istringstream iss(in);
	std::istream_iterator<std::string> first(iss), last;

	std::vector<std::string> parts;
	std::copy(first, last, std::back_inserter(parts));
	return parts;
}

int main()
{
	string userCommand;
	vector <Shape*> shapes;     // this one will hold your shapes
	vector <string> parameters; // this one will hold parameters for the commands


	while (userCommand.compare("exit") != 0) 
	{
		cout << "Enter the command: ";
		
		getline(cin, userCommand);

		char * cstr = new char[userCommand.length() + 1];

		strcpy_s(cstr, userCommand.length()+1, userCommand.c_str());
		
		// splits string into parameters.
		parameters = splitString(cstr);

		// parameter[0] is the command
		string command = parameters[0];

		if (command.compare("addR") == 0) {
			// get parameters in the correct order

			// addR <x> <y> <height> <width>
			// if not enough parameters

			cout << parameters.size() << endl;
			if (parameters.size() < 5 || parameters.size() > 5) {
				cout << "4 parameters are required: 'addR <x> <y> <height> <width>'" << endl;
				break;
			}

			int x = stoi(parameters[1].c_str()); 
			int y = stoi(parameters[2].c_str());
			int h = stoi(parameters[3].c_str());
			int w = stoi(parameters[4].c_str());

			Rectangle* r = new Rectangle(x, y, h, w);
			shapes.push_back(r);

			r->calculateArea();
			r->calculatePerimeter();
			r->calculatePoints();

			cout << *r;
		}
		else if (command.compare("addS") == 0) {
			// addS <x> <y> <edge>
			// if not enough parameters
			if (parameters.size() < 4 || parameters.size() > 4) {
				cout << "3 parameters are required: 'addS <x> <y> <edge>'" << endl;
				break;
			}

			// get parameters
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int e = stoi(parameters[3].c_str());

			Square* s = new Square(x, y, e);
			shapes.push_back(s);

			s->calculateArea();
			s->calculatePerimeter();
			s->calculatePoints();

			cout << *s;
		}

		else if (command.compare("addC") == 0) {
			// addC <x> <y> <radius>
			// if not enough parameters
			if (parameters.size() < 4 || parameters.size() > 4) {
				cout << "3 parameters are required: 'addC <x> <y> <radius>'" << endl;
				break;
			}

			// get parameters
			int x = stoi(parameters[1].c_str());
			int y = stoi(parameters[2].c_str());
			int r = stoi(parameters[3].c_str());

			Circle* c = new Circle(x, y, r);
			shapes.push_back(c);

			c->calculateArea();
			c->calculatePerimeter();
			c->calculatePoints();

			cout << *c;
			
		}
		else if (command.compare("scale") == 0) {
			// scale object at index... the scaling needs to be isotropic in case of circle and square 
			// you may want to check if the index exists or not!
			
			// Multiple inhertitance is tricky! The Shape class does nto have a scale function, the Movable does!
			// As a result all your derived classes have scale functions... 
			// You may need to use type casting wisely to use polymorphic functionality!
			
			// scale <index> <scaleX> <scaleY>
			// if not enough parameters
			if (parameters.size() < 4 || parameters.size() > 4) {
				cout << "3 parameters are required: 'scale <index> <scaleX> <scaleY>'" << endl;
				break;
			}

			int shapeIndex = stoi(parameters[1].c_str());
			float scaleX = stof(parameters[2].c_str());
			float scaleY = stof(parameters[3].c_str());

			if (shapes.size() > shapeIndex || shapeIndex < 1) {
				cout << "Scale command requires 'scale <index> <scaleX> <scaleY>', index must be a correct value." << endl;
				break;
			}

			Shape* shp = shapes[shapeIndex-1];

			Rectangle* shpRect = dynamic_cast<Rectangle*> (shp);
			Square* shpSquare = dynamic_cast<Square*> (shp);
			Circle* shpCircle = dynamic_cast<Circle*> (shp);

			if (shpRect != NULL) {
				shpRect->scale(scaleX, scaleY);
				cout << *shpRect;
			}
			if (shpSquare != NULL) {
				shpSquare->scale(scaleX);
				cout << *shpSquare;
			}
			if (shpCircle != NULL) {
				shpCircle->scale(scaleX);
				cout << *shpCircle;
			}
		}
		else if (command.compare("move") == 0) {
			// move object at index 
			if (parameters.size() < 4 || parameters.size() > 4) {
				cout << "3 parameters are required: 'move <shapeIndex> <moveX> <moveY>'" << endl;
				break;
			}

			int shapeIndex = stoi(parameters[1].c_str());
			int moveX = stoi(parameters[2].c_str());
			int moveY = stoi(parameters[3].c_str());

			if (shapes.size() > shapeIndex || shapeIndex < 1) {
				cout << "Move command requires 'move <shapeIndex> <moveX> <moveY>', index must be a correct value." << endl;
				break;
			}
			
			Shape* shp = shapes[shapeIndex-1];

			Rectangle* shpRect = dynamic_cast<Rectangle*> (shp);
			Square* shpSquare = dynamic_cast<Square*> (shp);
			Circle* shpCircle = dynamic_cast<Circle*> (shp);

			if (shpRect != NULL) {
				shpRect->move(moveX, moveY);
				cout << *shpRect;
			}
			if (shpSquare != NULL) {
				shpSquare->move(moveX, moveY);
				cout << *shpSquare;
			}
			if (shpCircle != NULL) {
				shpCircle->move(moveX, moveY);
				cout << *shpCircle;
			}
		}
		else if (command.compare("display") == 0) {
			for (int i = 0; i < shapes.size(); i++) {
				Shape* shp = shapes[i];

				Rectangle* shpRect = dynamic_cast<Rectangle*> (shp);
				Square* shpSquare = dynamic_cast<Square*> (shp);
				Circle* shpCircle = dynamic_cast<Circle*> (shp);

				if (shpRect != NULL) {
					cout << "Index: " << i+1 << endl<< *shpRect << endl << endl;
				}
				if (shpSquare != NULL) {
					cout << "Index: " << i + 1 << endl << *shpSquare << endl << endl;
				}
				if (shpCircle != NULL) {
					cout << "Index: " << i + 1 << endl << *shpCircle << endl << endl;
				}
			}
		}
		else {
			cout << "Incorrect command" << endl;
		}

		// destruct this as it is explicitly created with new.
		delete cstr;
	}
	for (int a = 0; a < shapes.size(); a++)
	{
		Shape* shp = shapes[a];
		delete shp;
	}

	cout << "Press any key to continue...";
	std::getchar();

	return 0;
}
