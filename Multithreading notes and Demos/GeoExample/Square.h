#include "Rect.h"

#include "common.h"
using namespace std;
// Defining creation and destruction external functions for access by dlsym
// The macro is passed through the compilation command line to enable definition when needed
class Square : public Rectangle // Inherits from Rectangle
{
private:
public:
Square(); // Default Constructor
Square(double p_width); // Parameterized Constructor
virtual void initialize (stringstream & ss); // A method that initializes the object from a stringstream
virtual GeometricObject * clone (stringstream & ss); // Factory Clone Method
virtual ~Square (); // Destructor
};
#ifdef SQUAREGUARD
extern "C" GeometricObject * create_object (); // Creating a Square Object
#endif