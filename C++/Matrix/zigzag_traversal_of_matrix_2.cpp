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

    vector<list<int>>ans(row+column-1);
    for(int i=0; i<column; i++)
    {
        for(int j=0; j<row; j++)
        {
            if((i+j)%2 == 0)
            ans[i+j].push_back(arr[j][i]);

            else
            {
                ans[i+j].push_front(arr[j][i]);
            }
        }
        cout<<"\n";
    }

    for(int i=0; i<ans.size(); i++)
    {
        for(auto it=ans[i].begin(); it != ans[i].end(); it++)
        {
            cout<<(*it)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}