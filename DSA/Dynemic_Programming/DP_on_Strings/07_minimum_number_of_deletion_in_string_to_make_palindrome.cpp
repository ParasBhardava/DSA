#include<bits/stdc++.h>
using namespace std;

int minDeletion(string str, int n)
{
    string str1 = str;
    reverse(str.begin(), str.end());
    string str2 = str;

    int t[n+1][n+1];

    for(int i = 0; i < n+1; i++)
        t[0][i] = 0;

    for(int i = 0; i < n+1; i++)
        t[i][0] = 0;

    for(int i=1; i<n+1; i++)
    {
        for(int j=1; j<n+1; j++)
        {
            if(str1[i-1] == str2[j-1])
                t[i][j] = 1+t[i-1][j-1];

            else
                t[i][j] = max(t[i][j-1], t[i-1][j]);
        }
    }

    return n-t[n][n];
   
}

int main()
{
    string str = "agbcba";
    // string str = "aebcbda";
    int n = str.size();

    cout<<minDeletion(str, n)<<"\n";

    return 0;
}