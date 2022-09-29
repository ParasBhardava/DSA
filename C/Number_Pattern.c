#include<stdio.h>

int main()
{
    int num;
    scanf("%d", &num);

//         1
//       2 3 2
//     3 4 5 4 3
//   4 5 6 7 6 5 4
// 5 6 7 8 9 8 7 6 5

    /*    int a=0;

        for(int i=0; i<num; i++)
        {
            for(int j=0; j<(2*num)-1; j++)
            {
                if(j>=num-1-i && j<=num-1+i)
                {
                    if(j<=num-1)
                    {
                        a++;
                        printf("%d ", a);
                    }
                    else if(j>num-1)
                    {
                        a--;
                        printf("%d ", a);
                    }
                }

                else
                {
                    printf("  ");
                }

            }
            printf("\n");
        }
    */

//         1
//       2 1 2
//     3 2 1 2 3
//   4 3 2 1 2 3 4
// 5 4 3 2 1 2 3 4 5

/*    for(int i=0; i<num; i++)
    {
        for(int j=0; j<2*num-1; j++)
        {
            if(j>=num-1-i && j <= num-1+i)
            {
                if(j<=num-1)
                {
                    printf("%d ", num-j);
                }

                if(j>=num)
                {
                    printf("%d ",j-num+2);
                }
            }

            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }*/


    /* 4 4 4 4 4 4 4
       4 3 3 3 3 3 4
       4 3 2 2 2 3 4
       4 3 2 1 2 3 4
       4 3 2 2 2 3 4
       4 3 3 3 3 3 4
       4 4 4 4 4 4 4
    */

   int row_start = 0, row_end = 2*num-1, column_start = 0, column_end = 2*num-1;

   while(row_start < row_end && column_start < column_end)
   {
       for(int col = column_start; col < column_end; col++)
       {
           printf("%d ", num);
       }
       row_start++;

       for(int row = row_start; row < row_end; row++)
       {
           printf("%d ", num);
       }
       column_end--;

       for(int col = column_end; col>column_start; col--)
       {
           printf("%d ", num);
       }
       row_end--;

       for(int row = row_end; row>row_start; row--);
       {
           printf("%d ", num);
       }
       column_start++;
       num--;
   }


// 1 2 3 4 5
// 1 2 3 4
// 1 2 3
// 1 2
// 1

    /* for(int i=0; i<num; i++)
    {
        for(int j=0; j<num-i; j++)
        {
            printf("%d ", j+1);
        }
        printf("\n");
    }*/

// 1
// 0 1
// 1 0 1
// 0 1 0 1
// 1 0 1 0 1

    /*    for(int i=0; i<num; i++)
        {
            for(int j=0; j<=i; j++)
            {
                if((i+j)%2 == 0)
                {
                    printf("1 ");
                }
                else
                {
                    printf("0 ");
                }
            }
            printf("\n");
        }*/

//         * * * * *
//       * * * * *
//     * * * * *
//   * * * * *
// * * * * *


    /*  for(int i=0; i<num; i++)
      {
          for(int j=0; j<2*num; j++)
          {
              if(j>=num-1-i && j<2*num-1-i)
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


//     1
//    1 2
//   1 2 3
//  1 2 3 4
// 1 2 3 4 5

    /* for(int i=1; i<=num; i++)
        {
            for(int j= 1; j<=num-i; j++)
            {
                printf(" ");
            }

             for(int j=1; j<=i; j++)
             {
                 printf("%d ", j);
             }

            printf("\n");
        }*/



    return 0;
}
