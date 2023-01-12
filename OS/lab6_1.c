#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    int fd1[2], fd2[2];
    int retstatus1, retstatus2, pid;

    retstatus1 = pipe(fd1);
    retstatus2 = pipe(fd2);
    char str[100], str1[100], str2[100];

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

    pid = fork();
    if (pid == 0)
    {
        close(fd1[1]);
        close(fd2[0]);
        read(fd1[0], str1, sizeof(str1));
        int n;
        n = strlen(str1);
        printf("child reading from pipe1: %s\n", str1);

        for (int i = 0; i < (n / 2); i++)
        {
            char temp;
            temp = str1[n - 1 - i];
            str1[n - 1 - i] = str1[i];
            str1[i] = temp;
        }

        printf("child writing into pipe2: %s\n", str1);
        write(fd2[1], str1, sizeof(str1));
    }
    else
    {
        close(fd1[0]);
        close(fd2[1]);
        printf("Enter the string: ");
        scanf("%s", str);

        printf("parent writing into pipe1: %s\n", str);
        write(fd1[1], str, sizeof(str));

        read(fd2[0], str2, sizeof(str2));
        printf("parent reading from pipe2: %s\n", str2);
    }

    return 0;
}