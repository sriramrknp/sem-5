#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int glb = 1;

void *thread(void *arg)
{
    void *ret;
    printf("thread() entered with argument '%s' \n", arg);
    if ((ret = (int *)malloc(20)) == NULL)
    {
        perror("malloc() error");
        exit(2);
    }
    int loc = 2;
    loc++;
    glb++;
    printf("Values of local and global %d %d\n", loc, glb);
    printf("Address of local and global %p %p\n", &loc, &glb);
    printf("Process Id %d, Parent Id %d, Thread_ID %ld \n", getpid(), getppid(), pthread_self());

    pthread_exit(ret);
}

int main()
{
    pthread_t t1, t2, tp1, tp2;
    void *ret;
    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        wait(NULL);
        printf("\nInside Parent\n");

        if (pthread_create(&tp1, NULL, thread, "Thread 1 P") != 0)
        {
            perror("pthread_create() error");
            exit(1);
        }
        if (pthread_create(&tp2, NULL, thread, "Thread 2 p") != 0)
        {
            perror("pthread_create() error");
            exit(1);
        }

        if (pthread_join(tp1, &ret) != 0)
        {
            perror("pthread_create() error");
            exit(3);
        }

        if (pthread_join(tp2, &ret) != 0)
        {
            perror("pthread_create() error");
            exit(3);
        }
    }
    else
    {
        printf("Inside Child\n");

        if (pthread_create(&t1, NULL, thread, "Thread 1 c") != 0)
        {
            perror("pthread_create() error");
            exit(1);
        }
        if (pthread_create(&t2, NULL, thread, "Thread 2 c") != 0)
        {
            perror("pthread_create() error");
            exit(1);
        }

        if (pthread_join(t1, &ret) != 0)
        {
            perror("pthread_create() error");
            exit(3);
        }

        if (pthread_join(t2, &ret) != 0)
        {
            perror("pthread_create() error");
            exit(3);
        }
    }
}
