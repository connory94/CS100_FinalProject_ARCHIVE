#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "../header/ReadScreenFile.h"

using namespace std;

//constructor
ReadScreenFile::ReadScreenFile(){
	readText = R"()";
}

//basic getter
string ReadScreenFile::getReadText(){
	return readText;
}


//read file, return false if fails
//each screen is 50 lines tall. separated by empty lines
//reads until we reach the screen we want, based on select
bool ReadScreenFile::readFile(const string& filename, unsigned int select){
	ifstream data(filename);
	if(!data.is_open()){
		cout << "read failed!" << endl;
		readText = "failed to read " + filename + "\n";
		return false;
	}

	string line = "";
	string currentScreen = "";
	int skip = 51*select + select;
	
	//amount of lines we skip to get to the right screen
	for(int i = 0; i < skip; i++){
		getline(data, line);
	}

	//grab the lines we do want, add to currentScreen
	for(int i = 0; i < 51; i++){
		if(getline(data, line)){
		currentScreen += line + "\n";
		}
		else{break;}
	}

	data.close();
	readText = currentScreen;
	return true;
}