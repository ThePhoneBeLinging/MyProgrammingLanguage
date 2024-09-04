//
// Created by Elias Aggergaard Larsen on 04/09/2024.
//

#ifndef PARSER_H
#define PARSER_H
#include <string>
#include "Item.h"
#include <vector>

class Parser
{
public:
    static std::string parseToC(std::vector<Item> items);
};


#endif //PARSER_H
