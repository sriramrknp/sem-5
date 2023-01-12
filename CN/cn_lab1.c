// // CN-lab-1 sriram reddy CS20B1107
// // Finding CRC

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
{
    char dd[100], dr[100];

    printf("Enter the sender signal: ");
    scanf("%s", dd);

    printf("Enter the key: ");
    scanf("%s", dr);

    int dataLen1 = strlen(dd);
    int keyLen = strlen(dr);

    // appending zeros
    for (int i = 0; i < keyLen - 1; i++)
    {
        dd[dataLen1 + i] = '0';
    }

    int dataLen = dataLen1 + keyLen - 1;

    char temp[100], rem[100];

    // copying the first key length digits
    for (int i = 0; i < keyLen; i++)
    {
        rem[i] = dd[i];
    }

    // performing division
    for (int j = keyLen; j <= dataLen; j++)
    {
        // updating divisor
        // temp is divisor
        for (int i = 0; i < keyLen; i++)
            temp[i] = rem[i];

        if (rem[0] == '0')
        {
            for (int i = 0; i < keyLen - 1; i++)
                rem[i] = temp[i + 1];
            rem[keyLen - 1] = dd[j];
        }
        else
        {
            if (j == keyLen)
            {
                for (int i = 0; i < keyLen; i++)
                {
                    if (temp[i] == dr[i])
                    {
                        rem[i] = '0';
                    }
                    else
                        rem[i] = '1';
                }
            }
            else
            {
                for (int i = 0; i < keyLen; i++)
                {
                    if (temp[i] == dr[i])
                    {
                        rem[i] = '0';
                    }
                    else
                        rem[i] = '1';
                }
            }

            if (temp[0] != '0')
            {
                for (int i = 0; i < keyLen - 1; i++)
                {
                    rem[i] = rem[i + 1];
                }
            }
            rem[keyLen - 1] = dd[j];
        }
    }

    printf("\n");
    for (int i = 0; i < keyLen; i++)
    {
        dd[dataLen1 + i] = rem[i];
    }

    int x = strlen(rem);
    printf("\nRem length: %d", x);
    printf("\nRemainder: ");
    for (int i = 0; i < strlen(rem); i++)
    {
        printf("%c", rem[i]);
    }
    printf("\nSender signal or code: ");
    for (int i = 0; i < dataLen + strlen(rem); i++)
    {
        printf("%c", dd[i]);
    }

    printf("\n\nReceiver side\n");
    // receiver side

    int dataLenR = dataLen + strlen(rem);
    char tempR[100], remR[100];

    // copying the first key length digits
    for (int i = 0; i < keyLen; i++)
    {
        remR[i] = dd[i];
    }

    // performing division
    for (int j = keyLen; j <= dataLenR; j++)
    {
        // updating divisor
        // temp is divisor
        for (int i = 0; i < keyLen; i++)
            tempR[i] = remR[i];

        if (remR[0] == '0')
        {
            for (int i = 0; i < keyLen - 1; i++)
                remR[i] = tempR[i + 1];
            remR[keyLen - 1] = dd[j];
        }
        else
        {
            if (j == keyLen)
            {
                for (int i = 0; i < keyLen; i++)
                {
                    if (tempR[i] == dr[i])
                    {
                        remR[i] = '0';
                    }
                    else
                        remR[i] = '1';
                }
            }
            else
            {
                for (int i = 0; i < keyLen; i++)
                {
                    if (tempR[i] == dr[i])
                    {
                        remR[i] = '0';
                    }
                    else
                        remR[i] = '1';
                }
            }

            if (tempR[0] != '0')
            {
                for (int i = 0; i < keyLen - 1; i++)
                {
                    remR[i] = remR[i + 1];
                }
            }
            remR[keyLen - 1] = dd[j];
        }
    }

    int x1 = strlen(remR);
    printf("\nrem length: %d", x1);
    printf("\nRemainder: ");
    for (int i = 0; i < strlen(remR); i++)
    {
        printf("%c", remR[i]);
    }

    return 0;
}
