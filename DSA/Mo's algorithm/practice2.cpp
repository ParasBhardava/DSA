// Problem Link : https://codeforces.com/problemset/problem/86/D

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    int blockSize = sqrt(n);
    vector<int> arr(n + 1);
    vector<pair<pair<int, int>, int>> queries;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        queries.push_back({{l, r}, i});
    }

    // This is the gist of the Mo's algo
    sort(queries.begin(), queries.end(), [&](pair<pair<int, int>, int> &a, pair<pair<int, int>, int> &b)
         {
            int blockNo1 = a.first.first / blockSize;
            int blockNo2 = b.first.first / blockSize;

            // if block number is same then sort based in right index
            if(blockNo1 == blockNo2)
                return a.first.second < b.first.second;

            // sort based on block number
            return blockNo1 < blockNo2; });

    vector<int> freq(1000001, 0);
    freq[arr[1]]++;
    int l = 1, r = 1, sum = freq[arr[1]] * freq[arr[1]];

    vector<int> queriesAns(q);
    for (auto &it : queries)
    {
        int L = it.first.first;
        int R = it.first.second;

        // Write the two pointer approach

        // Move r to the right to add new elements
        while (r < R)
        {
            r++;
            sum -= freq[arr[r]] * freq[arr[r]] * arr[r];
            freq[arr[r]]++;
            sum += freq[arr[r]] * freq[arr[r]] * arr[r];
        }

        // remove elements to satisfy the new range
        while (r > R)
        {
            sum -= freq[arr[r]] * freq[arr[r]] * arr[r];
            freq[arr[r]]--;
            sum += freq[arr[r]] * freq[arr[r]] * arr[r];

            r--;
        }

        // move l to the right
        while (l <= L)
        {
            sum -= freq[arr[l]] * freq[arr[l]] * arr[l];
            freq[arr[l]]--;
            sum += freq[arr[l]] * freq[arr[l]] * arr[l];

            l++;
        }

        // move l to the left, that means you are including that elements
        while (l > L)
        {
            l--;
            sum -= freq[arr[l]] * freq[arr[l]] * arr[l];
            freq[arr[l]]++;
            sum += freq[arr[l]] * freq[arr[l]] * arr[l];
        }

        queriesAns[it.second] = sum;
    }

    for (int i = 0; i < q; i++)
        cout << queriesAns[i] << " ";

    return 0;
}