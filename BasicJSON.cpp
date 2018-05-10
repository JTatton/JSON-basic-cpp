#include "BasicJSON.h"

BasicJSON::BasicJSON(std::string file){
  BasicJSON::fileNameLoc = file;
  readFile();
}

void BasicJSON::setFileLocation(std::string file){

}

std::string BasicJSON::getValue(std::string key){
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