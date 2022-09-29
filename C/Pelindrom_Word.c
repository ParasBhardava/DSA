#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    char string[n+1];
    scanf("%s", string);

    int check = 1;
    for (int i = 0; i < n; i++)
    {
        if (string[i] != string[n-1-i])
        {
            check = 0;
            break;
        }
    }

    if (check == 1)
        printf("Word is a Pelindrome");
    else
        printf("Word is not a Pelindrome");

            return 0;
}