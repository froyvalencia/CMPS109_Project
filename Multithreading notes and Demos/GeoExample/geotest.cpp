
#include "common.h"
#include <mutex>
#include "SharedObjectsManager.cpp"
#include "ShapesThread.cpp"
//#include "ThreadManager.cpp"

using namespace std;
std::mutex mtx;
int main (int argc, char ** argv) { // Main program with command line parameters
if ( argc < 2 ) { // Check for at least one parameter in addition to the program name
// If not then print error an usage message
cout << "Error: You need to provide at least one file parameter\n";
cout << "Usage: mt_shapes file1 [.... fileN]\n";
exit(1); // Terminate program
}
// Declare and instantiate a SharedObjectsManager for manageing the DSOs and the external functions
SharedObjectsManager * sharedObjectsManager = new SharedObjectsManager();
// Declare and instantiate a new ThreadManager object
ThreadManager * threadManager = new ThreadManager ();
pthread_mutex_t print_mutex; // A print mutex to handle printing
pthread_mutex_init(&print_mutex,NULL); // Initialize the print mutex
// Loop over argc starting from 1 (to skip program name) to create threads and pass it to ThreadManager
for ( int i = 1 ;i < argc ; i ++)
threadManager->addThread(new ShapesThread(sharedObjectsManager,argv[i],&print_mutex));
threadManager->start(); // Start all threads
threadManager->barrier(); // Wait for all threads to finish
delete (threadManager);// Destruct threadManager and free all resources
delete (sharedObjectsManager); // Destruct sharedObjectsManager and free all resources
pthread_mutex_destroy(&print_mutex); // Destruct the print mutex
return 0;
}
