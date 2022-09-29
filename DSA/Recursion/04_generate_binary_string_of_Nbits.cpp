#include<bits/stdc++.h>
using namespace std;

void solve(int n, int idx, string ans, vector<string>&res)
{
    if(idx == n)
    {
        res.push_back(ans);
        return;
    }

    ans[idx] = '0';
    solve(n, idx+1, ans, res);

    ans[idx]= '1';
    solve(n, idx+1, ans, res);
}

int main()
{
    int n;
    cin >> n;
    string ans(n, 0);
    vector<string>res;

    solve(n, 0, ans, res);

    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}