#include "ShapesThread.h"
ShapesThread::ShapesThread(SharedObjectsManager * p_sharedObjectsManager,char * p_filename,pthread_mutex_t *
p_print_mutex){ // Constructor: passing pointers from outside its scope
sharedObjectsManager = p_sharedObjectsManager; // Assigning pointer to data member for future references
filename = p_filename; // Assigning filename to data member for future references
print_mutex = p_print_mutex; // Assigning print_mutex to data member for synchronizing terminal outoput.
}
void * ShapesThread::threadMainBody(void * arg) { // Thread main body
 string line=""; // A line for parsing
 ifstream readFile(filename); // Name of the geometric object shapes file
 string name =""; // A string to store the object name. The object name should be equal to the DSO file base name
 while(getline(readFile,line)){ // Loop to parse the file line by line
 stringstream iss(line);// Define a stringstream to parse the line
 getline(iss, name, ','); // Fetch the first token before the first comma
 GeometricObject * obj = sharedObjectsManager->load(name); // Try to load corresponding object from DSO
 if ( obj != NULL ){ // If object is not NULL then object loaded
 obj = obj->clone(iss); // Clone object
pthread_mutex_lock(print_mutex); // Lock for printing
 cout << "Thread # " << pthread_self() << ": " << name <<":"<< obj->area() <<"\n"; // Calculate area
pthread_mutex_unlock(print_mutex); // Unlock
 delete (obj); // Delete object
 } // Else print an error message indicating that object could not be loaded
 else cout << "Undefined Object Identifier\n";
 }
 readFile.close(); // Close the shapes file
return NULL;
}
// Nothing to destruct since everything was instantiated outside the scope of the object and shared by other threads
ShapesThread::~ShapesThread(){}