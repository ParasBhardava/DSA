/*
Given 2D array of NxN integers. GIven Q queries and in each query given a, b, c and d print sum of square represented by (a, b) as top left point and (c, d) as top bottom right point.

It is useful to take 1 based index array instaed of 0 based in prefix sum.

*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int arr[N][N];
long long int prefix[N][N];

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>arr[i][j];
            prefix[i][j] = arr[i][j] + prefix[i-1][j] + prefix[i][j-1] - prefix[i-1][j-1];
        }
    }

    int q;
    cin>>q;
    while(q--)
    {
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        long long int sum = 0;
        cout<<prefix[c][d]-prefix[a-1][d]-prefix[c][b-1]+prefix[a-1][b-1]<<"\n";
    }

    return 0;
}