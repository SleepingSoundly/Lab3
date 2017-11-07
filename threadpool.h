/*
 *
 *	Implementation of Threadpool, for Lab 3
 *
 *		Header
 */

#pragma once // for the dummy C programmer, this is like ifdef headername.h sort of thing

#include <pthread.h>
#include <vector> 
#include <unistd.h>
#include <iostream>
#include <string.h>



using namespce std;




class ThreadPool{

 public:
 	ThreadPool(int given_pool_size); // constructor
 	~ThreadPool(); // destructor
 	int begin_threadpool();
 	void add_task(void* task); // should be an fp to a function to run? 
 	int start_task();
 	int end_threadpool();

 private:
 	int poolSize;
 	std::vector<pthread_t> availableThreads; 
 	std::deque<void*> availableTasks;
 	pthread_mutex_t taskLock;
 	bool isLocked;
 	pthread_cond_t taskCondVar;
 	int poolState;
 	
 	// and a queue of tasks? maybe don't need this one. 
 	// and if we do need it, we need a state of pool variable. 

};