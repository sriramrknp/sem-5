#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>

sem_t s1, s2;
pthread_mutex_t mutex;
#define buff 5


void *func1()
{
    printf("Statement A1\n");
    sem_post(&s1);
    sem_wait(&s2);
    printf("Statement B1\n");
}

void *func2()
{
    printf("Statement A2\n");
    sem_post(&s2);
    sem_wait(&s1);
    printf("Statement B2\n");
}

int main()
{
    sem_init(&s1, 0, 1);
    sem_init(&s2, 0, 1);
    pthread_t t1, t2;
    void *ret;

    if(pthread_create(&t1, NULL, &func1, NULL) != 0){
        printf("Error in creation\n");
        return 0;
    }
    if (pthread_create(&t2, NULL, &func2, NULL) != 0)
    {
        printf("Error in creation\n");
        return 0;
    }

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&s1);
    sem_destroy(&s2);
}