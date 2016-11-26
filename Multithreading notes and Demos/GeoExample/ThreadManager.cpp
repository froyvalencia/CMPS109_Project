#include "ThreadManager.h"

ThreadManager::ThreadManager() { // Constructor
pthread_mutex_init(&sync_mutex,NULL); // Initializing synchronization mutex 
}
Thread * ThreadManager::load(string name) {
pthread_mutex_lock(&sync_mutex);
Thread * obj = gobj[name]; // Fetch object based on name
if ( obj != NULL ) {
pthread_mutex_unlock(&sync_mutex);
return obj; // If found return it
} // Else load the DSO and fetch the object through external launcher function
 string lib_name = "./"+name+".so"; // Compose DSO name
 cout << "Loading Library: "<< lib_name <<"\n";
 // Loading dynamic object file. RTLD_LAZY: External functions are bound upon call.
 void * dso=dlopen (lib_name.c_str(),RTLD_LAZY);
 if ( dso ) { // If dso is not NULL then loaded successfully
cout << "Dynamic Object Loaded Successfully\n";
// Loading external function from DSO
create_object_routine * my_func = (create_object_routine *) dlsym (dso,"create_object");
if ( my_func ) { // If function loaded successfuly
gobj[name] = my_func(); // Store function in gobj vector
dsos[name] = dso; // Store DSO handler into dsos vectors
obj = gobj[name]; // Fetch the external function into obj to be returned
} // Cannot load the external function from the DSO
else cout << "Error fetching external function "<< name << ": " << dlerror() <<"\n";
} // Unable to load then print error message with dlerror()
 else cout << "Error loading dynamic object"<< name << ": " << dlerror() <<"\n";
pthread_mutex_unlock(&sync_mutex);
return obj; // Return required object
}




ThreadManager::~ThreadManager() // Destructor
{
// An iterator loop with a lambda function to delete all objects
for_each (gobj.begin(),gobj.end(),[](const std::pair<string,Thread *>& it) -> bool {
 Thread * obj = std::get<1>(it);
delete (obj);
 return true;
 });
// An iteration loop with a lambda function to close all the dlls
 for_each (dsos.begin(),dsos.end(),[](const std::pair<string,void *>& it) -> bool {
void * dso = std::get<1>(it);
dlclose(dso);
return true;
});
pthread_mutex_destroy(&sync_mutex);// Destroying synchronization mutex
}
