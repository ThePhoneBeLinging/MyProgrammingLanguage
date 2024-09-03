#include <stdio.h>
#include "Lexer.h"

int main(void)
{
    FILE *file = fopen("../example.txt", "r");
    if (file == NULL) {                      // Check if file opening succeeded
        perror("Error opening file");
        return EXIT_FAILURE;
    }
    while (1) {
        char c = fgetc(file);
        if (c == EOF) {
            break;
        }
        printf("%c", c);
    }
    fclose(file);
    return 0;
}
