#include<bits/stdc++.h>
using namespace std;

int t[11][51];
int solve(int eggs, int floor)
{
    if(floor == 0 || floor == 1)
        return floor;

    if(eggs == 1)
        return floor;

    if(t[eggs][floor] != -1)
        return t[eggs][floor];

    int mn = INT_MAX;
    for(int k = 1; k<=floor; k++) 
    {
        int temp = 1 + max(solve(eggs-1, k-1), solve(eggs, floor-k));   // for worst case
        mn = min(mn, temp);
    }

    return (t[eggs][floor] = mn);
}

int main()
{
    int floor = 4;
    int eggs = 3;
    memset(t, -1, sizeof(t));

    cout<<solve(eggs, floor);
    return 0;
}