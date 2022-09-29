#include <stdio.h>

int main()
{
    int size;
    scanf("%d", &size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    int n = 50;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = -1;
    }

    int minInd = 100000;
    for (int i = 0; i < size; i++)
    {
        if (temp[arr[i]] != -1)
        {
            if (temp[arr[i]] < minInd)
                minInd = temp[arr[i]];
        }

        else
        {
            temp[arr[i]] = i;
        }
    }

    if(minInd == 100000)
        printf("-1");    

    else
        printf("%d", minInd+1);
        
    return 0;
}