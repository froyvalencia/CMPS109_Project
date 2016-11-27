#include "Thread.h"
#include <thread>
#include <mutex>
#include "common.h"
using namespace std;
// A function pointer type to point to the creation routine within the DSO
typedef Thread * create_object_routine ();
class ThreadManager
{
private:
 map <string,Thread *> gobj; // A vector to store the cloner objects
 map <string,void *> dsos; // A vector to store all DSO objects
public:
ThreadManager(); // Constructor
Thread * load(); // Loading a DSO from file
~ThreadManager(); // Destructor
};