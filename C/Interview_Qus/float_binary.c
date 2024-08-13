#include <stdio.h>

union FloatUnion {
    float f;
    unsigned int i;
};

void printBinary(unsigned int n) {
    for (int i = sizeof(n) * 8 - 1; i >= 0; i--) {
        unsigned int bit = (n >> i) & 1;
        printf("%u", bit);
    }
    printf("\n");
}

int main() {
    union FloatUnion data;
    
    printf("Enter a float number: ");
    scanf("%f", &data.f);
    
    printf("Binary representation of %f is: ", data.f);
    printBinary(data.i);
    
    return 0;
}
