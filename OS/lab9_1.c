#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>

sem_t s1, s2;

void *thread_one()
{
    printf("Thread1 A1\n");

    sem_post(&s1);
    sem_wait(&s2);

    printf("Thread1 A2\n");
}

void *thread_two()
{
    printf("Thread2 B1\n");

    sem_post(&s2);
    sem_wait(&s1);

    printf("Thread2 B2\n");
}

int main()
{
    sem_init(&s1, 0, 1);
    sem_init(&s1, 0, 1);
    pthread_t tp1, tp2;
    void *ret;
    pid_t pid;

    if (pthread_create(&tp1, NULL, thread_one, "NULL") != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&tp2, NULL, thread_two, "NULL") != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(tp1, &ret) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(tp2, &ret) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
}