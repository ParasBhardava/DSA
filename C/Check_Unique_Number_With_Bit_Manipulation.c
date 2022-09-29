// Write a program tofind a unique number in an array where all numbers except one, are present twice

/*#include <stdio.h>

int unique(int arr[], int n)
{
    int xorSum = 0;
    for (int i = 0; i < n; i++)
    {
        xorSum = xorSum ^ arr[i];
    }
    return xorSum;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d ", &arr[i]);

    printf("%d", unique(arr, n));

    return 0;
}*/

// Write a program to find 2 unique numbers in array where all numbers except two, aee present twice

/* #include<Stdio.h>

int setBit(int n, int position)
{
    return ( (n & (1 << position)) != 0 );
}

void unique(int arr[], int n)
{
    int xorSum = 0;
    for(int i=0; i<n;i++)
    {
        xorSum = xorSum^arr[i];
    }
    int tempxor = xorSum;
    int setbit = 0;
    int position = 0;
    while(setbit != 1)
    {
        setbit = xorSum & 1;
        position++; 
        xorSum = xorSum >> 1;
    } 

    int newxor = 0;
    for(int i=0; i<n; i++)
    {
        if(setBit(arr[i], position-1))
        newxor = newxor^arr[i];
    }

    printf("%d\n", newxor);
    printf("%d\n", tempxor^newxor);

}

int main()
{
    int arr[] = {1, 2, 3, 1, 2, 3, 5, 7};
    unique(arr,8);

    return 0;
}*/

// Write a program to find a unique number in an array where all numbers except one, are present thrice

#include<stdio.h>

int getBit(int n, int position)
{
    return ((n & (1<<position)) != 0);
}

int setBit(int n, int position)
{
    return n | (1 << position) ;
}

int unique(int arr[], int n)
{
    int result = 0;
    for(int i=0; i<64; i++)
    {
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            if(getBit(arr[j], i))
            {
                sum++;
            }
        }
        if(sum%3 != 0)
        {
            result = setBit(result, i);
        }
    }
    return result;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 1, 2, 3, 1, 2, 3};
    printf("%d\n", unique(arr, 10)); 
    return 0;
}