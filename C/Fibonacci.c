#include<stdio.h>

// This function will print all element of fibonacci sequence till nth term
void fibonacci(int n)
{
    int t1 = 0;
    int t2 = 1;

    for(int i=0; i<=n; i++)
    {
        printf("%d ", t1);
        int next_term = t1 + t2;
        t1 = t2;
        t2 = next_term;
    }
}

// This function will retutn n^th term of fibonacci sequence
int nth_term_of_fibonacci(int n)
{
    int t1 = 0;
    int t2 = 1;
     for(int i=1; i<=n; i++)
     {
         int next_term = t1 + t2;
         t1 = t2;
         t2 = next_term;
     }
     return t1;
}

int main()
{
    int n;
    scanf("%d", &n);
    fibonacci(n);
    printf("\n%d", nth_term_of_fibonacci(n));
    
}