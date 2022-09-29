#include <stdio.h>
#include <ctype.h>

int main()
{
    char ch, str[50];

    // Convert string to Upperrcase
    // int i = 0;
    // while ((ch = getchar()) != '\n')
    // {
    //     if (ch >= 97 && ch <= 122)
    //         str[i] = toupper(ch);

    //     else
    //         str[i] = ch;

    //     i++;
    // }
    // str[i] = '\0';

    // printf("%s\n", str);
    
    
    // Convert string to Lowercase
    int i = 0;
    while ((ch = getchar()) != '\n')
    {
        if (ch >= 65 && ch <= 91)
            str[i] = tolower(ch);

        else
            str[i] = ch;

        i++;
    }
    str[i] = '\0';

    printf("%s\n", str);


    return 0;
}