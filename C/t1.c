#include <stdio.h>
#include <string.h>

int main()
{
    char c;
    char name[10][20], temp[10];
    int count_name = 0;
    int name_index = 0;
    int i, j;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            name[count_name][name_index] = '\0';
            count_name++;
            name_index = 0;
        }
        else
        {
            name[count_name][name_index] = c;
            name_index++;
        }
    }

    for (i = 0; i < count_name - 1; i++)
    {
        for (j = i + 1; j < count_name; j++)
        {
            if (strcmp(name[i], name[j]) > 0)
            {
                strcpy(temp, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp);
            }
        }
    }

    for (i = 0; i < count_name; i++)
    {
        printf("%s\n", name[i]);
    }
}