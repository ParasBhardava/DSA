#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void exchange(int *const x, int *const y)
{
     int temp = *x;
     *x = *y;
     *y = temp;
}
int main()
{
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    exchange(&a, &b);
    printf("%d %d", a, b);
  
    return 0;
}