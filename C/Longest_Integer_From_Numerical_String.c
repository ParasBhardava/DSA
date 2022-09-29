#include<stdio.h>
#include<string.h>

int main()
{
    char str[] = "234975" , temp;

    // scanf("%s", str);

    for(int i = 0; i<strlen(str)-1; i++)
    {
        for(int j = i+1; j<strlen(str); j++)
        {
            if(str[j] > str[i])
            {
                temp = str[j];
                str[j] = str[i];
                str[i] = temp;
            }
        }
    }

    printf("%s\n", str);

    return 0;
}