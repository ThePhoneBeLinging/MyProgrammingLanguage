#include <stdio.h>
#include "Lexer.h"

int main(void)
{
    FILE* file = fopen("../example.txt", "r");
    if (file == NULL)
    {
        // Check if file opening succeeded
        perror("Error opening file");
        return 1;
    }
    while (1)
    {
        char buffer[256];
        char c = fgetc(file);
        if (c == EOF || c == ' ' || c == '\n' || c == '\t')
        {
            break;
        }
        printf("%c", c);
    }
    fclose(file);
    return 0;
}
