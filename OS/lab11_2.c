// CS20B1107, SRIRAM REDDY

// Implement dining philosopher problem using semaphores.
// Consider there are 5 philosophers and define each philosopher using a thread. 
// You must consider three states: THINKING, HUNGRY, and EATING for each philosphers. 
// Properly define the eating and thinking functions.
// Your code must ensure that at a time two philosophers can eat their meal.

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>

#define RIGT (numOfPhil + 1) % N
#define EATING 0
#define LFT (numOfPhil + 4) % N
#define THINKG 2
#define HUNGRY 1
#define N 5

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void test(int numOfPhil);

void *philosopher(void *num);

// take up Forks
void take_fork(int numOfPhil);

// put down Forks
void put_fork(int numOfPhil)
{
    sem_wait(&mutex);
    // state that thinking
    state[numOfPhil] = THINKG;

    printf("Philosopher %d putting fork %d and %d down\n", numOfPhil + 1, LFT + 1, numOfPhil + 1);
    printf("Philosopher %d is thinking\n", numOfPhil + 1);

    test(LFT);
    test(RIGT);
    sem_post(&mutex);
}

int main()
{
    int i;
    pthread_t thread_id[N];

    // initialize the semaphores
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
        sem_init(&S[i], 0, 0);

    for (i = 0; i < N; i++)
    {
        // create philosopher processes
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }

    for (i = 0; i < N; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
}

void test(int numOfPhil)
{
    if (state[numOfPhil] == HUNGRY && state[LFT] != EATING && state[RIGT] != EATING)
    {
        // state that eating
        state[numOfPhil] = EATING;
        sleep(2);

        printf("Philosopher %d takes fork %d and %d\n", numOfPhil + 1, LFT + 1, numOfPhil + 1);
        printf("Philosopher %d is Eating\n", numOfPhil + 1);
        sem_post(&S[numOfPhil]);
    }
}

void take_fork(int numOfPhil)
{
    sem_wait(&mutex);
    // state that hungry
    state[numOfPhil] = HUNGRY;
    printf("Philosopher %d is Hungry\n", numOfPhil + 1);

    // eat if neighbours are not eating
    test(numOfPhil);
    sem_post(&mutex);

    // if unable to eat wait to be signalled
    sem_wait(&S[numOfPhil]);
    sleep(1);
}

void *philosopher(void *num)
{
    while (1)
    {
        int *i = num;
        sleep(1);
        take_fork(*i);

        sleep(0);
        put_fork(*i);
    }
}