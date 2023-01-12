// CS20B1107 SRIRAM REDDY CHEERLA
// CD Lab Ex - 3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *f = NULL;

    f = fopen("input3.txt", "r");
    if (f == NULL)
    {
        printf("Error");
        exit(1);
    }
    char ch = 'a';
    char ans[100][100];
    int k = 0, l = 0,temp=0;
    char *ptr = &ch;

    while (ptr != NULL)
    {
        char c[100];
        ptr = fgets(c, 100, f);
        int len = strlen(c);
        int i = 0;

        for (i = 0; i < len; i++)
        {
            if(c[i] == ' ' || c[i] == '\n')
            {
                k = temp;
                l = 0;
            }
            else 
            {
                if(k == temp && temp != 0){
                    k = temp + 1;
                }
                ans[k][l] = c[i];
                temp = k;
                l++;
            }
        }
    }
    k++;
    
    for (int i = 0; i < k; i++)
    {
        int len1 = strlen(ans[i]);
        for (int j = 0; j < len1; j++)
        {
            printf("%c", ans[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    fclose(f);
}

// for ( int e = 0; e < len; e++)
// {
//     printf("%c", c[e]);
// }
// printf("\n");