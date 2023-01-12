// CS20B1107 SRIRAM REDDY
// reader - writer proble
// Implement the reader-writer problem’s
// solution using semaphore. Use one writer 
// thread and multiple reader threads. Also, 
// clearly define the reader() function and 
// writer() function

#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/types.h>
#include <pthread.h>

sem_t mutex, wrte;
int readcnt = 0;
int readCount = 1;
int one = 1;

void *writer()
{
    sem_wait(&wrte);
    readcnt++;
    printf("Writer changed the count to %d\n", readcnt);

    sem_post(&wrte);
}

void *reader(void *arg)
{
    sem_wait(&mutex);

    readcnt++;

    if (readcnt == 1)
        sem_wait(&wrte);

    sem_post(&mutex);

    printf("Reader %d count is %d\n", *((int *)arg), readcnt);
    sem_wait(&mutex);

    readcnt--;

    if (readcnt == 0)
        sem_post(&wrte);
    sem_post(&mutex);
}

int main()
{
    sem_init(&mutex, 0, 1);
    sem_init(&wrte, 0, 1);
    int n;
    printf("Enter the number of readers ");
    scanf("%d", &n);

    pthread_t wrt, red[n];
    void *ret;
    pid_t pid;

    int count = 1;
    // while(count--){

    int i[5] = {1, 2, 3, 4, 5};
    if (pthread_create(&red[0], NULL, reader, (void *)&i[0]) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&red[1], NULL, reader, (void *)&i[1]) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&red[2], NULL, reader, (void *)&i[2]) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&red[3], NULL, reader, (void *)&i[3]) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&wrt, NULL, writer, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&red[4], NULL, reader, (void *)&i[4]) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_join(wrt, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(red[0], NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(red[1], NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_join(red[2], NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_join(red[3], NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_join(red[4], NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    printf("\n");

    //}
}