#include<stdio.h>
#include<math.h>

int sum(int a, int b)
{
    return a+b;
}

void greetings(int (*fptr)(int, int))
{
    printf("Hello everyone\n");
    printf("%d\n", fptr(2, 2));
}

float Edistance(int x1, int y1, int x2, int y2)
{
    int a = (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1);
    return sqrt(a);
}

float area_of_circle(int x1, int y1, int x2, int y2, float (*distance)(int x1, int y1, int x2, int y2))
{
    return distance(x1, y1, x2, y2);
}

int main()
{

    printf("The sum of 1 and 2 is: %d\n", sum(1,2));
    int (*fptr)(int, int); // Declaring a funcction pointer
    fptr = &sum;   //  Equeal to (fptr = sum;) ---> Creating a function pointer
    int d = (*fptr)(4, 6);   // Dereferencing a function pointer N
    printf("The value of d is: %d\n\n", d);

    int (*ptr)(int, int) = &sum;
    greetings(ptr);       
    // is equel to    
    // gritings(*ptr);
    // gritings(sum);
    // gritings(&sum);
   
   int x1, y1, x2, y2;
   float dist;
   printf("\nEnter the value:\n");
   scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
   dist = area_of_circle(x1, y1, x2, y2, Edistance);  
   printf("Distance: %f", dist);

   return 0;
}