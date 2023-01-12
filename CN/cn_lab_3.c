// cs20b1107, CHEERLA SRIRAM REDDY
// Hamming code, error correction and
// error detection

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char inp[4], s;
    char wthParity[7];
    for (int i = 0; i < 7; i++)
    {
        wthParity[i] = '0';
    }
    printf("Enter the 4 data bits: \n");
    scanf("%s", inp);

    printf("If you want to do in odd parity or even parity\n");
    printf("press e or  o\n");
    scanf(" %c", &s);

    if (s == 'e' || s == 'o')
    {
        int j = 0, a = 1;
        for (int i = 0; i < 7; i++)
        {
            if (i == 3 || i == 5 || i == 6)
            {
                wthParity[i] = '-';
            }
            else
            {
                wthParity[i] = inp[j];
                j++;
            }
        }

        // Printing without parity
        printf("Printing without parity bits\n");
        printf("    ->  ");
        for (int i = 0; i < 7; i++)
        {
            printf("%c", wthParity[i]);
        }
        printf("\n");

        char temp;
        for (int i = 0; i < 4; i++)
        {
            temp = wthParity[6 - i];
            wthParity[6 - i] = wthParity[i];
            wthParity[i] = temp;
        }

        // finding parity bits
        // p1, p2, p4

        int count = 0;
        for (int i = 1; i <= 4; i = (int)pow(2, i))
        {
            for (int j = i - 1; j < 7; j += i)
            {
                int k = i;
                while (k--)
                {
                    if (j > i - 1)
                    {
                        // printf("%d ", j);
                        if (wthParity[j] == '1')
                            count++;
                    }
                    j++;
                }
            }
            // even parity
            if (s == 'e')
            {
                if (count % 2 == 0)
                    wthParity[i - 1] = '0';
                else
                    wthParity[i - 1] = '1';
            }
            // odd parity
            else
            {
                if (count % 2 == 0)
                    wthParity[i - 1] = '1';
                else
                    wthParity[i - 1] = '0';
            }
            count = 0;
        }

        for (int i = 0; i < 4; i++)
        {
            temp = wthParity[6 - i];
            wthParity[6 - i] = wthParity[i];
            wthParity[i] = temp;
        }

        // printing after finding parity bits
        printf("After finding parity bits\n");
        printf("or Encoded message from sender side\n");
        printf("    ->  ");
        for (int i = 0; i < 7; i++)
        {
            printf("%c", wthParity[i]);
        }
        printf("\n");

        // receiver side
        char bit;
        int index = 0;
        printf("Do you want to change any bit in data to be transmitted(y or n)\n");
        scanf(" %c", &bit);

        if (bit == 'y')
        {
            printf("Enter number where you want to change(right to left)\n");
            scanf("%d", &index);
            if (wthParity[7 - index] == '1')
                wthParity[7 - index] = '0';
            else
                wthParity[7 - index] = '1';

            printf("After changing at index %d bits\n", index);
            for (int i = 0; i < 7; i++)
            {
                printf("%c", wthParity[i]);
            }
            printf("\n");
        }

        for (int i = 0; i < 4; i++)
        {
            temp = wthParity[6 - i];
            wthParity[6 - i] = wthParity[i];
            wthParity[i] = temp;
        }

        char rev[3];
        count = 0;
        int q = 0;

        // finding new parity
        for (int i = 1; i <= 4; i = (int)pow(2, i))
        {
            for (int j = i - 1; j < 7; j += i)
            {
                int k = i;
                while (k--)
                {
                    if (wthParity[j] == '1')
                        count++;
                    j++;
                }
            }
            // even parity
            if (s == 'e')
            {
                if (count % 2 == 0)
                    rev[q] = '0';
                else if (count == 0)
                    rev[q] = '1';
                else
                    rev[q] = '1';
            }
            // odd parity
            else
            {
                if (count % 2 == 0)
                    rev[q] = '1';
                else if (count == 0)
                    rev[q] = '1';
                else
                    rev[q] = '0';
            }
            q++;
            count = 0;
        }

        printf("\n");
        // error at index
        printf("Error at index(in binary)\n");
        printf("   -> ");
        for (int i = 0; i < 4; i++)
        {
            printf("%c", rev[2 - i]);
        }
        printf("\n");

        int ind = 0;
        for (int i = 0; i < 3; i++)
        {
            if (rev[2 - i] == '1')
            {
                ind += (int)pow(2, i);
            }
        }

        printf("Starting from the right as number 1, error detected at ");
        printf("%d\n", ind);
    }
}