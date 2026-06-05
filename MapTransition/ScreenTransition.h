#ifndef __SCREEN_TRANSITION_H__
#define __SCREEN_TRANSITION_H__

#include <string>
using namespace std;

//controls how screens are moved through.
//mode is for what the hotbar displays
//progress is how we track where we are in an area.
//like pages in a choose-your-own adventure book
class ScreenTransition(){
	public:
		ScreenTransition();
		void getInput();
		void transition();

		int getProgress();
		int getArea();
		void setProgress(int newProgress);
		void setArea(int newArea);
		
	private:
		unsigned int input;
		unsigned int progress;
		unsigned int area;
		unsigned int maxIndex[5][5];  //for getInput
		unsigned int behavior[5][13]; //for transition
		

}

#endif