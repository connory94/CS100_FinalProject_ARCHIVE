#include "../header/Hotbar.h"

#include <string>
#include <iostream>

using namespace std;

Hotbar::Hotbar(){
	options = "Press 1 to Start!";
}

//for multiple lines, please use the following format:
//ex: 1) Strike \n2) Items \n3) Run
void Hotbar::displayHotbar(const string& info, bool extra){
	options = info; //for testing

	cout << "==============================================================================================================================" << endl;
	cout << info;
	if(!extra){
		cout << "==============================================================================================================================" << endl;
	}
	else{
		cout << "------------------------------------------------------------------------------------------------------------------------------" << endl;
	}
}

void Hotbar::displayIntro(int progress){
	switch(progress){
		case(0):
			displayHotbar("Press 1 to Start!\n", false);
			break;

		case(1):
			displayHotbar("Pick your Class! (input 1-4)\n", false);
			break;

		case(2):
			displayHotbar("Are you ready to embark? \n1) Let The Adventure Begin! \n2) Return to Class Select\n", false);
			break;
	}
}

string Hotbar::getOptions(){
	return options;
}