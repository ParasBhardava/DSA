#include <bits/stdc++.h>
using namespace std;

int solve(string &s1, string &s2)
{
    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
        ans += abs(s1[i] - s2[i]);

    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }

        vector<int> temp;
        for (auto it : mp)
        {
            if (it.second >= k)
                temp.push_back(it.first);
        }

        if (temp.size() == 0)
        {
            cout << -1 << endl;
            continue;
        }

        sort(temp.begin(), temp.end());
        int maxi = 1;
        int l = temp[0], r = temp[0];
        int last = temp[0];

        for (int i = 1; i < temp.size(); i++)
        {
            if (temp[i] - 1 == temp[i - 1])
            {
                if (temp[i] - last + 1 > maxi)
                {
                    l = last;
                    r = temp[i];
                    maxi = temp[i] - last + 1;
                }
            }

            else
            {
                last = temp[i];
            }
        }
        cout << l << " " << r << "\n";
    }

    return 0;
}
