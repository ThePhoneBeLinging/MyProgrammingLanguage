#include <iostream>
#include "src/FileUtility.h"

int main()
{
    FileUtility::write("../compiled.txt", FileUtility::read("../example.txt"));
    return 0;
}
