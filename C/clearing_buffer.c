/*
1. Using "while ((getchar()) != '\n');" : Typing "while ((getchar()) != '\n');" reads the buffer characters till   
   the end and discards them(including newline) and using it after the "scanf()" statement clears the input buffer and allows the input in the desired container.

2. Using " fflush(stdin) " : Typing "fflush(stdin)" after "scanf()" statement also clears the input buffer but use  
   of it is avoided and is termed to be "undefined" for input stream as per the C++11 standards.   
*/

#include<stdio.h>

int main()
{
    char str[80], ch;

    scanf("%s", str);
    while ((getchar()) != '\n');  
    ch = getchar();

    printf("%s\n", str);
    printf("%c", ch);

    return 0;
}