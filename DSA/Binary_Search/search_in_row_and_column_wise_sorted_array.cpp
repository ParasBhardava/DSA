#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4, m=4;
    int mat[4][4]= { {10, 20, 30, 40},
                     {1, 25, 35, 45},
                     {27, 29, 37, 48},
                     {32, 33, 39, 50} };


    int val = 29, i = 0, j=m-1;

    while(i>=0 && i<n && j>=0 && j<m)
    {
        if(mat[i][j] == val)
        {
            cout<<i<<" "<<j<<"\n";
            break;
        }

        else if(mat[i][j] > val)
            j--;

        else if(mat[i][j] < val)
            i++;
    }

    return 0;
}