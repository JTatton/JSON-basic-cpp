#ifndef READFILE_H
#define READFILE_H

#include <string>
#include <iostream>

using namespace std;

class ReadFile
{
public:
	void inputFile();
	char nextChar();
private:
	static int location;
	string fileBuffer;
};

#endif //READFILE_H