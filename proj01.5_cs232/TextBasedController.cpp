/*
 * TextBasedController.cpp
 * .cpp file for the text based controller class.
 *  Created on: Feb 28, 2019
 *      Author: Bryce Allen
 */

#include "TextBasedController.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include "NanoTimer.h"
#include "TextBasedView.h"

/* explicit constructor prompts user to identify what actions
 * the user wants to take
 */
TextBasedController::TextBasedController(int argc, char* argv[]) {
	thread = false;
	process = false;
	repeat = 1;

	string input = "";
	while(true){
		cout << "Welcome to CallTimer!" << endl <<
				"[1] Measure the time of a thread" << endl <<
				"[2] Measure the time of a process" << endl <<
				"[3] Measure the time of a process and a thread" << endl <<
				"[0] Quit" << endl;

		cin >> input;

		if( input == "1" )
			thread = true;
		else if( input == "2" )
			process = true;
		else if( input == "3" )
		{
			thread = true;
			process = true;
		}
		else if( input == "0" )
			exit(0);

		cout << "how many times would you like to repeat?" << endl;
		cin >> repeat;

		run();

		cout << endl;
	}
	//at this point we should know what we want to test
	//thread, process, and how many times we want to repeat...

}

/* creates an instance of text based view and runs it
 */
void TextBasedController::run()
{
	//create an instance of CommandLineView and pass it thread process and repeat
	TextBasedView tbv(thread, process, repeat);
	tbv.getView();
}

