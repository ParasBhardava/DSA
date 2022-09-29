#include<bits/stdc++.h>
using namespace std;

void permutation(string str, int idx, vector<string>&res)
{
    if(idx == str.size())
    {
        res.push_back(str);
        return;
    }

    for(int i = idx; i<str.size(); i++)
    {
        swap(str[i], str[idx]);
        permutation(str, idx+1, res);
        swap(str[i], str[idx]);     // Backtracking
    }
}

int main()
{
    string str = "abc";
    vector<string>res;
    permutation(str, 0, res);

    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}