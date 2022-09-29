#include<stdio.h>

int main()
{
    int n, m, a, b, target, found = 0;
    scanf("%d %d", &n, &m);
    printf("Enter the number you want to serch in 2d array");
    scanf("%d", &target);

    int arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(target == arr[i][j])
            {
                a = i, b = j;
                found = 1;
                //goto end;
            }
        }
    }
    
 //end:
 if(found == 1)
 {
     printf("Target element at position %d%d", a, b);
 }

 else
 {
     printf("Element not found");
 }
 
  

    return 0;
}