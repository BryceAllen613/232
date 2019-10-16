/*
 * CommandLine.h
 * Reads information from the console and parses the command line (class definition)
 * cs232
 * Adams
 *  Created on: Mar 29, 2019
 *      Author: bda5
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cstring>

using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const;
	int getArgCount() const;
	char** getArgVector() const;
	char* getArgVector(int i) const;
	bool noAmpersand() const;

private:
	bool ampersand = false;
	int argc;
	char** argv;
};

#endif /* COMMANDLINE_H_ */
