#include <string>
#include <iostream>
#include "../header/ReadScreenFile.h"
#include "../header/ScreenDisplay.h"
#include "../header/Hotbar.h"

using namespace std;

ScreenDisplay::ScreenDisplay(){
	screen = "";
}

//passes in mode, file to read from, 
void ScreenDisplay::display(const string& filename, int screenIndex, const string& hotbarText, bool extra){
	clear();
	setScreen(filename, screenIndex);
	displayScreen();
	displayHotbar(hotbarText, extra);
}

void ScreenDisplay::setScreen(const string& filename, int index){
	if(reader.readFile(filename, index)){
		screen = reader.getReadText();
	}
}

string ScreenDisplay::getScreen(){
	return screen;
}

//displays different enemy based on its name
//apparently I can't use switch cases, so this is the best I can do right now.
void ScreenDisplay::displayEnemy(const string& filename, const string& enemyName){
	int index = 0;
	if(enemyName == "Slime"){
		index = 0;
	}
	else if(enemyName == "Cabin Spirit"){
		index = 1;
	}
	else if(enemyName == "Crystal Golem"){
		index = 2;
	}
	else if(enemyName == "Dark Goblin Shaman"){
		index = 3;
	}
	else if(enemyName == "Gate Keeper"){
		index = 4;
	}
	else if(enemyName == "Goblin Grunt"){
		index = 5;
	}
	else if(enemyName == "The Mad Tyrant"){
		index = 6;
	}
	else if(enemyName == "Oasis Guardian"){
		index = 7;
	}
	else if(enemyName == "Overgrown Bat"){
		index = 8;
	}
	else if(enemyName == "Spider Queen"){
		index = 9;
	}
	else if(enemyName == "Sand Worm"){
		index = 10;
	}
	else if(enemyName == "Ravine's Remnant"){
		index = 11;
	}
	else if(enemyName == "Villager Cultist"){
		index = 12;
	}

	cout << "Index: " << index << endl;

	string enemyMessage = enemyName + " approaches! \n";

	display(filename, index, enemyMessage, true);

}

//=================
//private helpers
//=================

//just make the previous screen not visible
void ScreenDisplay::clear(){
	for(int i = 0; i < 100; i++){
		cout << endl;
	}
}

void ScreenDisplay::displayScreen(){
	cout << screen;
}

//displays information between borders, changes bottom border if additional information is output
void ScreenDisplay::displayHotbar(const string& hotbarText, bool extra){
	//specific cases for handling intro sequence.
	//maybe not necessary?
	if(hotbarText == "INTRO0"){
		hbar.displayIntro(0);
	}
	else if(hotbarText == "INTRO1"){
		hbar.displayIntro(1);
	}
	else if(hotbarText == "INTRO2"){
		hbar.displayIntro(2);
	}
	else{
		hbar.displayHotbar(hotbarText, extra);
	}
}