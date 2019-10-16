/*
 * BSShell.cpp
 * Runs the command shell (class definition)
 * cs232
 * Adams
 * Created on: Mar 29, 2019
 * Author: Bryce Allen and Sean Jacobsma
 */

#ifndef BSSHELL_H_
#define BSSHELL_H_

#include <string>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include "CommandLine.h"
#include "Path.h"
#include "Prompt.h"
using namespace std;

class BSShell {
public:
	BSShell();
	void run();
protected:
	Prompt myPrompt;
	Path myPath;
	char* myCommand;
	pid_t pid;
};

#endif /* BSSHELL_H_ */
