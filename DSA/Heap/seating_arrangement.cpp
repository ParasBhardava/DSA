// Problem Link : https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/seating-arrangement-6b8562ad/

#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(pair<int, int> &a, pair<int, int> &b)
    {
        if (a.first == b.first)
            return a.second > b.second;

        return a.first < b.first;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;

    string pref;
    cin >> pref;

    priority_queue<pair<int, int>, vector<pair<int, int>>, comp> pq; // {len, starting_point}
    unordered_map<int, int> mp;

    pq.push({n, 1});
    for (int i = 1; i <= k; i++)
    {
        auto it = pq.top();
        pq.pop();

        int len = it.first;
        int s = it.second;
        int e = s + len - 1;

        int mid = (s + e) / 2;

        if (len % 2 == 0 && pref[i - 1] == 'R')
            mid += 1;

        mp[mid] = i;

        if (s != mid)
            pq.push({mid - s, s});

        if (e != mid)
            pq.push({e - mid, mid + 1});
    }

    int q;
    cin >> q;
    while (q--)
    {
        int chair;
        cin >> chair;

        if (mp.find(chair) == mp.end())
            cout << -1 << "\n";

        else
            cout << mp[chair] << "\n";
    }

    return 0;
}