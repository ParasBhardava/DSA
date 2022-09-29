#include<bits/stdc++.h>

using namespace std;

int main()
{
    multiset<string>s;
    s.insert("abc");            // O(logn)
    s.insert("xyz");
    s.insert("xyz");
    s.insert("pqr");
    s.insert("mno");
    s.erase("xyz");  // this will remove all element with value "xyz"  --> O(logn)
    
    // auto it = s.find("xyz");

    // if(it != s.end())   
    //     s.erase(it);            // this will remove the first element with value "cyz"

    for(auto val : s)
    {
        cout<<val<<" ";
    }
    cout<<"\n";

    return 0;
}