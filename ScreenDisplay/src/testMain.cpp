#include <iostream>
#include <string>

#include "../header/ScreenDisplay.h"

using namespace std;

//purely for testing purposes only.

/*
HOW TO USE:
============================
	- only need to include ScreenDisplay.h. other files are included there.
	- make instance of ScreenDisplay, (in this case, "screen")
	
	- display() function takes name of text file, index of text file, and hotbar text.
	- to demo, traverse to ScreenDisplay folder in terminal & use these commands:
		- $ g++ -o displayTest.out src/testMain.cpp src/ScreenDisplay.cpp src/Hotbar.cpp src/ReadScreenFile.cpp
		- $ ./displayTest.out

*/


int main(){
	unsigned int inputIdle = 0;
	
	ScreenDisplay screen;
	screen.display("txtfiles/intro.txt", 0, "INTRO0", false);
	cin >> inputIdle;
	inputIdle = 0;

	unsigned int embark = 0;
	while(embark == 0){
		screen.display("txtfiles/intro.txt", 1, "INTRO1", false);
		while(inputIdle == 0 || inputIdle > 5){
			cin >> inputIdle;
		}

		screen.display("txtfiles/intro.txt", inputIdle+1, "INTRO2", false);
		inputIdle = 0;

		while(inputIdle == 0 || inputIdle > 2){
			cin >> inputIdle;
		}
		if(inputIdle == 1){
			embark = 1;
		}
		inputIdle = 0;
	}
	screen.display("txtfiles/map.txt", 0, "Onwards! You are now entering the Starter Forest...\nEnter anything to continue \n", false);

	cin >> inputIdle;

	screen.displayEnemy("txtfiles/monsters.txt","Sand Worm");
	//placeholder image
	//screen.display("txtfiles/intro.txt", 8, "Example Text \nhello123\n");
	
	return 0;
}