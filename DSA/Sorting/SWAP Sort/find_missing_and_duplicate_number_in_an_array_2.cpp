#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<int>arr{3,1,2,5,3};

    int  i = 0;
    while(i < arr.size())
    {
        if(arr[i] != arr[arr[i]-1])
            swap(arr[i], arr[arr[i]-1]);
        
        else
            i++;
    }    

    vector<int>missing;
    vector<int>duplicates;
    for(int i = 0; i<arr.size(); i++)
    {
        if(arr[i] != i+1)
        {
            missing.push_back(i+1);
            duplicates.push_back(arr[i]);
        }
    }

    cout<<"Missing : ";
    for(int i : missing)
        cout<<i<<" ";

    cout<<"\nDuplicates : ";
    for(int i : duplicates)
        cout<<i<<" ";

    return 0;
}

// Swap Sort :
// this method is scalabale(alsp used for multiple missing and multiple duplicates)
// Time Complexity is O(N)