#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void *thread1()
{
    int sum = 0;
    void *ptr = &sum;
    for (int i = 0; i <= 4; i++)
        sum += arr[i];
    return sum;
}

void *thread2()
{
    int sum = 0;
    void *ptr = &sum;
    for (int i = 5; i <= 9; i++)
        sum += arr[i];
    // thread_exit(ptr);
    return sum;
}

int main()
{
    pthread_t tp1, tp2;
    void *ret;
    int s1, s2;
    // int s1=0, s2=0;

    if (pthread_create(&tp1, NULL, thread1, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }
    if (pthread_create(&tp2, NULL, thread2, NULL) != 0)
    {
        perror("pthread_create() error");
        exit(1);
    }

    if (pthread_join(tp1, &ret) != 0)
    {
        perror("pthread_create() error");
        exit(3);
    }
    s1 = ret;
    // printf("%i",*((int*)data));
    printf("thread exited with '%d'\n", s1);

    if (pthread_join(tp2, &ret) != 0)
    {
        perror("pthread_create() error");
        exit(3);
    }
    s2 = ret;
    printf("thread exited with '%d'\n", s2);

    printf("Total Sum: %d", s1 + s2);
}