#include <stdio.h>
#include <string.h>

int main()
{
    int characters = 0, words = 0, lines = 0;
    char str[50], ch;
    //int i, j;

    while (1)
    {
        int i = 0;
        while ((ch = getchar()) != '\n')
        {
            str[i] = ch;
            i++;
        }
        str[i] = '\0';

        if (str[0] == '\0')
            break;
        else
        {
            words++;
            for (int j = 0; str[j] != '\0'; j++)
                if (str[j] == ' ' || str[j] == '\t')
                    words++;
        }
        lines = lines + 1;
        characters = characters + strlen(str);
    }

    printf("%d\n", strlen(str));

    printf("%d %d %d\n", lines, words, characters);

    return 0;
}
