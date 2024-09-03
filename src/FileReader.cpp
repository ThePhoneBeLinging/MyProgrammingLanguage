//
// Created by Elias on 03/09/2024.
//

#include <sstream>
#include <fstream>
#include "FileReader.h"

std::string FileReader::read(std::string path)
{
    std::ifstream file(path);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file");
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
