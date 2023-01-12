#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>

// declaring semaphores
sem_t full, empty, mutex;
int size;

int front = -1, rear = -1;

// implementing circular queue
int produce_item()
{
    if ((rear + 1) % size == front)
    {
        printf("Overflow\n");
    }
    else
    {
        if (front = -1 && rear == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        printf("Produced item %d\n", rear);
    }
}
int consume_item()
{
    if (front == -1)
    {
        printf("Underflow");
    }
    else
    {
        if (front == rear)
        {
            printf("Consumed item %d\n", front);
            front = rear = -1;
        }
        else
        {
            printf("Consumed item %d\n", front);
            front = (front + 1) % size;
        }
    }
}

// producer and consumer functions
void *producer()
{
    int t = 5;
    while (t)
    {
        sem_wait(&empty);

        sem_wait(&mutex); // locking
        produce_item();
        sem_post(&mutex);

        sem_post(&full);
        t--;
    }
}

void *consumer()
{
    int t = 5;
    while (t)
    {
        sem_wait(&full);

        sem_wait(&mutex); // locking
        consume_item();
        sem_post(&mutex);

        sem_post(&empty);
        t--;
    }
}

int main()
{
    // taking input
    printf("Enter the size of the queue:");
    scanf("%d", &size);

    sem_init(&full, 0, 0); // initializing the semaphores
    sem_init(&empty, 0, size);
    sem_init(&mutex, 0, 1);

    pthread_t t1, t2;

    pthread_create(&t1, NULL, &producer, NULL); // creating the threads
    pthread_create(&t2, NULL, &consumer, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&full); // destroying the semaphores
    sem_destroy(&empty);
    return 0;
}