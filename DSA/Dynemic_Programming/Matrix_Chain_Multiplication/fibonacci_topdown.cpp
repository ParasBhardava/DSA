#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    int t[n+1];

    t[0] = 0;
    t[1] = 1;
    t[2] = 1;

    for(int i = 3;  i<n+1; i++)
        t[i] = t[i-1] + t[i-2];

    return t[n];
}

int main()
{
    int n;
    cin>>n;
    cout<<fibonacci(n)<<"\n";
    return 0;
}

// fibonaci sequence : 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ... 