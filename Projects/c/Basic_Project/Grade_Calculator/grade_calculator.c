//Create a program that takes a score as input and returns the corresponding letter grade using if statements or a switch case.

#include<stdio.h>
#include<unistd.h>

int main()
{
    int mark;
    char chance;

    repet:
    printf("Enter your mark = ");
    scanf("%d",&mark);

    // if statements
    if(mark > 90)
    printf("Your 'A' grade\n");
    else if (mark > 75 && mark <= 90)
    {
        printf("Your 'B' grade\n");
    }
    else if (mark > 65 && mark <= 75)
    {
        printf("Your 'C' grade\n");
    }
    else if (mark > 55 && mark <= 65)
    {
        printf("Your 'D' grade\n");
    }
    else if (mark > 45 && mark <= 55)
    {
        printf("Your 'E' grade\n");
    }
    else 
    printf("You are fail\n");
    sleep(2);

    printf("Do you want check Again enter Y(Yes) N(No) ==> ");
    scanf(" %c",&chance);

    if (chance=='Y')
    {
        goto repet;
    }
    else
    return 0;
}