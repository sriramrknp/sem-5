// CN-lab-2 sriram reddy CS20B1107
// Finding VRC

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
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

    return 0;
}
