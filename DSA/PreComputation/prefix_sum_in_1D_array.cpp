/*
Given an array of N integers, Given Q queries and in each query given L and R print sum of array elements from index L to R(L, R included)  
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int arr[N];
long long int prefix[N];

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        prefix[i] += prefix[i-1] + arr[i];
    }   

    int q;
    cin>>q;
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<"\n";
    }

    return 0;
}