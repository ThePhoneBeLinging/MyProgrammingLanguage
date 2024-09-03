cmake_minimum_required(VERSION 3.28)
project(MyProgrammingLanguage C)

set(CMAKE_C_STANDARD 17)

add_executable(MyProgrammingLanguage main.c
        Lexer.h
        Lexer.c
        Node.h
)
