/*
 * callTimer.cpp
 * runs a program that times system calls
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */

#include <stdio.h>
#include <pthread.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include "CommandLineController.h"
#include "TextBasedController.h"

using namespace std;

/* main driver function
 * @param argc: the number of arguments form command line.
 * @param argv: the (dynamic) array representing the list of command line arguments.
 */
int main( int argc, char* argv[] )
{
	bool commandLine = false;

	//processes the command line
	for(int i = 0; i < argc; i++)
		if(string(argv[i]) == "-cl")
			commandLine = true;

	//if the -cl switch is present then create instance of clc class
	//pass it argc and argv and anything else needed
	if(commandLine)
		CommandLineController clc(argc, argv);
	else//create instance of other controller class (text menu)
		TextBasedController tbc(argc, argv);
}


