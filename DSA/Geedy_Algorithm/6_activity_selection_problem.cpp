#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>>arr{{10, 20}, {12, 15}, {20, 30}};

    sort(arr.begin(), arr.end(), [&](vector<int>&a, vector<int>&b){
        return a[1] < b[1];
    });

    int take = 1;
    int end = arr[0][1];

    for(int i = 1; i < arr.size(); i++)
    {
        if(arr[i][0] >= end)
        {
            take++;
            end = arr[i][1];
        }
    }

    cout<<take<<"\n";

    return 0;
}