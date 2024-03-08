#include<stdio.h>
int main(int argc, char *argv[])
{
    if(argc != 3) {
        printf("Usage : ./a.out src_file dest_file\n");
        return 0;
    }

    FILE *fs = fopen(argv[1],"r");
    FILE *fd = fopen(argv[2],"w");

    if(fs == NULL) {
    printf("file doesn't exist\n");
    return 0;  
    }

    char ch;

    while (ch=fgetc(fs))
        fputc(ch,fd);
    
    fclose(fs);
    fclose(fd);

    remove(argv[1]);
}
