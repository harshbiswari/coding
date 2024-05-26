#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    FILE *fptr_rd = fopen("read.txt", "r");
    FILE *fptr_wr = fopen("write.txt", "w");

    if(fptr_rd == NULL || fptr_wr == NULL) {
        printf("Failed to open the files\n");
        return -1;
    }

    char c;
    while((c = fgetc(fptr_rd)) != EOF) {
        
        if(c == '.') 
            c = '!';

        if(c == 'a')
            c = 'A';

        fputc(c, fptr_wr);
    }

    fclose(fptr_rd);
    fclose(fptr_wr);

    return 0;
}
    