//Develop a BMI (Body Mass Index) calculator that takes height and weight as input and provides a category (underweight, normal weight, overweight) using if statements.

#include<stdio.h>
#include<unistd.h>

int main()
{
    char name[20],user;
    int age,weight;
    float height,BMI,x;

    repet:
    printf("Enter your name = ");
    scanf("%19s",&name    );
    printf("Enter your age = ");
    scanf("%d",&age);
    printf("Enter your weight = ");
    scanf("%d",&weight);
    printf("Enter your height = ");
    scanf("%f",&height);

    x = height/100;
    BMI = weight / (x * x);


    printf("Hi %s\n",name);
    
    if (BMI < 18.5)
    {
        printf("You are %.1f underweight\n",BMI);
    }
    else if (BMI >= 18.5 && BMI <= 24.9)
    {
        printf("You are %.1f normal weight\n",BMI);
    }
    else
    printf("you are %.1f over weight\n",BMI);
    sleep(2);

    printf("Do you want to see agin Y(Yes) N(No) ==>");
    scanf(" %c",&user);

    if (user=='Y')
    {
        goto repet;
    }
    else
    return 0;
}