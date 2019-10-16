/*
 * Path.h
 *
 *  Created on: Mar 29, 2019
 *      Author: Sean Jacobsma
 *   Professor: Adams
 * 		 class: CS 232
 */

#ifndef PATH_H_
#define PATH_H_

#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
using namespace std;

class Path {
public:
	Path();
	int find(const string& program);
	string getDirectory(int i);

protected:
	vector <string> myPath;

};



#endif /* PATH_H_ */
