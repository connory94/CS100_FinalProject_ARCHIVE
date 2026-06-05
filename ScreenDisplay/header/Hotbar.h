#ifndef __HOTBAR_H__
#define __HOTBAR_H__

#include <string>

class Hotbar{
	public:
		Hotbar();
		void displayHotbar(const std::string& info, bool extra); 
		void displayIntro(int progress);

		std::string getOptions();
		
	private:
		std::string options;

};

#endif