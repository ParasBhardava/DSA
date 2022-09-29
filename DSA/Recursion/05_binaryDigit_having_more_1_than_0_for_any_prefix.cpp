#include<bits/stdc++.h>
using namespace std;

void binaryDigit(int ones, int zeroes, int idx, int n, string ans, vector<string>&res)
{
    if(idx == n)
    {
        res.push_back(ans);
        return;
    }

    binaryDigit(ones+1, zeroes, idx + 1, n, ans + '1', res);

    if(ones > zeroes)
        binaryDigit(ones, zeroes+1, idx + 1, n, ans + '0', res);

}

int main()
{
    int n;
    cin>>n;
    vector<string>res;
    int ones = 0, zeroes = 0;
    string ans = "";

    binaryDigit(ones, zeroes, 0, n, ans, res);

    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}