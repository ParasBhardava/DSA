#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    int blockSize = sqrt(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

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

    int l = 0, r = 0, sum = arr[0];

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
            sum += arr[r];
        }

        // remove elements to satisfy the new range
        while (r > R)
        {
            sum -= arr[r];
            r--;
        }

        // move l to the right
        while (l <= L)
        {
            sum -= arr[l];
            l++;
        }

        // move l to the left, that means you are including that elements
        while (l > L)
        {
            l--;
            sum += arr[l];
        }

        queriesAns[it.second] = sum;
    }

    for (int i = 0; i < q; i++)
        cout << queriesAns[i] << " ";

    return 0;
}