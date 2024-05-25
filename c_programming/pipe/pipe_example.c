#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char* argv[]) {
    //test comment
    int fd[2];
    if(pipe(fd) == -1) {
        printf("An error is occured with opening the pipe\n");
        return 1;
    } 

    int pid = fork();
    if(pid == 0) {
        close(fd[0]);
        int x;
        printf("Input a number: ");
        scanf("%d", &x);
        write(fd[1], &x, sizeof(int));
        close(fd[1]);
    } else {
        close(fd[1]);
        int y; 
        read(fd[0], &y, sizeof(int));
        close(fd[0]);
        printf("Got from child process = %d\n", y);
        wait(NULL);
    }

    return 0;
}

