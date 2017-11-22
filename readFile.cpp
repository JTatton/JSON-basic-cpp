#include "readFile.h"

int ReadFile::location = 0;

void ReadFile::inputFile()
{
	string lineBuffer = "";

	int i = 0;

	while(getline(cin, lineBuffer))
	{
		for(int j = 0; j < lineBuffer.length(); j++)
		{
			fileBuffer += lineBuffer[j];
		}
	}

}

char ReadFile::nextChar()
{
	if(location < fileBuffer.length())
	{
		return fileBuffer[location++];
	}
	else
	{
		return '\0';
	}
}