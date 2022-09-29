#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &arr, int sum)
{
    int n = arr.size();
    vector<int> arr1, arr2;

    for (int i = 0; i < n / 2; i++)
        arr1.push_back(arr[i]);

    for (int i = n / 2; i < n; i++)
        arr2.push_back(arr[i]);

    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> left;
    for (int num = 0; num < (1 << n1); num++)
    {
        int s = 0;
        for (int i = 0; i < n1; i++)
        {
            if (num & (1 << i))
                s += arr1[i];
        }

        left.push_back(s);
    }

    vector<int> right;
    for (int num = 0; num < (1 << n2); num++)
    {
        int s = 0;
        for (int i = 0; i < n2; i++)
        {
            if (num & (1 << i))
                s += arr2[i];
        }
        right.push_back(s);
    }

    sort(right.begin(), right.end());
    int count = 0;

    for (int it : left)
        count += upper_bound(right.begin(), right.end(), sum - it) - right.begin();

    return count;
}

int main()
{
    // find the subsequences whose addition <= sum
    vector<int> arr = {1, 2, 4, 6, 3};
    int sum = 8;

    cout << solve(arr, sum);
    return 0;
}
