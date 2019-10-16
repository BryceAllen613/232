/*
 * Model.cpp
 * a class dedicated to timing system calls (threads and processes) and printing their
 * times and averages to the console.
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#include "Model.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "NanoTimer.h"
using namespace std;

/* constructor for the model class
 * (only default constructor because no instance variables are needed for this class)
 */
Model::Model() {}

/**
 * computes the average of a sum of numbers
 * @param sum: a sum of numbers calculated elsewhere
 * @param numData: the number of data points added in sum
 * @return sum/numData
 */
double Model::average(double sum, unsigned numData)
{ return sum / numData; }

/* function for identifying which thread is executing the function.
 * @param arg: the id of the thread executing this function.
 */
void *printHello(void *arg)
{ cout << "hello from child thread (tid: " << (long)arg << ")" << endl; }

/* runThread() creates, runs, and times thread system calls
 * @param: repeat, the number of times you want to repeat this system call.
 */
void Model::runProcess(int repeat)
{
	 NanoTimer nt;
	 double sum = 0.0;
	 for( int i = 0; i < repeat; i++)
	 {
		 nt.start();
		 //make two processes that run same program after this line...
		 pid_t pid = fork();
		 nt.stop();
		 sum += nt.asDouble();

		 if( pid == 0 ) //if child...
		 {
			 cout << "hello from child process (pid: "
					 << getpid()
					 << ")"
					 //<< nt.asDouble()
					 << endl;
		 	 kill(getpid(), SIGTERM);
		 }
		 else //if parent...
		 {
			 //cout << "hello from parent (pid: " << getpid() << ")" << nt.asDouble() << endl;
			 wait();
		 }
		 nt.reset();
	 }
	 cout << "Average process creation time: "
	 				 << average(sum, repeat)
	 				 << endl;
}

/* runProcess() creates, runs, and times process system calls
 * @param: repeat, the number of times you want to repeat this system call.
 */
void Model::runThread(int repeat)
{
	NanoTimer nt;
	double sum = 0.0;
	sum = 0.0;
	nt.reset();
	pthread_t threads[repeat];

	for( int i = 0; i < repeat; i++)
	{
		nt.start();
		//start a thread
		pthread_create(&threads[i], NULL, printHello, (void*)i);
		nt.stop();
		pthread_join(threads[i], NULL);
		sum += nt.asDouble();

		nt.reset();
	}
	cout << "Average thread creation time: "
		 			<< average(sum, repeat)
		 			<< endl;
}

