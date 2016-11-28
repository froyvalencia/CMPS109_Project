
#include "Square.h"
using namespace std;

Square::Square():Square(0){} // Default constructor calling parameterized constructor
// Parameterized constructor initializing data members using attribute lists and invoking parent constructor
Square::Square(double p_width):Rectangle(p_width,p_width){}
// Reading the width from a string stream and storing them in data members
void Square::initialize (stringstream & ss) {
string str ="";
getline(ss,str,',');
width = strtof(str.c_str(),NULL);
height = width;
}
// Creating a new Square object based on the provided string stream
GeometricObject * Square::clone (stringstream & ss) {
 Square * square = new Square();
 square->initialize(ss);
 return square;
}
Square::~Square (){} // Destructor
#ifdef SQUAREGUARD
// Instantiate a Square Object and return a pointer to it casted upward as GeometricObject pointer
extern "C" GeometricObject * create_object (){return new Square (); }
#endif