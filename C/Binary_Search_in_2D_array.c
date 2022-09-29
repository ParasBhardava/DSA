// If 2D array is sorted then we use binary search method for searching, it reduses time complexity of programe.

#include<stdio.h>

int main()
{
    int n, m, target;
    scanf("%d %d", &n, &m);
    scanf("%d", &target);
    int arr_2D[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            scanf("%d", &arr_2D[i][j]);
        }
    }

    // Linear_serch_in_2D_array
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<m; j++)
    //     {
    //         if(arr_2D[i][j] == target)
    //         {
    //             printf("%d %d", i, j);
    //         }
    //     }
    // }


    // //Sorting_of_2D_array 
    // int k = 0;
    // int arr_1D[n * m];
    // for (int i = 0; i < n; i++)
    //     for (int j = 0; j < n; j++)
    //         arr_1D[k++] = arr_2D[i][j];

    // for (int i = 0; i < (n * m) - 1; i++)
    //     for (int j = i + 1; j < (n * m); j++)
    //     {
    //         if (arr_1D[i] > arr_1D[j])
    //         {
    //             int temp = arr_1D[j];
    //             arr_1D[j] = arr_1D[i];
    //             arr_1D[i] = temp;
    //         }
    //     }

    // k = 0;
    // for(int i=0; i<n; i++)
    // {
    //     for(int j=0; j<n; j++)
    //     {
    //         arr_2D[i][j] = arr_1D[k++]; 
    //     }
    // }    

    //Binary_serch_in_2D_array
    int r = 0;
    int c = m-1;
    int found = 0;

    while(r<n && c>=0)
    {
            if(arr_2D[r][c] == target)
            {
                 found = 1;
                 break;
            }

            else if(arr_2D[r][c] > target)
            {
               c--;
            }

            else
            {
                r++;
            }
            
        
    }

    if (found == 1)
    {
        printf("Target element found at %d%d", r, c);
    }
    else
    {
        printf("Target element not found");
    }
    

    return 0;
}



