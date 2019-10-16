/*
 * CommandLineController.cpp
 *	a controller for the command line user interface
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#include "CommandLineController.h"

#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "NanoTimer.h"

/* explicit constructor takes in argc and argv to identify what actions
 * the user wants to take
 */
CommandLineController::CommandLineController(int argc, char* argv[]) {
	//traverse argv to see what commands were passed
	//parsing the command line
	thread = false;
	process = false;
	repeat = 1;
	for(int i = 1; i < argc; i++)
	{
		if( string(argv[i]) == "-t" || string(argv[i]) == "-thread" )
			thread = true;
		else if( string(argv[i]) == "-p" || string(argv[i]) == "-process" )
			process = true;
		else if( string(argv[i]).substr(0,2) == "-r" )
		{
			string command = string(argv[i]);
			int length = command.length();
			repeat = atoi(command.substr(2,length).c_str());
		}
		else if(string(argv[i]) == "-cl"){}
		else
		{
			cout<< "USAGE ERROR: improper entry" << endl;
			exit(0);
		}
	}
	//at this point we should know what we want to test
	//thread, process, and how many times we want to repeat...
	run();
}

/* creates an instance of command line view and runs it
 */
void CommandLineController::run()
{
	//create an instance of CommandLineView and pass it thread process and repeat
	CommandLineView clv(thread, process, repeat);
	clv.getView();
}

