#include<bits/stdc++.h>
using namespace std;

void generate(int open, int close, string ans, vector<string>&res)
{
    if(open == 0 && close ==0)
    {
        res.push_back(ans);
        return;
    }

    if(open != 0)
       generate(open-1, close, ans + '(', res);

    if(close > open)
        generate(open, close-1, ans + ')', res);

}

int main()
{
    int n;
    cin>>n;
    int open = n, close = n;
    
    vector<string>res;
    generate(open, close, "", res);

    for(auto &s : res)
        cout<<s<<"\n";

    return 0;
}