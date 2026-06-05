#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../header/ScreenTransition.h"

using namespace std;

//a lot of this will likely be rewritten to fit other ppl's functions
ScreenTransition::ScreenTransition(){
	input = 0;
	progress = 0;
	area = 0;

	//we could save a lot of trouble by having each area follow the same pattern
	maxIndex = {
		{1, 4, 2}, //intro
		{1, 2, 2}, //forest
		{2, 2, 2, 8}, //desert
		{3},		//kingsland
		{8}			//
	};
}

//use cin to get number from input, probably also detect when input is invalid.
void ScreenTransition::getInput(){ 
	unsigned int in = 0;
	unsigned int max = maxIndex[area][progress];
	while(true){
		cin >> in;
		if (cin.fail()) { //apparently we need to clear bad inputs.
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
		else if((!cin.fail()) && !(in < 1 || in > max)){
			break; //good input
		}
		else{
			cout << "invalid input, try again: " << endl;
		}
	}
	input = in;
}

//all all the transition logic for areas.
//maybe we don't need this, put in a separate folder for now.
//Jude implemented his own version of area traversal, call his functions.
void ScreenTransition::transition(){
	switch(area){
		case(0):	//intro
			switch(progress): 
				case(0):	//title
					if(input == 1){
						setProgress(1);
					}
					break;
				case(1):	//class select (probably want to add stat change functions later)
					if(input == 1){setProgress(2);}
					else if(input == 2){setProgress(3);}
					else if(input == 3){setProgress(4);}
					else if(input == 4){setProgress(5);}
					break;
				case(2):	//knight stats + class confirm
					if(input == 1){
						setArea(1);
						setProgress(0);
					}
					else if(input == 2){
						setProgress(0);
					}
					break;
				case(3):	//assassin stats + class confirm
					if(input == 1){
						setArea(1);
						setProgress(0);
					}
					else if(input == 2){
						setProgress(0);
					}
					break;
				case(4):	//tank stats + class confirm
					if(input == 1){
						setArea(1);
						setProgress(0);
					}
					else if(input == 2){
						setProgress(0);
					}
					break;
				case(5):	//mage stats + class confirm
					if(input == 1){
						setArea(1);
						setProgress(0);
					}
					else if(input == 2){
						setProgress(0);
					}
					break;
			break;
		case(1):	//forest
			break;
		case(2):	//caves
			break;	
		case(3):	//desert
			break;
		case(4):	//kingsland
			break;
	}
}

//=======================
// setters & getters
//=======================

//how far into an area we are
//like pages i n a choose-your-own-adventure book
int ScreenTransition::getProgress(){
	return progress;
}

//area of map we're in
int ScreenTransition::getArea(){
	return area;
}

void ScreenTransition::setProgress(int newProgress){
	progress = newProgress;
}

void ScreenTransition::setArea(int newArea){
	area = newArea;
}


