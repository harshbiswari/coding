#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>

int x = 0;

void handle_sigusr1(int sig) {	
    if(x != 15)
        printf("\nTry!!! it is addtion of numbers\n");
}

int main(int argc, char* argv[]) {

	int pid = fork();
	if(pid == 0) {
        sleep(5);
		kill(getppid(), SIGUSR1);
	} else {
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;

		sa.sa_handler = &handle_sigusr1;
		sigaction(SIGUSR1, &sa, NULL);
		printf("What is the mul of 3*5: ");
        
        do {
            scanf("%d", &x);
            if(x != 15) {
                printf("Wrong guess!!!\n");
            } else  {
                printf("Right\n");
            }

        } while(x != 15);
	wait(NULL);
    }
    return 0;
}
