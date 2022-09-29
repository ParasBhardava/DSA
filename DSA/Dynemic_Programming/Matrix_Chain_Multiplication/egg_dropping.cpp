#include<bits/stdc++.h>
using namespace std;

int solve(int eggs, int floor)
{
    if(floor == 0 || floor == 1)
        return floor;

    if(eggs == 1)
        return floor;

    int mn = INT_MAX;
    for(int k = 1; k<=floor; k++) 
    {
        int temp = 1 + max(solve(eggs-1, k-1), solve(eggs, floor-k));   // for worst case
        mn = min(mn, temp);
    }

    return mn;
}

int main()
{
    int floor = 4;
    int eggs = 2;

    cout<<solve(eggs, floor);
    return 0;
}