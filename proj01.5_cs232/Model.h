/*
 * Model.h
 * a class dedicated to timing system calls (threads and processes) and printing their
 * times and averages to the console.
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#ifndef MODEL_H_
#define MODEL_H_

class Model {
public:
	Model();
	double average(double sum, unsigned numData);
	void runThread(int repeat);
	void runProcess(int repeat);
};

#endif /* MODEL_H_ */
