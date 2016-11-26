#include <sstream>
#include "common.h"
class GeometricObject // Base Abstract Class
{
protected:
public:
GeometricObject(); // Constructor
virtual double area()= 0; // Pure virtual method for calculating the area
// Pure virtual method for initialization for a string stream
virtual void initialize (stringstream & ss) = 0;
// Pure virtual method for creating an object from a string stream and is used afactory engine as it will return a pointer to an object of type GeometricObject
virtual GeometricObject * clone (stringstream & ss)=0;
virtual ~GeometricObject(); // Destructor
};