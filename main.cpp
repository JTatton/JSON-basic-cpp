#include "BasicJSON.h"
#include <iostream>

int main()
{
  BasicJSON bjson("test.json");

  std::cout << bjson.getFileContents() << std::endl;

  return 0;
}