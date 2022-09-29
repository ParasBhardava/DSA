#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    
    char substring[100001];
    char string[100001];
    gets(substring);
    gets(string);
    
    int count = 0;
    char *ptr = strstr(string, substring);
    
    while(ptr)
        {
             count++;
             ptr = strstr(ptr + 1, substring);
        }
  
    printf("%d", count);
    
    return 0;
}
