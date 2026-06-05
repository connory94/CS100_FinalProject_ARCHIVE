#ifndef __READ_SCREEN_FILE_H__
#define __READ_SCREEN_FILE_H__

#include <iostream>
#include <fstream>
#include <string>

// this website: https://www.asciiart.eu/image-to-ascii
// using size of 126 characters
// using minimalist gradient
// using this image as a base: https://media.discordapp.net/attachments/1291931693896306721/1509698968521674852/bordertest.png?ex=6a1a203a&is=6a18ceba&hm=0ecc4649e9bcc369263701921aea33d2c6a46a1ae0dbd17203914617a2fead0e&=&format=webp&quality=lossless&width=1724&height=1293

//reads from file to get screen
class ReadScreenFile{
	public:
		ReadScreenFile();
		bool readFile(const std::string& filename, unsigned int select);
		std::string getReadText();

	private:
		std::string readText;
};

#endif