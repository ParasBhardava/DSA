#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int sum)
{
    int n = coins.size();
    vector<int> prev(sum + 1, 0);
    vector<int> curr(sum + 1, 0);

    for (int j = 0; j <= sum; j++)
    {
        if (j % coins[0] == 0)
            prev[j] = j / coins[0];

        else
            prev[j] = INT_MAX - 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int dontTake = prev[j];

            int take = INT_MAX;
            if (coins[i] <= j)
                take = 1 + curr[j - coins[i]];

            curr[j] = min(take, dontTake);
        }

        prev = curr;
    }

    return prev[sum];
}

int main()
{
    int n = 3;
    vector<int> coins = {25, 10, 5};
    int sum = 30;
    cout << minCoins(coins, sum) << "\n";
    return 0;
}