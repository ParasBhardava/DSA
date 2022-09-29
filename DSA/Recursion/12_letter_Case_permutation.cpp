#include <bits/stdc++.h>
using namespace std;

void letterCasePermutation(string str, int idx, string ans, vector<string> &res)
{
    if (idx == str.size())
    {
        res.push_back(ans);
        return;
    }

    if (str[idx] >= '0' && str[idx] <= '9')
    {
        ans.push_back(str[idx]);
        letterCasePermutation(str, idx + 1, ans, res);
    }

    else
    {

        ans.push_back(tolower(str[idx]));
        letterCasePermutation(str, idx + 1, ans, res);
        ans.pop_back();

        ans.push_back(toupper(str[idx]));
        letterCasePermutation(str, idx + 1, ans, res);
    }
}

int main()
{
    string str = "a1b2";
    vector<string> res;

    letterCasePermutation(str, 0, "", res);

    for (auto &s : res)
        cout << s << "\n";

    return 0;
}