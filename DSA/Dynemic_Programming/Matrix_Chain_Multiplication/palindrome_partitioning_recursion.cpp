#include<bits/stdc++.h>
using namespace std;

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

    int mn = INT_MAX;
    for(int k = i; k <= j-1; k++)
    {
        int temp = (solve(str, i, k) + solve(str, k+1, j) + 1);
        mn = min(mn, temp);
    }

    return mn;
}

int main()
{
    string str = "niti";
    int n = str.size();

    cout<<solve(str, 0, n-1)<<"\n";
    return 0;
}