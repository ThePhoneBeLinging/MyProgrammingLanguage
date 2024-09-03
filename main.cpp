#include <iostream>
#include "src/FileReader.h"

int main()
{
    std::cout << FileReader::read("../example.txt");
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
