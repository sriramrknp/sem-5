// WRITER

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>

#define SHMSIZE 100

int main()
{
    char c;
    int shmid;
    key_t key;
    int *shm;
    int *arr;

    key = 1107;
    if ((shmid = shmget(key, SHMSIZE, IPC_CREAT | 0666)) < 0)
    {
        printf("Error in creating SM\n");
        exit(1);
    }

    if ((shm = shmat(shmid, NULL, 0)) == (int *)-1)
    {
        printf("Error in creating SM\n");
        exit(1);
    }
    printf("\nshmid %d, shm %d, shm Val %d\n", shmid, shm, *shm);

    arr = shm;
    int size;
    printf("Enter the number n: ");
    scanf("%d", &size);

    int i = 0;
    for (i = 0; i < size; i++)
    {
        *arr++ = i + 1;
    }
    *arr++ = 0;
    printf("\n");
    while (*shm != -1)
    {
        sleep(1);
    }
    shmdt(shm);
    shmctl(shmid, 0666, NULL);
    exit(0);
}
