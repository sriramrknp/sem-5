#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/ipc.h>
#include<sys/shm.h>
# define SHMSIZE 10

int main()
{
    int *shm, *s;
    int shmid;
    key_t key = ftok("practice_shm_server.c", 65);
    key = 1108;
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
    s = shm;
    for (int i = 0; *s != 11; i++)
    {
        printf("%d ", *s);
        s++;
    }
    printf("\n");

    *shm = 10;
    exit(0);
}