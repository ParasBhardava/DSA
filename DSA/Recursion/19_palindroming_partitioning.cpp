#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end)
{
    while (start <= end)
    {
        if (str[start++] != str[end--])
            return false;
    }

    return true;
}

void solve(int idx, string str, vector<string> &ans, vector<vector<string>> &res)
{
    if (idx == str.size())
    {
        res.push_back(ans);
        return;
    }

    for (int i = idx; i < str.size(); i++)
    {
        if (isPalindrome(str, idx, i))
        {
            ans.push_back(str.substr(idx, i - idx + 1));
            solve(i + 1, str, ans, res);
            ans.pop_back();
        }
    }
}

int main()
{
    string str = "aabb";
    vector<string> ans;
    vector<vector<string>> res;
    solve(0, str, ans, res);

    for (auto &v : res)
    {
        for (auto &s : v)
            cout << s << " ";
        cout << "\n";
    }

    return 0;
}