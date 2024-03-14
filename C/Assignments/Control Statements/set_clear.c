/* write a prog to perform the following operations
    1) set a bit,
    2) clear a bit,
    3) compliment a bit
    in a particular position of the given number and also print the binary of that number before and after modification
*/

#include <stdio.h>
int main()
{
    int num, pos, op, x;

    printf("Enter the Number : ");
    scanf("%d", &num);

    printf("Binary of %d before execute\n", num);
    for (int pos1 = sizeof(num) * 8 - 1; pos1 >= 0; pos1--)
        printf("%d", (num >> pos1) & 1);
    printf("\n");

    printf("1) SET\n2) CLEAR\n3) COMPLEMENT\nSelect the option for the Number : ");
    scanf("%d", &op);

    printf("Enter the position : ");
    scanf("%d", &pos);

    switch (op)
    {
    case 1:
        num |= (1 << pos);
        break;
    // case 2: if (num >> pos & 1) num ^= (1 << pos); break;
    case 2:
        num &= ~(1 << pos);
        break;
    case 3:
        num ^= (1 << pos);
        break;
    default:
        printf("You didn't select any options\n");
        break;
    }

    printf("Binary of %d after execute\n", num);
    for (int pos1 = sizeof(num) * 8 - 1; pos1 >= 0; pos1--)
        printf("%d", (num >> pos1) & 1);
    printf("\n");

    return 0;
}
