#include<bits/stdc++.h>

using namespace std;

int main()
{
    unordered_set<string>s;
    s.insert("abc");            // O(1)
    s.insert("xyz");
    s.insert("xyz");
    s.insert("pqr");
    s.insert("mno");
    s.erase("pqr");            // O(1)

    for(auto val : s)
    {
        cout<<val<<" ";
    }
    cout<<"\n";

    auto it = s.find("abcd");            // O(1)
    if(it != s.end())
    {
        cout<<(*it);
    }
    return 0;
}