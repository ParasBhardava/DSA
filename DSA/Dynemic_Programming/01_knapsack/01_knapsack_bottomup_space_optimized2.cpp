#include <bits/stdc++.h>

using namespace std;

int knapsack(int n, int W, int wet[], int val[])
{
    vector<int> prev(W + 1, 0);

    for (int j = wet[0]; j <= W; j++)
        prev[j] = val[0];

    for (int i = 1; i < n; i++)
    {
        for (int j = W; j >= 0; j--)
        {
            int take = INT_MIN;
            if (wet[i] <= j)
                take = val[i] + prev[j - wet[i]];

            int dontTake = prev[j];

            prev[j] = max(take, dontTake);
        }
    }

    return prev[W];
}

int main()
{
    int n = 3;
    int wet[] = {10, 20, 30};
    int val[] = {60, 100, 120};
    int W = 50;

    cout << "Total Value: " << knapsack(n, W, wet, val) << "\n";

    return 0;
}
