//
// Created by Elias on 03/09/2024.
//

#ifndef MYPROGRAMMINGLANGUAGE_LEXER_H
#define MYPROGRAMMINGLANGUAGE_LEXER_H


#include <string>
#include <vector>

class Lexer
{
public:
    static void tokenize(std::string code);

    static void initializeKeywords();

    static std::vector<std::string> getTokens();

private:
    static bool isKeyWord(const std::string &token);

    static inline bool isStringOrChar(const std::string &string);

    static inline bool isInteger(const std::string &string);

    static inline std::vector<std::string> tokens_;
    static inline std::vector<std::string> keywords_;
};


#endif //MYPROGRAMMINGLANGUAGE_LEXER_H
