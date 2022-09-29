#include<bits/stdc++.h>

using namespace std;

int main()
{
    int row, column;
    cin>>row>>column;

    int arr[row][column];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            cin>>arr[i][j];
        }
    }

    vector<vector<int>>ans(row+column-1);
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
        {
            ans[i+j].push_back(arr[j][i]);
            cout<<i<<j<<" ";
        }
        cout<<"\n";
    }

    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}