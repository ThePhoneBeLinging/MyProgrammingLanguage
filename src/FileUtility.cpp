//
// Created by Elias on 03/09/2024.
//

#include <sstream>
#include <fstream>
#include "FileUtility.h"

std::string FileUtility::read(const std::string &path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void FileUtility::write(const std::string &path, const std::string &content)
{
    std::ofstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }
    file.write(content.c_str(), content.size());
}
