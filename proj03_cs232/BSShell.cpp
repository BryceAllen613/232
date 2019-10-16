/*
 * BSShell.cpp
 * Runs the command shell (method definitions)
 * cs232
 * Adams
 * Created on: Mar 29, 2019
 * Author: Bryce Allen and Sean Jacobsma
 */

#include "BSShell.h"


BSShell::BSShell()
{}

/**
 * Executes the command shell using an infinite loop
 */
void BSShell::run()
{
	while(true)
	{
		myPrompt = Prompt();
		cout << myPrompt.get() + "$ " << flush;
		CommandLine cl(cin);
		myCommand = cl.getCommand();
		string command = myCommand;

		if (command == "exit")
		{
			kill(pid, SIGKILL);
			exit(0);
		}
		else
		{
			if( command == "cd" )
			{
				char buf[1000];
				char * gdir = getcwd(buf, sizeof(buf));
				char * dir = strcat(gdir, "/");
				char * to = strcat(dir, cl.getArgVector(1));
				chdir(to);
			}
			else
			{
				pid = fork();
				if( pid == 0 )
				{
					const string w = myPath.getDirectory(myPath.find(command)).c_str();
					char* s = (char*) ((w + '/' + command).c_str());
					execve((const char*) s,(char* const*) cl.getArgVector(), NULL);
					kill(pid, SIGKILL);
				}
				else if(cl.noAmpersand())
				{
					waitpid(pid, NULL, 0);
				}
			}
		}
	}
}




