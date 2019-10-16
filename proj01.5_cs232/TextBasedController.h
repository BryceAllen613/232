/*
 * TextBasedController.h
 * method signatures and instance variables for the text based controller class
 *  Created on: Feb 28, 2019
 *      Author: Bryce Allen
 */

#ifndef TEXTBASEDCONTROLLER_H_
#define TEXTBASEDCONTROLLER_H_
#include "TextBasedView.h"
class TextBasedController {
public:
	TextBasedController(int argc, char* argv[]);
	void run();
private:
	bool process;
	bool thread;
	unsigned repeat;
};

#endif /* TEXTBASEDCONTROLLER_H_ */
