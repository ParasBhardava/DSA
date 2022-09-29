#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    int blockSize = sqrt(n);
    vector<int> block(blockSize + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];

        // it belongs yo i / blockSize
        block[i / blockSize] += arr[i];
    }

    // Update Query
    int idx, val;
    cin >> idx >> val;
    arr[idx] += val;
    block[idx / blockSize] += val;

    // Range Sum Query
    int l, r;
    cin >> l >> r;

    int i = l, sum = 0;
    while (i <= r)
    {
        if (i % blockSize == 0 && i + blockSize - 1 <= r)
        {
            sum += block[i / blockSize];
            i += blockSize;
        }

        else
        {
            sum += arr[i];
            i++;
        }
    }

    cout << sum << " ";

    return 0;
}