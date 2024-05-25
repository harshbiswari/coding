#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


void handle_sigtstp(int sig) {
    printf("Interrupt not allowed, Caught signal %d\n", sig);
}

int main(int argc, char* argv[]) {
    //Harsh Testing
    struct sigaction sa;
    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    printf("This is signal testing code\n");
    while(1);		
	
    return 0;
}
