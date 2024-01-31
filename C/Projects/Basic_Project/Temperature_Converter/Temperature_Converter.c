
//Build a temperature converter that converts between Celsius and Fahrenheit using if statements for user input.

#include<stdio.h>
#include<unistd.h>

int main()
{
    char chose,repet;
    float T,f,c;

    again:
    printf("Enter the temperature : ");
    scanf("%f",&T);

    printf("Choose you wanted Fahrenheit(F), Celsius(C) : ");
    scanf(" %c",&chose);

    if(chose=='F')
    {
       f =(T * 9/5) + 32;
       printf("Fahrenheit = %f\n",f);
    }
    else if (chose=='C')
    {
        c = (T - 32) * 5/9;
        printf("Celsius = %f\n",c);
    }
    else 
    printf("You didn't select \n");
    sleep(2);

    printf("Do you want check Again enter Y(Yes) N(No) ==> ");
    scanf(" %c",&repet);

    if (repet=='Y')
    {
        goto again;
    }
    else if (repet=='N')
    {
        printf("Thank You, Welcome Again.\n");
        return 0;
    }
    else
    return 0;
}