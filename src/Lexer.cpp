//
// Created by Elias on 03/09/2024.
//
#include <regex>
#include "Lexer.h"
#include "FileUtility.h"

void Lexer::initializeKeywords()
{
    auto allKeyWords = FileUtility::read("../keywords.txt");
    std::regex newline_regex("\n");
    std::sregex_token_iterator iter(allKeyWords.begin(), allKeyWords.end(), newline_regex, -1);
    std::sregex_token_iterator end;
    keywords_.assign(iter, end);
}

void Lexer::tokenize(const std::string &code)
{
    bool inQuotes = false;
    bool inComment = false;
    initializeKeywords();
    std::string token;
    for (char character: code)
    {
        if (character == '"')
        {
            inQuotes = !inQuotes;
        }
        if (character == '/' && token.back() == '/')
        {
            inComment = true;
        }
        if (character == '\n')
        {
            inComment = false;
        }

        if (character == ' ')
        {
            if (inQuotes || inComment)
            {
                continue;
            }
            if (isKeyWord(token))
            {
                tokens_.push_back(token);
                token.clear();
                continue;
            }


        }
        token += character;

    }
}

std::vector<std::string> Lexer::getTokens()
{
    return tokens_;
}

bool Lexer::isKeyWord(const std::string &token)
{
    for (auto &keyword: keywords_)
    {
        if (token == keyword)
        {
            return true;
        }
    }
    return false;
}
