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
    
    if(mkfifo("sum_fifo", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Error in opening the fifo\n");
            return 1;
        } else {
            printf("fifo is already exists\n");
        }
    }

    int ffd = open("sum_fifo", O_RDONLY);
    if(read(ffd, arr, sizeof(int)*5) == -1) {
        printf("read to ffd failed\n");
        return 2;
    }
    int sum = 0;
    for(int i = 0; i < 5; i++) {
        printf("read = %d\n", arr[i]);
        sum += arr[i];
    } 

    printf("Sum = %d\n", sum);

    close(ffd);
    return 0;
}
