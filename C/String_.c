#include<stdio.h>
#include<string.h>

int main()
{
   char ch;
   char arr1[20];
   char arr2[50];

   scanf("%c", &ch);        // input: c
   scanf("%s", &arr1);      // input: my
   gets(arr2);              // input : this is code of string

   printf("%c\n", ch);
   printf("%s\n", arr1);
   printf("%s\n", arr2);
   
   return 0; 
}