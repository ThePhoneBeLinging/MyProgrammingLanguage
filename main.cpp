#include <iostream>
#include "src/FileUtility.h"
#include "src/Lexer.h"

int main()
{
    //FileUtility::write("../compiled.txt", FileUtility::read("../example.txt"));
    Lexer::tokenize(FileUtility::read("../example.txt"));
    for (const auto& token : Lexer::getTokens())
    {
        std::cout << token.type() << std::endl;
    }
    return 0;
}
