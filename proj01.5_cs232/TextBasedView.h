/*
 * TextBasedView.h
 * method signatures and instance variables for the text based view class
 *  Created on: Feb 28, 2019
 *      Author: Bryce Allen
 */

#ifndef TEXTBASEDVIEW_H_
#define TEXTBASEDVIEW_H_

class TextBasedView {
public:
	TextBasedView(bool thread1, bool process1, int repeat1);
	void getView();
private:
	bool thread;
	bool process;
	int repeat;
};

#endif /* TEXTBASEDVIEW_H_ */
