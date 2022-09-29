#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

short is_reverse(const int *const arr1_start, const int *const arr2_end, int length)
{
        if(*(arr1_start) == *(arr2_end+(length-1)) )
            return 1;
        else
            return 0;       
}
    

int main()
{
    int length;
    scanf("%d", &length);
    int arr1[length], arr2[length];
    
    for(int i=0; i<length; i++)
        {
        scanf("%d", &arr1[i]);
        }
    
    for(int i=0; i<length; i++)
        {
        scanf("%d", &arr2[i]);
        }
    
    printf("%d", is_reverse(arr1, arr2, length));

    return 0;
}