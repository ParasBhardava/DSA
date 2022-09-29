#include<bits/stdc++.h>
using namespace std;

int t[11][51];
int solve(int eggs, int floor)
{

    if(floor == 0 || floor == 1)
        return floor;

    if(eggs == 1)
        return floor;

    memset(t, -1, sizeof(t));

    if(t[eggs][floor] != -1)
        return t[eggs][floor];

    int mn = INT_MAX;
    for(int k = 1; k<=floor; k++) 
    {
        int low, high;

        if(t[eggs-1][k-1] != -1)
            low = t[eggs-1][k-1];
        else
        {
            low = solve(eggs-1, floor-1);
            t[eggs-1][floor-1] = low;
        }

        if(t[eggs][floor-k] != -1)
            high = t[eggs][floor-k];
        else
        {
            high = solve(eggs, floor-k);
            t[eggs][floor-k] = high;
        }

        int temp = 1 + max(low, high);   // for worst case
        mn = min(mn, temp);
    }

    return mn;
}


int main()
{
    int floor = 4;
    int eggs = 2;
    memset(t, -1, sizeof(t));

    cout<<solve(eggs, floor);
    return 0;
}