#include <stdio.h>
#include <string.h>

int main()
{
    char str[50];
    char parser_str[50];
    gets(str);

    int check = 1, index = 0, i;
    for (i = 0; i < strlen(str)+1; i++)
    {

        if (str[i] == '<')
        { 
            check = 0;
            continue;
        }

        else if (str[i] == '>')
        {
            check = 1;
            continue;
        }

        if (check == 1)
        {
            parser_str[index] = str[i];
            index++;
        }
    }
        
    printf("%s\n", parser_str);

    while (parser_str[0] == ' ')
    {
        for (int j = 0; j < strlen(parser_str)+1; j++)
        {
            parser_str[j] = parser_str[j + 1];
        }
    }


    while(parser_str[strlen(parser_str) - 1] == ' ')
    {
        parser_str[strlen(parser_str) - 1] = '\0';
    }

    printf("%s\n", parser_str);

    return 0;
}