#include "BasicJSON.h"
#include <iostream>

int main()
{
  BasicJSON bjson("traintest.json");

  //std::cout << bjson.getFileContents() << std::endl;

  std::cout << bjson.getValue("DestinationAimedArrivalTimeSpecified") << std::endl;

  return 0;
}