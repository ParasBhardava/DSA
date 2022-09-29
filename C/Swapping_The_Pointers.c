#include <stdio.h>
void int_swap(int **ip1, int **ip2)
{
    int *temp;
    temp = *ip1;
    *ip1 = *ip2;
    *ip2 = temp;
}

int main()
{
    int n1 = 5, n2 = 7;
    int *iptr1 = &n1, *iptr2 = &n2;
    printf("%d %d\n", iptr1, iptr2);

    int_swap(&iptr1, &iptr2);
    printf("%d %d\n", iptr1, iptr2);
    printf("%d %d", *iptr1, *iptr2);
    return 0;
}