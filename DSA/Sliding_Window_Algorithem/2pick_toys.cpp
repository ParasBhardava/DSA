#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "abaccab";
    
    int i = 0, j = 0, mx = 0;
    unordered_map<char, int>mp;

    while(j<str.size())
    {
        mp[str[j]]++;

        if(mp.size()<2)
            j++;

        else if(mp.size() == 2)
        {
            mx = max(mx, j-i+1);
            j++;
        }

        else if(mp.size() > 2)
        {
            while(mp.size() > 2)
            {
                mp[str[i]]--;
                if(mp[str[i]] == 0)
                    mp.erase(str[i]);
                i++;
            }

            j++;
        }
    }

    cout<<mx<<"\n";

    return 0;
}