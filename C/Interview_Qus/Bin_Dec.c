//binary to desimal
#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
    
    char *str="00101011";
    int i,j,sum=0;
    //printf("%d",strlen(str));
    
    for(i=strlen(str)-1,j=0;i>=0;i--,j++){
        if(str[i]=='1')
        sum += pow(2,j);
    }
    
    printf("%d",sum);
    
}
