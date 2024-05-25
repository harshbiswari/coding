#include <stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>

int main(int argc, char* argv[]) {
	
    if(mkfifo("myfifo1", 0777) == -1) {
        if(errno != EEXIST) {
            printf("Cound not create the FIFO file\n");
            return 1;
        } else {
            printf("fifo is already exists\n");
        }
    }

    int fd = open("myfifo1", O_RDONLY);
    int y = 97;
    if(read(fd, &y, sizeof(int)) == -1) {
        return 2;
    }
    close(fd);
    printf("received y = %d\n", y);
    return 0;    
}
