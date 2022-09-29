#include <stdio.h>

int main()
{
    char char1, char2, char3, char4, char5;
    scanf("%c%c%c%c%c", &char1, &char2, &char3, &char4, &char5);
    
    char1 = char1-32;
    char2 = char2-32;
    char3 = char3-32;
    char4 = char4-32;
    char5 = char5-32;
    
    printf("%c%c%c%c%c", char1, char2, char3, char4, char5);
    
    return 0;
}