#include<bits/stdc++.h>
using namespace std;

int solve(int n)
{
    if(n == 0 || n == 1 || n == 2 || n == 3)
        return n;

    int t[n+1];
    t[0] = 0;
    t[1] = 1;
    t[2] = 2;
    t[3] = 3;

    for (int i = 4; i < n+1; i++)
    {
        t[i] = i;
 
        for (int j = 1; j <= ceil(sqrt(i)); j++)
        {
            if (j*j > i)
                break;
         
            else
                t[i] = min(t[i], 1 + t[i - j*j]);
        }
    }
 

    return t[n];
}

int main()
{
    int n = 5;
    cout<<solve(n)<<"\n";
    return 0;
}