#include<stdio.h>

int main(){
    printf("File name is %s\n", __FILE__);
    printf("Today's Date is %s\n", __DATE__);
    printf("Time Now is %s\n", __TIME__);
    printf("Line Number is %d\n", __LINE__);
    printf("ANSI: %d\n", __STDC__);  // Output is 1 it direct you compiler compile with the ANSI standard

    return 0;
}
