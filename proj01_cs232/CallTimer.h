/*
 * CallTimer.h
 * a class that times system calls such as fork() and pthread_create()
 *  Created on: Feb 13, 2019
 *      Author: Bryce Allen
 */

#ifndef CALLTIMER_H_
#define CALLTIMER_H_

class CallTimer {
public:
	CallTimer();
	double average(double sum, unsigned numData);
	void run(int argc, char* argv[]);
};

#endif /* CALLTIMER_H_ */
