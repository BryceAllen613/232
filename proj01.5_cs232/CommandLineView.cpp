/*
 * CommandLineView.cpp
 * method definitions for command line view class
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#include "CommandLineView.h"
#include <iostream>

using namespace std;

/* explicit constuctor for the class, takes in two bools to represent the process and thread
 * commands from the user and assigns them to corresponding instance variables.
 */
CommandLineView::CommandLineView(bool thread1, bool process1, int repeat1) {
	thread = thread1;
	process = process1;
	repeat = repeat1;
}

/* getView creates an instance of model and calls runThread and runProcess when necessary
 */
void CommandLineView::getView()
{
	Model md;
	if(thread)
	{
		cout << "thread was called." << endl;
		md.runThread(repeat);
	}
	if(process)
	{
		cout << "process was called." << endl;
		md.runProcess(repeat);
	}
}

