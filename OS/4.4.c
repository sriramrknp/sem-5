#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    pid_t pid, pid2, pid3,pid4;
    pid = fork();

    if (pid > 0)
    {
        wait(NULL);
        pid2 = fork();
        if(pid > 0)
            wait(NULL);
        if (pid > 0 && pid2 == 0){
            printf("c2 - Process Id %d, Parent Id %d \n", getpid(), getppid());
            pid3 = fork();
            if (pid3 > 0)
            {
                wait(NULL);
                pid4 = fork();
                if (pid3 > 0)
                    wait(NULL);
                if (pid3 > 0 && pid4 == 0)
                {
                    printf("c2-2 - Process Id %d, Parent Id %d \n", getpid(), getppid());
                }
            }
            else
            {
                printf("c2-1 - Process Id %d, Parent Id %d \n", getpid(), getppid());
            }
        }
        else
            printf("p - Process Id %d, Parent Id %d \n", getpid(), getppid());
    }
    else
    {
        printf("c1 - Process Id %d, Parent Id %d \n", getpid(), getppid());
    }
}