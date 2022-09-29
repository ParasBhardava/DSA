// Problem Link : https://www.codechef.com/problems-old/WORKCHEF

#include <bits/stdc++.h>
using namespace std;
const int LCM = 2520;

int dp[19][2][2520][520];

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

int solve(int idx, int flag, int rem, int mask, int k, vector<int> num)
{
    if (idx == num.size())
    {
        int count = 0;
        for (int i = 1; i <= 9; i++)
        {
            if (mask & (1 << i))
            {
                if (rem % i == 0)
                    count++;
            }
        }

        if (count >= k)
            return 1;

        return 0;
    }

    int limit = num[idx];
    if (flag == 1)
        limit = 9;

    int ans = 0;

    for (int digit = 0; digit <= limit; digit++)
    {
        int newMask = mask | (1 << digit);

        if (flag == 1)
            ans += solve(idx + 1, flag, (rem * 10 + digit) % LCM, newMask, k, num);

        else
        {
            if (digit < num[idx])
                ans += solve(idx + 1, 1, (rem * 10 + digit) % LCM, newMask, k, num);

            else
                ans += solve(idx + 1, flag, (rem * 10 + digit) % LCM, newMask, k, num);
        }
    }

    return ans;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;

    memset(dp, -1, sizeof(dp));
    vector<int> num = convertToVec(b);
    int right = solve(0, 0, 0, 0, k, num);

    memset(dp, -1, sizeof(dp));
    num = convertToVec(a - 1);
    int left = solve(0, 0, 0, 0, k, num);

    cout << right - left << "\n";
    return 0;
}

/*
Observation
Let us say that we have a number x, we want to know divisibility of this number for some numbers a1, a2, ....., ak. If you know the reminder of number x by lcm(a1, a2, ..... ak), then can you find its reminder for each of the a1, a2 ..... ak ?

Answer is yes. Observe that you can write any number x as :

x = p * lcm(a1, a2, ..... ak) + q, where 0 <= q < lcm(a1, a2, ...... ak)
x mod ai = q (mod a)i, ai | lcm(a1, a2, a3, a4, ...... ak)

LCM of all the numbers from 2 to 9 will be equal to 2^3 * 3^2 * 5 * 7 = 25202. So, we know the reminder of number modulo 2520, we can find its reminder by each of the numbers from 2 to 9.
*/