/*
 * CommandLineController.h
 * method signatures and instance variables for the command line view class
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#include "CommandLineView.h"
#ifndef COMMANDLINECONTROLLER_H_
#define COMMANDLINECONTROLLER_H_

class CommandLineController {
public:
	CommandLineController(int argc, char* argv[]);
	void run();
private:
	bool process;
	bool thread;
	unsigned repeat;
};

#endif /* COMMANDLINECONTROLLER_H_ */
