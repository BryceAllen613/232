/*
 * Prompt.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Sean Jacobsma
 *   Professor: Adams
 * 		 class: CS 232
 */

#include "Prompt.h"
#include <stdlib.h>
#include <stdio.h>
#include <linux/limits.h>
using namespace std;


/* the Prompt gets the current working directory path
 * it stores this in the protected string "path"
 */
Prompt::Prompt() {
	char buffer[PATH_MAX];
	if(getcwd(buffer, PATH_MAX) != NULL){
		path = (string)buffer;
	}
}

/* this function returns the path of
 * the current working directory
 */
string Prompt::get() const {
	return path;
}
