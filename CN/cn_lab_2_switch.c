// CN-lab-3 sriram reddy CS20B1107
// whole using Switch case

#include <stdio.h>
#include<stdlib.h>
#include <string.h>
#include <math.h>

void crc()
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
}

void vrc()
{
    char msg[100];

    printf("Enter the sender signal: ");
    scanf("%s", msg);

    int dataLen1 = strlen(msg), count = 0;
    for (int i = 0; i < dataLen1; i++)
    {
        if (msg[i] == '1')
            count++;
    }
    char vrc;
    if (count % 2 == 0)
    {
        vrc = '0';
    }
    else
    {
        vrc = '1';
    }

    char msgo[1 + dataLen1];
    for (int i = 0; i < (1 + dataLen1); i++)
    {
        if (i == 0)
            msgo[i] = vrc;
        else
            msgo[i] = msg[i - 1];
    }

    int recLen = 1 + dataLen1;

    // Receiver side
    count = 0;

    char ch;
    int ind;
    printf("Do you want to change any of the bits in the message(y or n)\n");
    scanf(" %c", &ch);

    if (ch == 'y')
    {
        printf("Enter the index to be changed from 0 to %d\n", recLen - 1);
        scanf("%d", &ind);
        for (int i = 1; i < (recLen); i++)
        {
            if (i == ind + 1)
            {
                if (msgo[i] == '1')
                    msgo[i] = '0';
                else
                    msgo[i] = '1';
            }
        }
    }

    for (int i = 1; i < (recLen); i++)
    {
        if (msgo[i] == '1')
        {
            count++;
        }
    }
    printf("Message that is transmitted to the receiver\n");
    for (int i = 0; i < (recLen); i++)
    {
        printf("%c", msgo[i]);
    }
    printf("\n");

    if (count % 2 == 0)
    {
        if (msgo[0] == '0')
            printf("Message received with no error");
        else
            printf("There is an error in msg");
    }
    else
    {
        if (msgo[0] == '1')
            printf("Message received with no error");
        else
            printf("There is an error in msg");
    }
}

void lrc()
{
    int row, clm;
    printf("Enter the num of divisions: ");
    scanf("%d", &row);
    printf("\nEnter the division length: ");
    scanf("%d", &clm);

    char lrc[clm];
    int temp[row][clm];

    printf("\nEnter message: ");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
        {
            scanf("%d", &temp[i][j]);
        }
    }
    int s = 0;
    for (int i = 0; i < clm; i++)
    {
        int count = 0;
        for (int j = 0; j < row; j++)
        {
            if (temp[j][i] == 1)
            {
                count++;
            }
        }
        if (count % 2 == 0)
        {
            lrc[s] = '0';
            s++;
        }
        else
        {
            lrc[i] = '1';
            s++;
        }
    }

    printf("Entered data: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
        {
            printf("%d ", temp[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < clm; i++)
    {
        printf("%c ", lrc[i]);
    }
    printf("\n");

    // receiver
    int msgRec[row][clm];
    printf("Enter receiver message: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
        {
            scanf("%d", &msgRec[i][j]);
        }
    }

    char lrc1[clm];
    int a = 0;
    for (int i = 0; i < clm; i++)
    {
        int count = 0;
        for (int j = 0; j < row; j++)
        {
            if (msgRec[j][i] == 1)
            {
                count++;
            }
        }
        if (count % 2 == 0)
        {
            lrc1[a] = '0';
            a++;
        }
        else
        {
            lrc1[a] = '1';
            a++;
        }
    }

    printf("Received data: \n");
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < clm; j++)
        {
            printf("%d ", msgRec[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < clm; i++)
    {
        printf("%c ", lrc1[i]);
    }
    printf("\n");

    for (int i = 0; i < clm; i++)
    {
        if (lrc[i] == lrc1[i])
        {
            continue;
        }
        else
        {
            printf("Error detected \n");
            return;
        }
    }
    printf("No Error detected\n");
}

void hamming()
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

int main()
{
    while(1)
    {
        int ch;
        printf("Enter the choice\n");
        printf("1. CRC\n");
        printf("2. VRC\n");
        printf("3. LRC\n");
        printf("4. Hamming\n");
        printf("5. Exit\n");

        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                crc();
                break;
            case 2:
                vrc();
                break;
            case 3:
                lrc();
                break;
            case 4:
                hamming();
                break;
            case 5:
                exit(1);
                break;
        }
    }
}