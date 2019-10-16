/*
 * Prompt.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Sean Jacobsma
 *   Professor: Adams
 * 		 class: CS 232
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <string>
#include <unistd.h>
using namespace std;

class Prompt {
public:

	Prompt();
	string get() const;
protected:
	string path;
};


#endif /* PROMPT_H_ */
