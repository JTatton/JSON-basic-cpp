#ifndef BASICJSON_H
#define BASICJSON_H

#include <string>
#include <fstream>
#include <iostream>
#include <regex>

class BasicJSON
{
public:
  BasicJSON(std::string file);            // file is location relative to current 
                                          // directory and filename with extension
                                          // e.g. "/dir/file.json"

  void setFileLocation(std::string file); // sets file location e.g "/dir/file.json"
                                          // then calls read file

  std::string getValue(std::string key);  // returns the value matching the key
                                          // always as a string - future update 
                                          // may change

  std::string getFileContents();          // returns the string containing file
                                          // contents. Mainly to be used for
                                          // testing

private:
  std::string fileNameLoc;                // stores directory/name of file
  std::string fileContents;               // stores contents of the file

  void readFile();                        // reads from file at fileNameLoc
                                          // into string fileContents also 
                                          // removes spaces

  std::string readBetweenQuotes(unsigned int* position);

  unsigned int positionInFile;
  unsigned int* posPtr;
  
};

#endif //BASICJSON_H