#include<bits/stdc++.h>
using namespace std;

int solve(string str, int i, int j, bool isTrue)
{
    if(i > j)
    {
        return false;
    }

    if(i == j)
    {
        if(isTrue == true)
        {
            if(str[i] == true)
                return true;

            else
                return false;
        }

        else
        {
            if(str[i] == false)
                return true;

            else
                return false;
        }
    }

    int ans = 0;
    for(int k = i+1; k<j; k+=2)
    {
        int lt = solve(str, i, k-1, true); 
        int lf = solve(str,i, k-1, false);
        int rt = solve(str, k+1, j, true);
        int rf = solve(str, k+1, j, false);
        
    }

    return ans;
}

int main()
{
    string str = "T^F&T";
    cout<<solve(str, 0, str.size()-1, true);
    return 0;
}