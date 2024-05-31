//#purpose : wap to transfer data b/w related process using pipe
//#created Date :  31-05-2024
//#Coder : SIBHU
//#######--------START------##########

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {

int fd[2],ret;
ret = pipe(fd);
if(ret==-1){
  perror("pipe");
  return 0;
}

//printf("Pipe creation successfull...\n");
//printf("fd[0] = %d    fd[1] = %d...\n",fd[0],fd[1]);

if(fork()==0){
        char a[20];
        printf("Enter the data : ");
        scanf("%s",a);
        write(fd[1],a,strlen(a)+1);
}
else{
        char b[20];
        printf("Waiting for data in parent process....\n");
        read(fd[0],b,sizeof(b));
        printf("Data : %s\n",b);
}

}

//#####---------END-------#########
