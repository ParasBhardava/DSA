// Problem Link : https://codeforces.com/problemset/problem/1341/B
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8, k = 6;
    vector<int> arr = {1, 2, 4, 1, 2, 4, 1, 2};

    int peaks = 0;
    for (int i = 1; i < k - 1; i++)
    {
        if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1])
            peaks++;
    }

    int startIdx = 0;
    int maxPeaks = peaks;

    int l = 0, r = k - 1;
    while (r <= n - 2)
    {
        if (arr[r] > arr[r - 1] && arr[r] > arr[r + 1])
            peaks++;
        r++;

        l++;
        if (arr[l] > arr[l - 1] && arr[l] > arr[l + 1])
            peaks--;

        if (peaks > maxPeaks)
        {
            maxPeaks = peaks;
            startIdx = l;
        }
    }

    cout << maxPeaks + 1 << " " << startIdx + 1 << "\n";

    return 0;
}