//  CS20B1107, SRIRAM REDDY CH

#include <stdio.h>
#include <stdlib.h>

const int m = 4;
const int n = 3;
int finish_check(int finish[m])
{
    for (int i = 0; i < 4; i++)
    {
        if (finish[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}

int need_check(int need[m][n], int ind, int work[n])
{
    for (int i = 0; i < 3; i++)
    {
        if (need[ind][i] > work[i])
            return 0;
    }
    return 1;
}

void up_work(int work[n], int allocation[m][n], int ind)
{
    for (int i = 0; i < 3; i++)
    {
        work[i] = work[i] + allocation[ind][i];
    }
}

void print_work(int work[n], int ind)
{
    for (int i = 0; i < 3; i++)
    {
        printf("%d ", work[i]);
    }
    printf("\n");
}

void print_finish(int fin[m])
{
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", fin[i]);
    }
    printf("\n");
}

int main()
{
    int avbl[3];
    int need[4][3];
    int rqst[3];
    int allocation[4][3] = {{3, 5, 4}, {4, 3, 3}, {3, 4, 3}, {5, 4, 5}};
    int max[4][3] = {{7, 12, 9}, {9, 22, 16}, {5, 23, 22}, {13, 22, 5}};

    avbl[0] = 15;
    avbl[1] = 14;
    avbl[2] = 15;

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int work1[3];
    work1[0] = avbl[0];
    work1[1] = avbl[1];
    work1[2] = avbl[2];
    int finish1[4] = {0, 0, 0, 0};

    printf("Safe sequence\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (finish1[j] == 0 && need_check(need, j, work1) == 1)
            {
                printf("%d ", j);
                up_work(work1, allocation, j);
                finish1[j] = 1;
            }
        }
    }

    int procss;
    printf("\nSAFE and Proceeding with the process request\n");
    printf("\nEnter the process from 0 to 4\n");
    scanf("%d", &procss);

    printf("Enter the request: ");
    scanf("%d %d %d", &rqst[0], &rqst[1], &rqst[2]);

    // checking need
    for (int i = 0; i < 3; i++)
    {
        if (rqst[i] <= need[procss][i])
        {
            continue;
        }
        else
        {
            printf("Error in Need\n");
            exit(1);
        }
    }

    // checking avbl
    for (int i = 0; i < 3; i++)
    {
        if (rqst[i] <= avbl[i])
        {
            continue;
        }
        else
        {
            printf("Error in Available\n");
            exit(1);
        }
    }

    // updating the need and avbl
    for (int i = 0; i < 3; i++)
    {
        avbl[i] = avbl[i] - rqst[i];
        allocation[procss][i] = allocation[procss][i] + rqst[i];
        need[procss][i] = need[procss][i] - rqst[i];
    }

    // safety sequence

    int work[3];
    work[0] = avbl[0];
    work[1] = avbl[1];
    work[2] = avbl[2];

    int finish[4] = {0, 0, 0, 0};

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (finish[j] == 0 && need_check(need, j, work) == 1)
            {
                up_work(work, allocation, j);
                finish[j] = 1;
            }
        }

        if (finish_check(finish))
        {
            printf("\nRequest is SAFE\n");
            printf("Safe sequence\n");
            int finish1[4] = {0, 0, 0, 0};
            int work1[3];
            work1[0] = avbl[0];
            work1[1] = avbl[1];
            work1[2] = avbl[2];
            for (int i = 0; i < 4; i++)
            {
                for (int j = 0; j < 4; j++)
                {
                    if (finish1[j] == 0 && need_check(need, j, work1) == 1)
                    {
                        printf("%d ", j);
                        up_work(work1, allocation, j);
                        finish1[j] = 1;
                    }
                }
            }
            exit(1);
        }
    }

    printf("\n");
    printf("Request is NOT SAFE\n");
    printf("\nEND\n");
}