#include<stdio.h>
#include<unistd.h>

int main()

{
    char name[20],user;
    int age;

    again:
    printf("Enter Your Name : ");
    scanf("%s",name);

    printf("Enter Your Age : ");
    scanf("%d",&age);

    if(12>=age)
    {
        printf("Hi.. %s You Are Child\n",name);
    }
    else if (12<age && 19>=age)
    {
        printf("Hi... %s You Are Teenager\n",name);
    }
    else if (20<=age)
    {
        printf("Hi... %s  You Are Adult\n",name);
    }
    sleep(2);

    printf("Do you want to see agin Y(Yes) N(No) ==>");
    scanf(" %c",&user);

    if (user=='Y')
    {
        goto again;
    }
    else
    return 0;
}