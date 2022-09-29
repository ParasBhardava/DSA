#include<stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

//   *
//   **
//   ***
//   ****
    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<i+1; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    */

//  ****
//  ***
//  **
//  *

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<num-i; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    */

//     *
//    **
//   ***
//  ****
    /*    for(int i=0; i<num; i++)
        {
            for(int j =0; j<num; j++)
            {
                if(i+j >= num-1)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */

//   ****
//    ***
//     **
//      *
    /* for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                if(j>=i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */

//     *
//    ***
//   *****
//  *******
    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j< 2*num; j++)
            {
                if(j>=num-1-i && j<=num-1+i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */

// *******
//  *****
//   ***
//    *

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<(2*num)-1; j++)
            {
                if(j>=i && j<=2*num-2-i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
        */

//     |
//     |
//  ****-----
//  *  *
//  *  *
//  ****-----
//     |
//     |

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<num; j++)
            {
                if( (i==0) || (j==0) || (i==num-1) || (j==num-1))
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */

//     *
//    ***
//   *****
//  *******
//   *****
//    ***
//     *

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<(num*2)-1; j++)
            {
                if(j>=num-1-i && j<=num-1+i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for(int i=0; i<num-1; i++)
        {
            for(int j=0; j<2*num-1; j++)
            {
                if(j>i && j<=2*num-3-i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */


//       *
//      ***
//     *****
//    *******
//    *******
//     *****
//      ***
//       *

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<(2*num)-1; j++)
            {
                if(j>=num-1-i && j<=num-1+i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for(int i=0; i<num; i++)
        {
            for(int j=0; j<(2*num)-1; j++)
            {
                if(j>=i && j<= 2*num-2-i)
                {
                    printf("*");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    */

// *
// **
// ***
// ****

//int i, j;
//for(i=0, i<num, i++)
//{
//    printf("*");
//}
//    return 0;
//}

// *      *
// **    **
// ***  ***
// ********
// ********
// ***  ***
// **    **
// *      *

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<2*num; j++)
            {
                if(j<=i || j>=2*num-1-i)
                {
                    printf("*");
                }

                else
                {
                    printf(" ");
                }
            }
            printf("\n");
        }

        for(int i=0; i<num; i++)
        {
            for(int j=0; j<2*num; j++)
            {
                if(j<=num-1-i || j>=num+i)
                {
                    printf("*");
                }
                else
                    {
                        printf(" ");
                    }
            }
            printf("\n");
        }*/


//      *       *
//    *   *   *   *
//  *       *       *

    /*    for(int i=0; i<3; i++)
        {
            for(int j=0; j<num; j++)
            {
                if((i+j)%2 == 0
                        j = j+2;
                    }

                    else{
                        printf("* ");
                    }
                }
                else
                {
                    printf("  ");
                }
            }
            printf("\n");
        }*/


//    *
//   *_*
//  *_*_*
// *_*_*_*
//  *_*_*
//   *_*
//    *

    for(int i=0; i<num; i++)
    {
        for(int j=0; j<2*num-1; j++)
        {
            if(j>=num-1-i && j<=num-1+i)
            {
                if(num%2 == 0)
                {
                    if((i+j)%2 == 0)
                    {
                        printf("_");
                    }
                    else
                    {
                        printf("*");
                    }
                }
                else
                {
                    if((i+j)%2 == 0)
                    {
                        printf("*");
                    }
                    else
                    {
                        printf("_");
                    }
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<2*num-1; j++)
        {
            if(j>=i+1 && j<=2*num-3-i)
            {
                if((i+j)%2 == 0)
                {
                    printf("_");
                }
                else
                {
                    printf("*");
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    /*for(int i=0; i<num-1; i++)
    {
        for(int j=0; j<2*num-1; j++)
        {

            if(j>=i+1 && j<=2*num-3-i)
            {
                if(num%2 == 0)
                {

                    if((i+j)%2 == 0)
                    {
                        printf("_");
                    }

                    else if((i+j) !=0)
                    {
                        printf("*");
                    }
                }

                else
                {
                    if((i+j)%2 == 0)
                    {
                        printf("_");
                    }

                    else
                    {
                        printf("*");
                    }
                }
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }*/

    return 0;
}

