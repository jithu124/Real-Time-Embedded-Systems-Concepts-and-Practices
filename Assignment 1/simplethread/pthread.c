#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <syslog.h>

#define NUM_THREADS 1



pthread_t threads[NUM_THREADS];



void *MessageThread(void *threadp)
{
    syslog(LOG_INFO, "[COURSE:1][ASSIGNMENT:1] Hello World from Thread!\n");
}


int main (int argc, char *argv[])
{

    syslog(LOG_INFO, "[COURSE:1][ASSIGNMENT:1] Hello World from Main!\n");

    pthread_create(&threads[0],   // pointer to thread descriptor
                      NULL,     // use default attributes
                      MessageThread, // thread function entry point
                      NULL // parameters to pass in
                      );
    
    pthread_join(threads[0],NULL);
    
    closelog();


}
