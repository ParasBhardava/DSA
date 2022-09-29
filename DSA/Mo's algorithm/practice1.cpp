// Find the number of distinct elements in range (L - R)
/// https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 11;
    vector<int> arr = {20, 37, 20, 12, 12, 16, 37, 16, 20, 20, 12};
    int blockSize = sqrt(n);

    vector<pair<pair<int, int>, int>> queries;
    int q;
    cin >> q;
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

    int l = 0, r = 0, count = 1;
    vector<int> freq(1000001, 0);
    freq[arr[0]]++;

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
            freq[arr[r]]++;

            if (freq[arr[r]] == 1)
                count++;
        }

        // remove elements to satisfy the new range
        while (r > R)
        {
            freq[arr[r]]--;

            if (freq[arr[r]] == 0)
                count--;

            r--;
        }

        // move l to the right
        while (l <= L)
        {
            freq[arr[l]]--;

            if (freq[arr[l]] == 0)
                count--;

            l++;
        }

        // move l to the left, that means you are including that elements
        while (l > L)
        {
            l--;
            freq[arr[l]]++;
            if (freq[arr[l]] == 1)
                count++;
        }

        queriesAns[it.second] = count;
    }

    for (int i = 0; i < q; i++)
        cout << queriesAns[i] << " ";

    return 0;
}