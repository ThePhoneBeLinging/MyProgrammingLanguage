//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//


#include "Lexer.h"

#include <stdlib.h>

void lexer(char* code, char* buffer, int size, Node* head)
{
    // Code here
}

void initializeKeyWords(struct Node* head)
{
    head->value = "number";
    head->tokenName = "NUMBER";
}
