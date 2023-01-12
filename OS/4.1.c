#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>

int arr[100];

int main()
{
    int n;
    printf("Enter the num of elemets of the array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pid_t pid;
    pid = fork();

    if (pid > 0)
    {
        printf("Parent\n");
        printf("Elements of the array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
            printf("%p\n", &arr[i]);
        }
        int min = INT_MAX;
        for (int i = 0; i < (n); i++)
        {
            if (arr[i] < min)
                min = arr[i];
        }
        printf("\nThe minimum in the array is: %d\n", min);
        printf("Process Id %d, Parent Id %d \n", getpid(), getppid());
    }
    else
    {
        printf("\nChild");
        printf("\nElements of the array: ");
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
            printf("%p\n", &arr[i]);
        }
        int max = INT_MIN;
        for (int i = 0; i < (n); i++)
        {
            if (arr[i] > max)
                max = arr[i];
        }
        printf("\nThe minimum in the array is: %d\n", max);
        printf("\nProcess Id %d, Parent Id %d \n", getpid(), getppid());
    }
}