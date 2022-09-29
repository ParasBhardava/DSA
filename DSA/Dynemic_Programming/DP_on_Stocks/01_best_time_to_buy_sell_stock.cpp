#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int n = prices.size();
    int mini = prices[0];
    int profit = 0;

    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }

    cout << profit << "\n";

    return 0;
}