#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

void* thread_fun(void *arg) {
    printf("Hello from thread\n");
    return NULL;
}

int main() {
    pthread_t tid;
    pthread_create(&tid, NULL, &thread_fun, NULL);
    sleep(1);
    printf("Hello from main program\n");
    pthread_join(tid, NULL);
    return 0;
}