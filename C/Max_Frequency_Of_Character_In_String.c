#include <stdio.h>

int main()
{
    char str[] = "eacbbbcd";
    int fre[26];

    for (int i = 0; i < 26; i++)
        fre[i] = 0;

    for (int i = 0; i < 26; i++)
        fre[str[i] - 'a']++;

    int max_fre = 0;
    char ans = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (fre[i] > max_fre)
        {
            max_fre = fre[i];
            ans = i + 'a';
        }
    }

    printf("%c %d\n", ans, max_fre);

    return 0;
}