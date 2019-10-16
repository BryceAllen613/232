/*
 * Path.cpp
 *
 *  Created on: Mar 29, 2019
 *      Author: Sean Jacobsma
 *   Professor: Adams
 * 		 class: CS 232
 */

#include "Path.h"

using namespace std;

/* This is the consructor for the path class
 * path has a protected variable myPath
 * this is a sring vector which stores everything in the "PATH" environment
 */
Path::Path(){
	stringstream Path(getenv("PATH"));
	string chunk;
	while(! Path.eof()){
		getline(Path, chunk, ':');
		myPath.push_back(chunk);
	}
}

/* the find function searches the path
 * for a program decalared as an argument
 */
int Path::find(const string& program){
	DIR *dir;
	struct dirent *entry;
	for (int i=0; i < (int)myPath.size(); i++){
		dir = opendir(myPath[i].c_str());
		while((entry = readdir(dir)) != NULL ){
			if ((string)entry->d_name == program){
				return i;
			}
		}
		closedir(dir);
	}
	return -1;
}

/* the get directory function returns the directory
 * in the myPath vector that matches the input i
 */
string Path::getDirectory(int i){
	return myPath[i];
}
