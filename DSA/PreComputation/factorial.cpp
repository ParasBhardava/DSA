#include<bits/stdc++.h>
using namespace std;
const int N = 1e7;
long long fact[N];

int main()
{
    fact[0] = fact[1] = 1;
    for(int i = 2; i<=N; i++)
    {
        fact[i] = i * fact[i-1];
    }

    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<n*fact[n-1]<<" ";
    }
    return 0;
}