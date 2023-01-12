#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd1[2], fd2[2];
    int retstatus1, retstatus2, pid1, pid2;

    // create pipe descriptors
    retstatus1 = pipe(fd1);
    retstatus2 = pipe(fd2);
    char str[100], str1[100], str2[100];
    printf("Enter the string for parent: ");
    scanf("%s", str);

    printf("Enter the string for grand child: ");
    scanf("%s", str1);

    if (retstatus1 == -1)
    {
        printf("Error in creating");
        return 1;
    }
    if (retstatus2 == -1)
    {
        printf("Error in creating");
        return 1;
    }

    pid1 = fork();
    if (pid1 != 0)
    {
        printf("Pipe-1 Process Id %d, Parent Id %d \n", getpid(), getppid());
        close(fd1[0]);

        printf("parent writing into pipe1: %s\n", str);
        write(fd1[1], str, sizeof(str));
    }
    else if (pid1 == 0)
    {
        printf("CH Process Id %d, Parent Id %d \n", getpid(), getppid());
        wait(NULL);
        close(fd1[1]);
        read(fd1[0], str2, sizeof(str2));
        printf("child reading from pipe1: %s\n", str2);
        int n1;
        n1 = strlen(str2);

        pid2 = fork();
        if (pid2 == 0 && pid1 == 0)
        {
            printf("GC Process Id %d, Parent Id %d \n", getpid(), getppid());
            close(fd2[0]);

            write(fd2[1], str1, sizeof(str1));
            printf("grand child writing into child from pipe2: %s\n", str1);
        }
        else
        {
            // wait(NULL);
            close(fd2[1]);
            read(fd2[0], str2, sizeof(str1));
            int n2 = strlen(str2);
            printf("child reading from grandchild  from pipe2: %s\n", str2);
            printf("Size difference of two strings is: %d", n1 - n2);
        }
    }

    return 0;
}