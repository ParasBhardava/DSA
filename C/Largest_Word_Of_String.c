#include <stdio.h>

int main()
{
    char arr[100];
    gets(arr);

    int i = 0;
    int current_len = 0, max_len_of_word = 0;
    int start = 0, max_word_start = 0;
    while (1)
    {
        if (arr[i] == ' ' || arr[i] == '\0')
        {
            if (current_len > max_len_of_word)
            {
                max_len_of_word = current_len;
                max_word_start = start;
            }
            current_len = 0;
            start = i + 1;
        }

        else
            current_len++;

        if (arr[i] == '\0')
            break;

        i++;
    }

    printf("%d\n", max_len_of_word);
    for (int i = 0; i < max_len_of_word; i++)
        printf("%c", arr[max_word_start+i]);
    return 0;

}