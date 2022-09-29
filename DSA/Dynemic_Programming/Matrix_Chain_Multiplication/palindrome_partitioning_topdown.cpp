#include<bits/stdc++.h>
using namespace std;

//  We consider that string length <= 1000
int t[1001][1001];

bool isPalindrome(string str, int i, int j)
{
    while(i <= j)
    {
        if(str[i] != str[j])
            return false;

        i++;
        j--; 
    }
    return true;
}

int solve(string str, int i, int j)
{

    if(i >= j)
        return 0;

    if(isPalindrome(str, i, j) == true)
        return 0;

    int mn = INT_MAX, left, right;
    for(int k = i; k <= j-1; k++)
    {
        if(t[i][k] != -1)
            left = t[i][k];
        else
        {
            left = solve(str, i, k);
            t[i][k] = left;
        }

        if(t[k+1][j] != -1)
            right = t[k+1][j];
        
        else
        {
            right = solve(str, k+1, j);
            t[k+1][j] = right;
        }

        int temp = left + right + 1;
        mn = min(mn, temp);
    }

    return (t[i][j] = mn);
}

int main()
{
    string str = "nitik";
    int n = str.size();
    memset(t, -1, sizeof(t));

    cout<<solve(str, 0, n-1)<<"\n";
    return 0;
}