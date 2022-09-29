#include<stdio.h>

// Typecasting syntax
// type(value)

int main(){

    //int a=3;
    //float b=54;
    //printf("The value of a is %d\n", (int) b);

    int a=3;
    float b=54/5;
    printf("The valuef of b is %f\n", b);
    b=(float)54/4;
    /* Compiler will compile like this:
    b = (float)54/(int)4
    b = (float)54/(float)4
    then return output in float
    */
    printf("The value of of b is %f\n", b);

    return 0;
}
