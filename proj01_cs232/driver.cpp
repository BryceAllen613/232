/*
 * main.cpp
 * uses CallTimer to run a program that times system calls
 *  Created on: Feb 10, 2019
 *      Author: Bryce Allen
 */

#include "CallTimer.h"
#include <stdio.h>
#include <pthread.h>
#include <iostream>


using namespace std;

/* main driver function
 * @param argc: the number of arguments form command line.
 * @param argv: the (dynamic) array representing the list of command line arguments.
 */
int main( int argc, char* argv[] )
{
	CallTimer ct;
	ct.run(argc, argv);
}


