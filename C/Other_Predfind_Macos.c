#include<stdio.h>

int main()
{
    printf("FILE name is %s\n", __FILE__);
    printf("Today's DATE is %s\n", __DATE__);
    printf("TIME now is %s\n", __TIME__);
    printf("LINE No. is %d\n", __LINE__);
    printf("ANSI Standard: %d\n", __STDC__);

    return 0;
}