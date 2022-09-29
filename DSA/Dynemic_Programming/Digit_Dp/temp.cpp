#include <bits/stdc++.h>
using namespace std;

vector<int> convertToVec(int n)
{
    vector<int> num;
    while (n)
    {
        num.push_back(n % 10);
        n /= 10;
    }

    reverse(num.begin(), num.end());
    return num;
}

int solve(int idx, int flag, int mask, vector<int> &num)
{
    if (idx == num.size())
        return (mask != 0);

    int limit = num[idx];

    if (flag == 1)
        limit = 9;

    int ans = 0;
    for (int digit = 0; digit <= limit; digit++)
    {
        if (mask & (1 << digit))
            continue;

        int newMask = (mask == 0 && digit == 0 ? mask : (mask | (1 << digit)));

        if (flag == 1)
        {
            ans += solve(idx + 1, flag, newMask, num);
        }

        else if (flag == 0)
        {
            if (digit < num[idx])
                ans += solve(idx + 1, 1, newMask, num);

            else
                ans += solve(idx + 1, 0, newMask, num);
        }
    }

    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> num = convertToVec(n);
    vector<int> arr(10, 0);
    cout << solve(0, 0, 0, num);
    return 0;
}