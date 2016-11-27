// Defining creation and destruction external functions for access by dlsym
// The macro is passed through the compilation command line to enable definition when needed
#include <sstream>
#include "GeometricObject.h"
#include "common.h"
using namespace std;

#ifdef RECTANGLEGUARD
extern "C" GeometricObject * create_object (); // Creating a Rectangle Object
#endif

class Rectangle: public GeometricObject // Rectangle inherits from GeometricObject
{
 protected:
 double width;
 double height;
 public:
Rectangle (); // Default Constructor
 Rectangle(double p_width,double p_height); // Parameterized Constructor
 double area (); // A method for calculating the area
void initialize (stringstream & ss); // A method that inializes the object from a stringstream
GeometricObject * clone (stringstream & ss); // Factory clone method
 virtual ~Rectangle (); // Destructor
};