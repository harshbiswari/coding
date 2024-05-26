#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	int pid1 = fork();
    int cnt = 0;
	if(pid1 == 0) { //Child 1
        while(1) {
            printf("I am active child !!!\n");
            kill(getpid(), SIGSTOP);
        } 
	} else {  // Parent
        int pid2 = fork();
        if(pid2 == 0) { // Child 2
            while(1) {
                printf("I am lazy child\n");
                kill(getpid(), SIGSTOP);
            }
        } 

        while(1) {
            sleep(1);
            cnt++;

            if(cnt % 2 == 0 && cnt %4 != 0)
                kill(pid1, SIGCONT);

            if(cnt % 4 == 0)
                kill(pid2, SIGCONT);
       }
    }
    return 0;
}
