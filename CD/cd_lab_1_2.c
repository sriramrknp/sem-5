// CS20B1107 SRIRAM REDDY CHEERLA
// CD Lab Ex - 2

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    FILE *f = NULL, *n = NULL;

    f = fopen("input2.txt", "r");
    n = fopen("output2.txt", "w");
    if (f == NULL || n == NULL)
    {
        printf("Error");
        exit(1);
    }

    char c[100];
    int ind1 = -1;

    // fgets reads each line as a string
    // from start END OF FILE (each line), then
    // we store the string each time
    // in c, and read the string each time
    // from start to end and put each character except
    // space(' '), new line character('\n') and
    // comments(single line and multiline)
    // into the output.txt file

    while(fgets(c, 100, f) != NULL)
    {
        int ind = -1;
        int len = strlen(c);
        for (int i = 0; i < (len - 1); i++)
        {
            if(c[i] == '/' && c[i+1] == '/')
                ind = i;
            if (c[i] == '/' && c[i + 1] == '*')
                ind1++;
            if (c[i] == '*' && c[i + 1] == '/')
            {    
                ind1--;
                ind = 0;
            }
        }

        // condition for comments line
        if(ind1 != -1) continue;
        if(ind != -1) continue;

        for (int i = 0; i < len; i++)
        {
            if (c[i] == ' ' || c[i] == '\n')
                continue;
            else
            {
                fputc(c[i], n);
            }
        }
    }

    printf("\n");
    fclose(f);
}