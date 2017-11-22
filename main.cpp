#include "readFile.h"
#include <iostream>

using namespace std;

int main()
{
	ReadFile newFile;

	newFile.inputFile();

	for(int i = 0; i<200; i++)
	{
		cout << newFile.nextChar();
	}

	cout << endl;

	return 0;
}