#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "adobecodebanc";
    string t = "abc";

    unordered_map<char, int>mp;
    for(int i = 0; i<t.size(); i++)
    {
        mp[t[i]]++;
    }


    int i = 0, j = 0, count = mp.size(), mn = INT_MAX, start = 0;
    
    while(j<s.size())
    {
        if(mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;

            if(mp[s[j]] == 0)
                count--;
        }

        if(count > 0)
            j++;

        else if(count == 0)
        {
            while(count == 0)
            {
                if(j -i +1 < mn)
                {
                    mn = j-i+1;
                    start = i;
                }
                if(mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if(mp[s[i]] == 1)
                        count++;
                }
                i++;
            }
            j++;
        }

    }

    // cout<<mn<<"\n";
    cout<<s.substr(start, mn)<<"\n";

    return 0;
}