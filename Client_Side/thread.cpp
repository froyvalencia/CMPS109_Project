//Brian NGuyen
//thread.h

#include "thread.h"


//since input argument to the runThread() is the Thread class this pointer, we can cast it to a Thread pointer
// then use it to call the Thread::run()
static void* runThread(void* arg)
{
    return ((Thread*)arg)->run();
}

//construtor initializes all members to 0.
//thrad id, running is off and detatched is off.
Thread::Thread() : m_tid(0), m_running(0), m_detached(0) {}


Thread::~Thread()
{
    //when destructing thread, check to see if it is still running
    if (m_running == 1 && m_detached == 0) {
        pthread_detach(m_tid);
    }
    //this will ensure the thread is shutdown at some point in the future
    if (m_running == 1) {
        pthread_cancel(m_tid);
    }
}
//creates thread and accepts 4 args.
//pointer to a: (pthread_t) var that contains threadID, attirubutes object set to null, 
//pointer to a function that is called when thread starts to take the thread action, and data object 
/// that will be passed to the thread action function.
int Thread::start()
{
    int result = pthread_create(&m_tid, NULL, runThread, this);
    if (result == 0) {
        m_running = 1;
    }
    //returns 0 if successful and !0 when fails
    return result;
}
//method checks to see if the thread is running, then calls this function to wait for the thread to complete.
// If the call is successful the thread is marked as detached since pthread_join() automatically detatches a thread.
int Thread::join()
{
    int result = -1;
    if (m_running == 1) {
        result = pthread_join(m_tid, NULL);
        if (result == 0) {
            m_detached = 0;
        }
    }
    return result;
}

// detaches a thread when the caller doesn’t want to wait for the thread to complete. If the thread is running and
// not detached, pthread_detach() is called and the thread is flagged as detached if the call is successful.
int Thread::detach()
{
    int result = -1;
    if (m_running == 1 && m_detached == 0) {
        result = pthread_detach(m_tid);
        if (result == 0) {
            m_detached = 1;
        }
    }
    return result;
}
///method that returns the thread ID for display or logging purposes.
pthread_t Thread::self() {
    return m_tid;
}
