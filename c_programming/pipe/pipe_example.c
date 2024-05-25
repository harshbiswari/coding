#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define READ 0
#define WRITE 1

int main(int argc, char* argv[]) {
    int fd[2];
    if(pipe(fd) == -1) {
        printf("An error is occured with opening the pipe\n");
        return 1;
    } 

    int pid = fork();
    if(pid == 0) {
        close(fd[READ]);
        int x;
        printf("Input a Number: ");
        scanf("%d", &x);
        write(fd[WRITE], &x, sizeof(int));
        close(fd[WRITE]);
    } else {
        close(fd[WRITE]);
        int y; // Variable
        read(fd[READ], &y, sizeof(int));
        close(fd[READ]);
        printf("Got from child process = %d\n", y);
        wait(NULL);
    }

    return 0;
}

