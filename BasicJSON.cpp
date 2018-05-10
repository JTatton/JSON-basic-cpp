#include "BasicJSON.h"

using namespace std;

BasicJSON::BasicJSON(std::string file){
  BasicJSON::fileNameLoc = file;
  readFile();
  BasicJSON::positionInFile = 0;
  BasicJSON::posPtr = &positionInFile;
}

void BasicJSON::setFileLocation(std::string file){
  BasicJSON::fileNameLoc = file;
}

std::string BasicJSON::readBetweenQuotes(unsigned int *position)
{
  std::string temp;

  for (*position; *position < fileContents.length(); (*position)++)
  {
    //cout << fileContents[*position] << endl;
    if (fileContents[*position] != '"')
    {
      while(fileContents[*position] != '"')
      {
        temp += fileContents[*position];
        (*position)++;
      }
      break;
    }
  }

  return temp;
}

std::string BasicJSON::getValue(std::string key){
  //unsigned int positionInFile = 0;
  //unsigned int* posPtr = &positionInFile;

  std::string value = "";

  for ((*posPtr); (*posPtr) < fileContents.length(); (*posPtr)++)
  {
    if (fileContents[positionInFile] == '"')
    {
      (*posPtr)++;
      if(readBetweenQuotes(posPtr) == key)
      {
        (*posPtr)++;
        (*posPtr)++;

        if(fileContents[(*posPtr)] != '"')
        {
          return "ERROR - Not String Value";
        }

        (*posPtr)++;

        return readBetweenQuotes(posPtr);
      }

    }

  }

  return "ERROR";
}

void BasicJSON::readFile(){
  std::ifstream inputFile(fileNameLoc);

  if(!inputFile.is_open())
  {
    std::cout << "ERROR: input file cannot be opened" << std::endl;
  }
  else
  {

    std::string lineBuffer;

    while(std::getline(inputFile, lineBuffer))
    {
      for (unsigned int i = 0; i < (lineBuffer.length() - 1); i++)
      {
        if (lineBuffer[i] != ' ') //removes spaces
        {
          fileContents += lineBuffer[i];
        }
      }
    }

  }

}

std::string BasicJSON::getFileContents()
{
    return fileContents;
}