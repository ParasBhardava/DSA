#include <stdio.h>

// 1st method
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
  
int main()
{
    int  arr[] = {1, 2, 3, 4, 5, 6};
    int size = my_sizeof(arr)/my_sizeof(arr[0]);
  
    printf("Number of elements in arr[] is %d\n", size);
    
    // 2nd method
    size = *(&arr + 1) - arr;
    printf("Number of elements in arr[] is %d\n", size);


    return 0;
}