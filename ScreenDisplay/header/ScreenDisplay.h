#ifndef __SCREEN_DISPLAY_H__
#define __SCREEN_DISPLAY_H__

#include <string>
#include "ReadScreenFile.h"
#include "Hotbar.h"

//only concerned with showing screens.
class ScreenDisplay{
	public:
		ScreenDisplay();
		void display(const std::string& filename, int index, const std::string& hotbarText, bool extra);
		void setScreen(const std::string& filename, int mode);
		std::string getScreen();
		void displayEnemy(const std::string& filename, const std::string& enemyName);

	private:
		ReadScreenFile reader;
		Hotbar hbar;
		std::string screen;
		void clear();
		void displayScreen();
		void displayHotbar(const std::string& hotbarText, bool extra);
		
	
};

#endif