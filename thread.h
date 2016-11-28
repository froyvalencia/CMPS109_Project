/*Brian Nguyen
//thread.h
//provides methods to start the thread at the time of caller's choosing,
wait for thread to finish and detatch thread so that it doesn't require another
thread to wait for it to finish.*/
#ifndef __thread_h__
#define __thread_h__

#include <pthread.h>

class Thread
{
  public:
    Thread();//Constructor
    virtual ~Thread(); //virtual destructor to terminate all instances of the thread when it's done

    int start();
    int join();
    int detach();
    pthread_t self();
    
    //setting it to 0 forves this class to be abstart and requires that run to be overridding in any subclass of thread.
    virtual void* run() = 0; 
    
  private:
    pthread_t  m_tid; //contains the thread iD
    int        m_running; //toggle flag that is 0 when thread isn't running and 1 when it is
    int        m_detached; //toggle flag that is 0 when thread is not detatched and 1 when it is.
};

#endif
