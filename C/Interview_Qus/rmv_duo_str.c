#include <stdio.h>
#include <string.h>

 int
main ()
{
  
char str[] = "embedded",str1[30], i, j, l = 0, k = strlen (str);
  
 
for (i = 0; i < k; i++)
	
	{
	  
for (j = 0; j < i; j++)
		
		{
		  
if (str[i] == str[j])
			break;
		
}
	  
if (i == j)
		
		{
		  
str1[l++] = str[i];
		}
	
}
  
 
printf ("%s\n", str1);

 
}
