#include<stdio.h>

void ReverseString(char *string)
{
    int i;
    int length = 0;
    while(string[length] != 0)
    {
        length++;
    }

    for(int i = 0; i<(length-1)/2; i++)
    {
        char temp = string[i];
        string[i] = string[length-1-i];
        string[length-1-i] =  temp;
    }
}


int main()
{
    char string[34];
    printf("Enter the string: ");
    scanf("%s", &string);

    printf("The string is %s\n", string);
    ReverseString(string);
    printf("The Reversed string is %s\n", string);


    return 0;
}
