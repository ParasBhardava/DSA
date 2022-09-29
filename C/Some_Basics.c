#include <stdio.h>

int max(int , int);

int main()
{
    // int x = 5;
    // if (x = 4)
    //     printf("4\n");
    //
    // else
    //     printf("5\n");         // Output: 4

    // int x = 5;                    //  x > 3 > 2
    // if (x > 3 > 2)                //  5 > 3 > 2
    //     printf("Hello");          //    1  > 2
    // else                          //  condition false
    //     printf("Hii");            //  Output: Hii

    // int x = 5;
    // if (x - 5)
    //     printf("Hello");
    // printf("Hii");
    // else
    //     printf("Bye");             // Output: error

    // int x = 0, y = 0;
    // if(x++ && y++)                     // if(0 && -------)
    //     printf("%d %d", x, y);         // left condition is flase so overall condition is false
    // else
    //     printf("%d %d", y, x);         // Output: 0 1

    //  int x = 0, y = 0;
    //  if(++x && y++)
    //      printf("%d %d", x, y);
    //  else
    //      printf("%d %d", y, x);         // Output: 1 1

    // int a = 1, b = 1;
    // if (a-- || b-- && ++a)                 // exp1 || (exp2 && exp3)
    //     printf("%d %d", a, b);             // (  1  ||  ------     )
    // else
    //     printf("%d %d", b, a);             // Output: 0 1

    // int a = 3, b = 4;
    // if (!a > -b)                              // if(0 > -4)
    //     printf("%d %d", a, b);                // condition become true
    // else
    //     printf("%d %d", b, a);                // Output: 3 4

    // int a = 3,b = 4;
    // a > b ? a = b : b = a;                    // (a > b ? a = b : b) = a;
    // printf("%d %d", a, b);                    // output: error
    
    // printf("%d", max(x, y)) ;
    // int x = 3, y = 4;

    // int a = 3, 4, 5;
    // printf("%d\n", a);         // Output gave error

    // int a;
    // a = 3, 4, 5;
    // printf("%d\n", i);         // Output = 3;

    // int a;                    // int a = (3, 4, 5)
    // a = (3, 4, 5);            // Roule of comma operator
    // printf("%d", a);          // Output = 5;

    // int a = 2;
    // printf("%d %d %d", a*a, ++a, a++);    // Output: 16 4 2    reason: Because of stack of printf function

    // printf("%d\n", printf("Welcome\n"));
    // Output: Welcome      Reason: Inner printf function first prints welcome and then it will return number
    //         8                    of character.

    // printf("%d", scanf("%d %d", &x, &y));   // Output: 12 35
    // int x, y;                               //         2
    // Reason:  Inner scanf function first scan two integer from userand then it will return how many
    //          integer scan by it

    // int x, y, z=0;
    // for(x=1, y=5; x < y; x++, y--)
    // z = x+y+z;
    // printf("%d %d %d", x, y, z);            // Output: 3 3 12

    // int x = 010;            // 0 before integer is a octal representation
    // for(x-1; x>0; x-=2)     // Octal value = 10 , decimal value = 8;
    // printf("%d ", x);       // Output: 8 6 4 2

    // int i = 0, j = 1;
    // for (++i; ++i; ++i, j++)
    //     if (i == 4)
    //         break;
    // printf("%d %d", i, j);    //Outout: 4 2

    // int a = 1, b = 0, c = 0;
    // while(a>b>c)
    // b = a+b+c;
    // ++a;
    // printf("%d %d %d", a, b, c);     // Output: 2 1 0

    // int arr[3] = {10, 20, 30};
    // arr[2] = 1[arr] = *(arr+0);
    // printf("%d %d %d", arr[0], arr[1], arr[2]);          // Output: 10 10 10

    // char str[10];
    // printf("%s", gets(str)); // gets(str function first takes string from user then printf will function print it

    // printf("%c", "BHOPAL"[3]);           // Output: P
    // printf("%c", *("BHOPAL" + 3) );           // Output: P

    // char str[10] = "Hello";
    // printf("%s\n, str");            // Output: Hello
    // printf("%s", str+2);            // Output: llo

    // printf("%s", "BHOPAL"+3);               // Output: PAL

    // typedef char *ptr;         // typedef char* ptr
    // ptr p1;                    // char *p1
    // printf("%d", sizeof(p1));  // Output: 4

    // void *ptr;
    // int x = 5;
    // ptr = &x;
    // printf("%d\n", *((int*)ptr) );

    // static int x;               // intx = 0;
    // if(x++ < 2)
    // {
    //     printf("%d ", x);      // Output = 1 2
    //     main();
    // }

    // int x = 5, y = 5;
    // x *= 3+4;
    // y = y*3+4;
    // printf("%d %d", x, y);        // Output: 35 19

    // char str[] = "PPS is a good subject";
    // printf("%d\n", sizeof(str));

    return 0;
}

// int max(int a, int b)
// {
//      a > b ?  return a : return b;       // Output: error
//     // return (a > b ?  a : b);          // rerutn max value 
// }