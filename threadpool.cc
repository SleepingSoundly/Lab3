/*
 *
 *	Implementation of Threadpool, for Lab 3
 *
 *
 */

#include "Threadpool.h"


// constructor initializes the # of threads we'll create 
ThreadPool::ThreadPool(int given_pool_size) : poolSize(given_pool_size)
{
	isLocked = false; // init mutex status for task queue
	cout << "Constructed ThreadPool of size " << poolSize << endl;

}


ThreadPool::~ThreadPool(){
	// need a conditional to not do this while requests are already stopped? 
	destroy_threadpool();
}


// apparently pthread_create can't take a member function
// make a wrapper and pass in the function you want. 

// start all the threads
int ThreadPool::begin_threadpool(){
	poolState = 0;
	int ret, idx;

	for(idx = 0; idx < given_pool_size; idx++){
		// create thread. 


	}


}

// end all the threads
int ThreadPool::end_threadpool(){



}

void ThreadPool::add_task(void* task){
	pthread_mutex_lock(&taskLock);
	isLocked = true;
	
	availableTasks.push_back(task);
	pthread_cond_signal(&taskCondVar); // alert threads that something is here to process
    
    isLocked = false;
	pthread_mutex_unlock(&taskLock);

}



int ThreadPool::start_task(){




}
