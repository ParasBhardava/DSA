#include<bits/stdc++.h>
using namespace std;

int rainWaterTrapping(vector<int>&v)
{
    int n = v.size();
    int mxL[n]; 
    int mxR[n]; 

    mxL[0] = v[0];
    for(int i = 1; i<n; i++)
        mxL[i] = max(mxL[i-1], v[i]);

    mxR[n-1] = v[n-1];
    for(int i = n-2; i>=0; i--)
        mxR[i] = max(mxR[i+1], v[i]);

    int water[n], sum = 0;
    for(int i =0; i<n; i++)
    {
        water[i] = min(mxL[i], mxR[i])-v[i];
        sum += water[i];    
    }

    return sum;
}

int main()
{
    vector<int>v{3, 0, 0, 2, 0, 4};
    cout<<rainWaterTrapping(v);

    return 0;
}

/*
                                    4
                3                   |
                |           2       |
                |           |       |
                |   0   0   |   0   |  

index:          0   1   2   3   4   5

*/