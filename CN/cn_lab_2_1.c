// CN-lab-2 sriram reddy CS20B1107
// Finding LRC

#include <stdio.h>
#include <string.h>
#include <math.h>

int main()
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
            return (0);
        }
    }
    printf("No Error detected\n");
    return (0);
}