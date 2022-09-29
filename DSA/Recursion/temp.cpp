#include<bits/stdc++.h>
using namespace std;

void solve(string str, int idx, string ans, vector<string>&res)
{
    if(idx == str.size())
    {
        res.push_back(ans);
        return;
    }

    ans.push_back('_');
    ans.push_back(str[idx]);
    solve(str, idx+1, ans, res);
    ans.pop_back();
    ans.pop_back();

    ans.push_back(str[idx]);
    solve(str, idx + 1, ans, res);

}

int main()
{
    string str = "abc";
    vector<string>res;
    string ans = "";
    ans.push_back(str[0]);

    solve(str, 1, ans, res);
    
    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}