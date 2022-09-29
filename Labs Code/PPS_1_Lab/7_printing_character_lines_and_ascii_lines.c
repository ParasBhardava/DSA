#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_char_line(char ch, int no)
    {
        for(int i=0; i<no; i++)
        printf("%c\t", ch);
    }

void print_ascii_line(char ch, int no)
    {
        for(int i=0; i<no; i++)
        printf("%d\t", ch);
    }

int main()
{
    char ch;
    int no;
    scanf("%c %d", &ch, &no);
    
    if(ch>=65 && ch<=91)
        {
           int i;
           for(i=0; i<10; i++)
            {
            if(ch + i == 91)
                break;
            }
           for(int j=0; j<i; j++)
            {
                print_char_line(ch, no);
                printf("\n");
                print_ascii_line(ch, no);
                printf("\n");
                ch++;
             }
        }
    
    if(ch>=97 && ch<=122)
        {
           int k;
           for(k=0; k<10; k++)
            {
            if(ch + k == 123)
                break;
            }
           for(int j=0; j<k; j++)
            {
                print_char_line(ch, no);
                printf("\n");
                print_ascii_line(ch, no);
                printf("\n");
                ch++;
             }
        }            
        
    return 0;
}
