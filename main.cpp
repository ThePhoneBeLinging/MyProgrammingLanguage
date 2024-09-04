#include <iostream>
#include "src/FileUtility.h"
#include "src/Lexer.h"
#include "src/Parser.h"

int main()
{
    //FileUtility::write("../compiled.txt", FileUtility::read("../example.txt"));
    Lexer::tokenize(FileUtility::read("../example.txt"));

    FileUtility::write("../otherFile.c", Parser::parseToC(Lexer::getTokens()));
    return 0;
}
