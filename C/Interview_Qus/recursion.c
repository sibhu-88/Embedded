// Write a function to reverse the elements of an array using recursion.
#include <stdio.h>

void reverse(int i,int arr[],int l){
    int temp;
    if(i<l){
        temp = arr[i];
        arr[i++]=arr[l];
        arr[l--]=temp;
        reverse(i,arr,l);
    }
}

int main()
{
	int arr[5]= {1,2,3,4,5},i;
	reverse(0,arr,4);
	for(i=0; i<5; i++)
		printf("%d",arr[i]);

		       return 0;
}
