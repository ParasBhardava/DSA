#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    vector<int> arr = {2, 2, 3, 3, 4, 4};

    int diff = 0;
    int i = 0, j = 0;
    int ans = 1;

    while (j < n)
    {

        if (abs(arr[j] - arr[i]) <= 1)
            j++;

        else if (j < n && abs(arr[j] - arr[i]) > 1)
        {
            while (j < n && abs(arr[j] - arr[i]) > 1)
            {
                i++;
            }

            j++;
        }

        cout << i << " " << j << "\n";

        ans = max(ans, j - i);
    }

    cout << ans << "\n";

    return 0;
}