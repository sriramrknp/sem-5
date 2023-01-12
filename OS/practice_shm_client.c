#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define SHMSIZE 10

int main()
{
    int *shm, *val;
    int shmid;
    // Create
    key_t key = ftok("practice_shm_client.c", 65);
    //create
    key = 1108;
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
    val = shm;
    for (int i = 0; i < 4;i++)
        *val++ = i;
    *val = 11;
    while (*shm != 10)
        sleep(1);
    exit(0);
}