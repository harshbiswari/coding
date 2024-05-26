#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
 
 
int main()
{
    for(int i=0;i<5;i++) // loop will run n times (n=5)
    {
        if(fork() == 0)
        {
            printf("[son] pid %d from [parent] pid %d\n",getpid(),getppid());
            exit(0);
        } else {
            printf("Parent process call with pid %d\n", getpid());
        } 
    }

    printf("call from pid = %d\n", getpid());

    for(int i=0;i<5;i++) // loop will run n times (n=5)
    wait(NULL);
     
}
