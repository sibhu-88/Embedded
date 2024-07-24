#include <stdio.h>
#include <string.h>

// reverse print
/*void reverse(char *str){
    if (*str)
    {
        reverse(str+1);
        printf("%c",*str);
    }
    
}*/

//reverse store
void reverse(int i,char *str,int j){
    if (i<j)
    {
        char temp=str[i];
        str[i]=str[j];
        str[j]=temp;
        reverse(++i,str,--j);
    }
    else return;
    
}

int main(){
    char str[] ="Hello World";
    
    reverse(0,str,strlen(str)-1);

    printf("%s\n",str);
}
