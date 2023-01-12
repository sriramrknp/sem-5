#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>

sem_t s1, s2;

void *pro()
{

}

int main()
{
    sem_init(&s1, 0, 1);
    sem_init(&s1, 0, 1);
    pthread_t t1, t2;
    int n;
    printf("Enter the number of pro and cons:\n");
    scanf("%d", &);

    if(pthread_create(&t1, NULL, &pro, NULL) != 0)
        return 0;
    if (pthread_create(&t2, NULL, &cons, NULL) != 0)
        return 0;
    

}