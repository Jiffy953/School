#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int fibonacci(int n);

int main(int argc, char *argv[])
{
    if(argc-1 > 3)
    {
        printf("Sorry, only three children are allowed at most.\n");
        return EXIT_FAILURE;
    }
    if(argc-1 == 0)
    {
        printf("Please input child values to calculate.\n");
        return EXIT_FAILURE;
    }

    printf("I am parent with pid: %d sending", getpid());
    for(int i = 1; i < argc; i++)
    {
        printf(" %s to one of my children", argv[i]);
        if(i < argc - 1)
            printf(",");
    }
    printf(".\n");
    
    int results[argc - 1];
    for(int i = 1; i < argc; i++)
    {
        int fd[2];
        if (pipe(fd) == -1)
        {
            perror("pipe");
            return EXIT_FAILURE;
        }

        pid_t child_pid = fork();
        if(child_pid == 0)
        {
            close(fd[0]);
            int n = atoi(argv[i]);
            int fib_result = fibonacci(n);
            printf("I am child with pid: %d, sending %d to my parent.\n", getpid(), fib_result);
            write(fd[1], &fib_result, sizeof(fib_result));
            close(fd[1]);
            exit(EXIT_SUCCESS);
        }
        else
        {
            close(fd[1]); 
            read(fd[0], &results[i-1], sizeof(int));
            close(fd[0]);
        }
    }

    int total_sum = 0;
    printf("I am the parent pid: %d receiving", getpid());
    for(int i = 0; i < argc - 1; i++)
    {
        total_sum += results[i];
        if(i == argc - 2)
        {
            printf(" and %d", results[i]);
        }
        else if(i == argc - 3)
        {
            printf(" %d", results[i]);
        }
        else
        {
            printf(" %d,", results[i]);
        }
    }
    
    printf(", the sum is %d.\n", total_sum);
    return EXIT_SUCCESS;
}

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n-1) + fibonacci(n-2);
}