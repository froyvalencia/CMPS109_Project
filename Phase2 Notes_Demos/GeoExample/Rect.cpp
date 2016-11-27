
#include "common.h"
#include "Rect.h"
using namespace std;
Rectangle::Rectangle ():Rectangle(0,0){} // Default constructor calling parameterized constructor
// Parameterized constructor initializing data members using attribute lists and invoking parent constructor
Rectangle::Rectangle(double p_width,double p_height):width(p_width),height(p_height),GeometricObject(){}
double Rectangle::area (){return width*height;} // Calculating the area of the rectangle
// Reading the width and height from a string stream and storing them in data members
void Rectangle::initialize (stringstream & ss) {
string str = "";
getline(ss,str,',');
width = strtof(str.c_str(),NULL);
 getline(ss,str,',');
height = strtof(str.c_str(),NULL);
}
// Creating a new Rectangle object based on the provided string stream
GeometricObject * Rectangle::clone (stringstream & ss) {
Rectangle * rectangle = new Rectangle();
rectangle->initialize(ss);
return rectangle;
}
Rectangle::~Rectangle (){} // Destructor
// The macro is passed through the compilation command line to enable definition when needed
#ifdef RECTANGLEGUARD
// Instantiate a Rectangle Object and return a pointer to it casted upward as GeometricObject pointer
extern "C" GeometricObject * create_object () { return new Rectangle (); }
#endif