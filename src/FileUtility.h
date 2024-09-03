//
// Created by Elias on 03/09/2024.
//

#ifndef MYPROGRAMMINGLANGUAGE_FILEUTILITY_H
#define MYPROGRAMMINGLANGUAGE_FILEUTILITY_H


#include <string>

class FileUtility
{
public:
    static std::string read(const std::string& path);
    static void write(const std::string& path, const std::string& content);
};


#endif //MYPROGRAMMINGLANGUAGE_FILEUTILITY_H
