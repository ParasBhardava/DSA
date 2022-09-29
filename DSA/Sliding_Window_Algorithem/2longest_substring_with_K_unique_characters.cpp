#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "aabacbebebe";
    int k = 3;

    int i = 0, j = 0, ans = 0, mx = INT_MIN;
    unordered_map<char, int>mp;

    while(j<str.size())
    {
        mp[str[j]]++;

        if(mp.size()<k)
            j++;

        else if(mp.size() == k)
        {
            mx = max(mx, j-i+1);
            j++;
        }

        else if(mp.size() > k)
        {
            while(mp.size() > k)
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