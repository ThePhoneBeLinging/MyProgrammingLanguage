cmake_minimum_required(VERSION 3.28)
project(MyProgrammingLanguage)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyProgrammingLanguage main.cpp
        src/FileReader.cpp
        src/FileReader.h)
