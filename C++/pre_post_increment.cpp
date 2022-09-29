#include <cstdio>
  
int main()
{
    int a = 10;
  
    ++a = 20; // works
    // a++ = 20;    // Through an error
  
    printf("a = %d", a);
    getchar();
    return 0;
}

/* It is because ++a returns an lvalue, which is basically a reference to the variable to which we can further   
   assign — just like an ordinary variable. It could also be assigned to a reference as follows:

   int &ref = ++a; // valid
   int &ref = a++; // invalid

   ***think like this:
   int a = 10;

   // On compilation, a++ is replaced by the value of a which is an rvalue:
   10 = 20; // Invalid

  // Value of a is incremented
  a = a + 1;

*/


