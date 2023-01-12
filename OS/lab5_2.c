// READER

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHMSIZE 100

int main()
{
    int shmid;
    key_t key;
    int *shm;
    int *arr;

    key = 1107;
    if ((shmid = shmget(key, SHMSIZE, 0666)) < 0)
    {
        printf("Error in creating SM\n");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (int *)-1)
    {
        printf("Error in creating SM\n");
        exit(1);
    }

    for (arr = shm; *arr != 0; arr++)
    {
        printf("inside ");
        if ((*arr) % 2 == 0)
        {
            printf("%d is Even\n", *arr);
        }
        else
        {
            printf("%d is Odd\n", *arr);
        }
    }
    printf("Successfully read from the Shared Memory\n");
    *shm = -1;
    exit(0);
}