#include "SharedObjectsManager.h"
#include "Thread.h"
class ShapesThread: public Thread
{
private:
SharedObjectsManager * sharedObjectsManager; // SharedObjectManager instantiated outside thescope of this object and used to load DSOs when needed
char * filename; // Shapes file name that has the shapes whose areas need to be calculated
pthread_mutex_t * print_mutex; // A shared mutex among all ShapesThreads to synchronize output
public:
// Constructor
ShapesThread(SharedObjectsManager * p_sharedObjectsManager,char * p_filename,pthread_mutex_t
* p_print_mutex);
virtual void * threadMainBody (void * arg); // Main thread body that carries out the calculations
~ShapesThread (); // Destructor
};