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

void Lexer::tokenize(std::string code)
{
    code += ' ';
    bool inQuotes = false;
    bool inComment = false;
    initializeKeywords();
    std::string token;
    for (char character : code)
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

        if (character == ' ' || character == '\n')
        {
            if (inQuotes || inComment)
            {
                continue;
            }
            if (isKeyWord(token))
            {
                tokens_.emplace_back("keyword", token);
            }
            else if (isStringOrChar(token))
            {
                token.erase(std::remove(token.begin(), token.end(), '"'), token.end());
                if (token.size() == 3)
                {
                    tokens_.emplace_back("char", token);
                }
                else
                {
                    tokens_.emplace_back("string", token);
                }
            }
            else if (isFloat(token))
            {
                tokens_.emplace_back("float", token);
            }
            else if (isInteger(token))
            {
                tokens_.emplace_back("integer", token);
            }
            else
            {
                tokens_.emplace_back("identifier", token);
            }
            token.clear();
            continue;
        }
        token += character;
    }
}

std::vector<Item> Lexer::getTokens()
{
    return tokens_;
}

bool Lexer::isKeyWord(const std::string& token)
{
    for (auto& keyword : keywords_)
    {
        if (token == keyword)
        {
            return true;
        }
    }
    return false;
}

bool Lexer::isStringOrChar(const std::string& str)
{
    return str.size() >= 2 && str.front() == '"' && str.back() == '"';
}

bool Lexer::isInteger(const std::string& str)
{
    std::regex intRegex(R"([+-]?[0-9]+)");
    return std::regex_match(str, intRegex);
}

bool Lexer::isFloat(const std::string& string)
{
    std::regex floatRegex(R"([+-]?([0-9]*[.])+[0-9]+)");
    return std::regex_match(string, floatRegex);
}
