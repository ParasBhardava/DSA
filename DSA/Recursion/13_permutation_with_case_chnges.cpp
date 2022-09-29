#include<bits/stdc++.h>
using namespace std;

void permutation_with_case_changes(string str, int idx, string ans, vector<string>&res)
{
    if(idx == str.size())
    {
        res.push_back(ans);
        return;
    }

    ans.push_back(tolower(str[idx]));
    permutation_with_case_changes(str, idx + 1, ans, res);
    ans.pop_back();

    ans.push_back(toupper(str[idx]));
    permutation_with_case_changes(str, idx + 1, ans, res);
}

int main()
{
    string str= "abc";
    vector<string>res;

    permutation_with_case_changes(str, 0, "", res);
    
    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}