/*
 * CommandLineView.h
 * method signatures and instance variables for the comand line view class
 *  Created on: Feb 26, 2019
 *      Author: Bryce Allen
 */
#include "Model.h"
#ifndef COMMANDLINEVIEW_H_
#define COMMANDLINEVIEW_H_

class CommandLineView {
public:
	CommandLineView(bool thread1, bool process1, int repeat1);
	void getView();
private:
	bool thread;
	bool process;
	int repeat;
};

#endif /* COMMANDLINEVIEW_H_ */
