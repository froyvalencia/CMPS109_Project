#include "GeometricObject.h"
#include <thread>
#include <mutex>
#include "common.h"
using namespace std;
// A function pointer type to point to the creation routine within the DSO
typedef GeometricObject * create_object_routine ();
class SharedObjectsManager
{
private:
 map <string,GeometricObject *> gobj; // A vector to store the cloner objects
 map <string,void *> dsos; // A vector to store all DSO objects
public:
SharedObjectsManager(); // Constructor
GeometricObject * load(string name); // Loading a DSO from file
~SharedObjectsManager(); // Destructor
};