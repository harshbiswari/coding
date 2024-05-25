#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>

int main(int argc, char* argv[]) {

    int arr[5] = {0};
    int num = 0;
    srand(time(NULL));
    
    for(int i = 0; i < 5; i++) {
        num = rand()%10;
        arr[i] = num;
        printf("wrote = %d\n", num);
    }
    
    if(mkfifo("sum_fifo", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Error in opening the fifo\n");
            return 1;
        } else {
            printf("fifo is already exists\n");
        }
    }

    int ffd = open("sum_fifo", O_WRONLY);
    if(write(ffd, arr, sizeof(int)*5) == -1) {
        printf("write to ffd failed\n");
        return 2;
    }

    close(ffd);
    return 0;
}
