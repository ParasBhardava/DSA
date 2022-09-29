#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aabaabaa";
    string ptn = "aaba";

    unordered_map<char, int>mp;
    for(int i = 0; i<ptn.size(); i++)
    {
        mp[ptn[i]]++;
    }
    int count = mp.size();


    int i=0, j=0, ans = 0;
    while(j<str.size())
    {
        if(mp.find(str[j]) != mp.end())
        {
            mp[str[j]]--;
            if(mp[str[j]] == 0)
                count--;
        }

        if(j-i+1 < ptn.size())
            j++;

        else if(j-i+1 == ptn.size())
        {
            if(count == 0)
                ans++;

            if(mp.find(str[i]) != mp.end())
            {
                mp[str[i]]++;
                if(mp[str[i]] == 1)
                    count++;
            }

            i++;
            j++;
        }
    }

    cout<<ans<<"\n";

    return 0;
}