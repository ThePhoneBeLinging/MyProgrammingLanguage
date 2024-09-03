cmake_minimum_required(VERSION 3.28)
project(MyProgrammingLanguage)

set(CMAKE_CXX_STANDARD 20)

add_executable(MyProgrammingLanguage main.cpp
        src/FileUtility.cpp
        src/FileUtility.h
        src/Lexer.cpp
        src/Lexer.h)
