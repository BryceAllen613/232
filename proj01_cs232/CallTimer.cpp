/*
 * CallTimer.cpp
 * the source file for the CallTimer class; method definitions.
 *  Created on: Feb 13, 2019
 *      Author: Bryce Allen
 */

#include "CallTimer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "NanoTimer.h"
using namespace std;

CallTimer::CallTimer() {}

/**
 * computes the average of a sum of numbers
 * @param sum: a sum of numbers calculated elsewhere
 * @param numData: the number of data points added in sum
 * @return sum/numData
 */
double CallTimer::average(double sum, unsigned numData)
{ return sum / numData; }

/* function for identifying which thread is executing the function.
 * @param arg: the id of the thread executing this function.
 */
void *printHello(void *arg)
{ cout << "hello from child thread (tid: " << (long)arg << ")" << endl; }

/* runs the program with the given command line argument parameters.
 * @param argc: the number of arguments form command line.
 * @param argv: the (dynamic) array representing the list of command line arguments.
 */
void CallTimer::run(int argc, char* argv[])
{
	bool process = false;
	bool thread = false;
	unsigned repeat = 1;

	//traverse argv to see what commands were passed
	//parsing the command line
	for(int i = 1; i < argc; i++)
	{
		if( string(argv[i]) == "-t" || string(argv[i]) == "-thread" )
		{
			thread = true;
			cout << "thread was called." << endl;
		}
		else if( string(argv[i]) == "-p" || string(argv[i]) == "-process" )
		{
			process = true;
			cout << "process was called." << endl;
		}
		else if( string(argv[i]).substr(0,2) == "-r" )
		{
			string command = string(argv[i]);
			int length = command.length();
			repeat = atoi(command.substr(2,length).c_str());
			cout << "repeat was called." << endl;
		}
		else
		{
			cout<< "USAGE ERROR" << endl;
			exit(0);
		}
	}

	//BEGIN: the timing comparison part of the program.
	NanoTimer nt;
	double sum = 0.0;

	//get an average time for fork() startup
	if( process )
	{
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

	if( thread )
	{
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
}
