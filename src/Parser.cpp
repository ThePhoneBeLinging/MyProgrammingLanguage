//
// Created by Elias Aggergaard Larsen on 04/09/2024.
//

#include "Parser.h"


std::string Parser::parseToC(std::vector<Item> items)
{
    std::string code;
    code += "#include <stdio.h>\n";
    code += "int main()\n";
    code += "{\n";

    for (const auto& item : items)
    {
        code += "printf(";
        code += '"' + item.type() + "\\n" + '"';
        code += ");\n";
    }

    code += "return 0;\n";
    code += "}\n";
    return code;
}
