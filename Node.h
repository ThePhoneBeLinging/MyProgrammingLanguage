//
// Created by Elias Aggergaard Larsen on 03/09/2024.
//

#ifndef NODE_H
#define NODE_H
#include <stdlib.h>


typedef struct Node {
    struct Node* prev;
    char* value;
    char* tokenName;
    struct Node* next;
} Node;

inline Node* newNode()
{
    Node* node = malloc(sizeof (Node));
    return node;
}

#endif //NODE_H
