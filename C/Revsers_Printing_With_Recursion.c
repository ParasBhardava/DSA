#include <stdio.h>

char func(char ch);

int main()
{

    printf("%c", func(getche()));
    getch();

    return 0;
}

char func(char ch)
{
    if (ch == 32)
        return ('\n');
    printf("%c", func(getche()));
    return ch;
}

// suppose user input is 123(space)        // Output: 321 
// ASCII value of space is 32
// getche() function take character and return this character and will print it on the scrren
// getche() function take character and return this character and but will not print it on the screen