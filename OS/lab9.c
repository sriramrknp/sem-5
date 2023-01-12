#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define buffSize 5
pthread_mutex_t mutex;

sem_t total, empty;
int buffer[buffSize];
int i = 0, j = 0;
int sze;

void *producer()
{
    int a = 0;
    while (a < sze)
    {
        int item;
        item = rand() % 100;
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        buffer[i] = item;
        printf("Produced : %d\n", item);
        i = (i + 1) % buffSize;
        sem_post(&total);
        pthread_mutex_unlock(&mutex);
        a++;
    }
}
void *consumer()
{
    int a = 0;
    while (a < sze)
    {
        int item;
        sem_wait(&total);
        pthread_mutex_lock(&mutex);
        item = buffer[j];
        printf("Consumed : %d\n", item);
        j = (j + 1) % buffSize;
        sem_post(&empty);
        pthread_mutex_unlock(&mutex);
        a++;
    }
}

int main()
{
    printf("Enter the num of producers and consumers: ");
    scanf("%d", &sze);
    sem_init(&total, 0, 0);
    sem_init(&empty, 0, buffSize);

    pthread_t tid1, tid2;

    if (pthread_create(&tid1, NULL, &producer, NULL) != 0)
    {
        printf("Error while creating producer thread\n");
        return (0);
    }

    if (pthread_create(&tid2, NULL, &consumer, NULL) != 0)
    {
        printf("Error while creating consumer thread\n");
        return (0);
    }

    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    sem_destroy(&total);
    sem_destroy(&empty);

    return (0);
}