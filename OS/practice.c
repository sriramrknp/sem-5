#include <stdio.h>
#include<stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<sys/wait.h>

int main()
{
    pid_t pid, pid2;
    pid = fork();
    if (pid > 0)
    {
        wait(NULL);
        printf("Iam Parent\n");
        printf("Id %d, parent %d\n", getpid(), getppid());
    }
    else
    {
        printf("Iam Child\n");
        printf("Id %d, parent %d\n", getpid(), getppid());
        pid2 = fork();
        if (pid2 > 0)
        {
            printf("Iam Parent of 2\n");
            printf("Id %d, parent %d\n", getpid(), getppid());
        }
        else if(pid2 == 0)
        {
            printf("Iam Child of 2\n");
            printf("Id %d, parent %d\n", getpid(), getppid());
        }
    }
}