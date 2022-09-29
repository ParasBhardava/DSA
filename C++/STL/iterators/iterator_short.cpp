#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int>v = {1, 3, 4, 5, 7, 6};

    // values are copyid not actuall passed
    for(int val : v)
    {
        val++;
    }

    //Range Based loops
    for(int val : v)
    {
        cout<<val<<" ";
    }
    cout<<"\n";

    // actuall values are passed by reference 
    for(int &val : v)
    {
        val++;
    }

    for(int val : v)
    {
        cout<<val<<" ";
    }


    return 0;
}
