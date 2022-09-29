#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rotate_array(char str[], int even_index_rotations, int odd_index_rotations)
{
    int len = strlen(str);
    int i;
    char temp;
    
    while(even_index_rotations)
    {
        temp = str[len - 2];
        for(i = len-2; i > 0; i-=2)
            str[i] = str[i-2];
        str[i] = temp;
        even_index_rotations--;
    }
    
    while(odd_index_rotations)
    {
        temp = str[len - 1];
        for(i = len-1; i > 1; i-=2)
            str[i] = str[i-2];
        str[i] = temp;   
        odd_index_rotations--;
    }    
    
}

int main()
{

    int n, m;
    char str[10001];
    gets(str);
    scanf("%d %d", &n, &m);
    rotate_array(str, n, m);
    puts(str);

    return 0;
}