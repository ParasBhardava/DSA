#include<bits/stdc++.h>
using namespace std;

int solve(string str)
{
    int n = str.size(), ans = 0, start = 0;
    int dp[n+1][n+1];

    memset(dp, 0, sizeof(dp));

    for(int i = 0; i<n+1; i++)
        dp[i][i] = 0;

    for(int i = 1; i<n+1; i++)
    {
        for(int j = i+1; j<n+1; j++)
        {
            if(str[i-1] == str[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                
                if(ans < dp[i][j])
                {
                    start = i;
                    ans = dp[i][j];
                }

            }
        }
    }

    if(ans == 0)
        cout<<"-1\n";
    else    
        cout<<str.substr(start-ans, ans)<<"\n";
    
    return ans;
}

int main()
{
    string str = "banana";
    cout<<solve(str);
    return 0;
}