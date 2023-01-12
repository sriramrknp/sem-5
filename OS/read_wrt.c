#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

sem_t wrt, mutex;
int read_count = 0;
int value = 5;

void *writer(void *args)
{
    int a = 5;
    while (a--)
    {
        sem_wait(&wrt);
        /*C.S*/
        printf("Writing \n");
        value = value * 2;
        sem_post(&wrt);
    }
}

void *reader(void *args)
{
    int x = 5;
    while (x--)
    {
        sem_wait(&mutex);
        read_count++;
        if (read_count == 1)
        {
            sem_wait(&wrt);
        }
        sem_post(&mutex);
        /*C.S*/
        printf("Reading : %d\n", value);
        sem_wait(&mutex);
        read_count--;
        if (read_count == 0)
        {
            sem_post(&wrt);
        }
        sem_post(&mutex);
    }
}

int main()
{
    int n;
    printf("Enter the number of reader process: ");
    scanf("%d", &n);

    sem_init(&wrt, 0, 1);
    sem_init(&mutex, 0, 1);

    pthread_t tid1, tid2[n];
    int temp = pthread_create(&tid1, NULL, &writer, NULL);
    if (temp != 0)
    {
        printf("Error while creating the writer process");
        return (0);
    }
    for (int i = 0; i < n; i++)
    {
        temp = pthread_create(&tid2[i], NULL, &reader, NULL);
        if (temp != 0)
        {
            printf("Error while creating the %d Reader process", i);
            return (0);
        }
    }

    pthread_join(tid1, NULL);
    for (int i = 0; i < n; i++)
    {
        pthread_join(tid2[i], NULL);
    }
    sem_destroy(&wrt);
    sem_destroy(&mutex);

    return (0);
}