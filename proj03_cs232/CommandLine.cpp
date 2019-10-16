/*
 * CommandLine.h
 * Reads information from the console and parses the command line (method definitions)
 * cs232
 * Adams
 *  Created on: Mar 29, 2019
 *      Author: bda5
 */

#include "CommandLine.h"
#include <vector>
#include <sstream>
#include <iterator>
#include <cstring>

/* constructor for CommandLine
 * @param in: the istream we would read the command line from
 */
CommandLine::CommandLine(istream& in)
{
	argc = 0;
	string input = "";
	getline(in, input);
	stringstream ss(input);

	string s;

	vector<string> vec;
	while(ss >> s)
	{
		vec.push_back(s);
		argc++;
	}

	argv = (char**)calloc(argc, sizeof(const char));

	for( int i = 0; i < argc; i++ )
	{
		//argv[i] = vec[i].c_str();
		//cout << argv[i] << flush;
		char* temp = (char*)calloc(sizeof(vec[i])+1,sizeof(char));
		temp[sizeof(vec[i])] = '\0';
		temp = (char*) vec[i].c_str();
		for(int j = 0; j < sizeof(vec[i]); j++)
		{
			temp[j] = vec[i][j];
		}
		argv[i] = temp;
		//cout << argv[i] << flush;
	}

	if(argc != 0){
		if(argv[argc-1][0] == '&'){
			ampersand = true;
			argc--;
		}
	}


}

/* simply returns the first element in argv, which is the command to be performed
 * @return The command that need to be performed as a char*.
 */
char* CommandLine::getCommand() const
{ return argv[0]; }

/* returns number of arguments in this command line.
 * @return argc, which is the counter for the number of command line arguments.
 */
int CommandLine::getArgCount() const
{ return argc; }

/* returns all the 'words' from the command line.
 * @return argv: which contains all the command line arguments.
 */
char** CommandLine::getArgVector() const
{ return argv; }

/* returns an element at a specified index in argv.
 * @param i: the index for the element we want to access.
 * @return: argv[i]
 */
char* CommandLine::getArgVector(int i) const
{ return argv[i]; }

/* returns true if there is no ampersand in the command line
 * false otherwise.
 */
bool CommandLine::noAmpersand() const
{
//	string s = "";
//	for( int i = 0; i < argc; i++ ){
//		s = argv[i];
//		if( s.find('&') != string::npos )
//			return false;
//	}
//	return true;
	return !ampersand;
}
