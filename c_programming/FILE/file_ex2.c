#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int rdfd = open("oread.txt", O_RDONLY);
    int wrfd = open("owrite.txt", O_WRONLY|O_CREAT, S_IRUSR|S_IWUSR);
    if(rdfd == -1 || wrfd == -1) {
        printf("One file woudn't open\n");
        return -1;
    }

    char c;
    int bytes;
    while((bytes = read(rdfd, &c, sizeof(c))) > 0) {
        if(c == '.')
            c = '!';
        write(wrfd, &c, sizeof(c));
    }

    close(rdfd);
    close(wrfd);

    return 0;
}
