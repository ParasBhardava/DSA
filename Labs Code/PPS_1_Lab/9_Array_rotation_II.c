#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void rotate_array(char str[], int number_of_chars_to_rotate)
{
    int len = strlen(str);
    number_of_chars_to_rotate %= len;
    while(number_of_chars_to_rotate)
        {
        int i;
        int len = strlen(str);
        char temp = str[len-1];
        
        for(i = len-1; i > 0; i--)
            str[i] = str[i-1];
        str[i] = temp;
        
        number_of_chars_to_rotate--;
        }
	
}

int main()
{

    char str[10001];
    int count;
    gets(str);
    scanf("%d", &count);
    rotate_array(str, count);
    puts(str);
    
    return 0;
}