// CS20B1107 SRIRAM REDDY CHEERLA
// CD Lab Ex - 1

#include <stdio.h>
#include <stdlib.h>

int main() 
{
    FILE *f = NULL, *n = NULL;

    f = fopen("input.txt", "r");
    n = fopen("output.txt", "w");
    if (f == NULL)
    {
        printf("Error");
        exit(1);
    }

    char c;

    // fgetc reads each and every charater
    // from start END OF FILE, then
    // we store the character each time
    // in c, and put each character except
    // space(' ') and new line character('\n')
    // into the output.txt file
    while ((c = fgetc(f)) != EOF)
    {
        if (c == ' ' || c == '\n')
        {
            continue;
        }
        else{
            fputc(c, n);
        }
    }
    printf("\n");
    fclose(f);
}