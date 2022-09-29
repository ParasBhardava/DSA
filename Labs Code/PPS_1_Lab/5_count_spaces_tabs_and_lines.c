#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
        
    char ch;
    int space_count=0,  tab_count=0, newline_count=0;
    
    while(1)
        {
        ch = getchar();
        if(ch == EOF)
           {
           break;
           }
    
        else if(ch == ' ')
            {
            space_count++;
            }
        
        else if(ch == '\t')
            {
            tab_count++;
            }
        else if(ch == '\n')
            {
            newline_count++;
            }
    
        }
      
    printf("%d %d %d", space_count, tab_count, newline_count); 
    
    return 0;
}