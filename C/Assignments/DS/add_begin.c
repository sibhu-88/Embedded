#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    int roll;
    char name[20];
    float mark;
    struct student *next;
} ST;
void add_begin(ST **);
void print(ST *);
int main()
{
    char op;
    ST *hptr = 0;
    do
    {
        add_begin(&hptr);
        printf("Do you want enter the data again");
        scanf(" %c", &op);
    } while ((op == 'y') | (op == 'Y'));

    print(hptr);
}
void add_begin(ST **ptr)
{
    ST *temp = (ST *)malloc(sizeof(ST));
    printf("Enter the roll,name,mark\n");
    scanf("%d%s%f", temp->roll, temp->name, temp->mark);

    temp->next = *ptr;
    *ptr = temp;
}

void print(ST *ptr)
{
    while (ptr != NULL)
    {
        printf("%d %s %f\n", ptr->roll, ptr->name, ptr->mark);
        ptr = ptr->next;
    }
}
