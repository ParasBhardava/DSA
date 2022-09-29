#include <bits/stdc++.h>
using namespace std;

// int solve(int n, vector<int> &price)
// {
//     vector<int> prev(n + 1, 0);
//     vector<int> curr(n + 1, 0);

//     for (int j = 0; j <= n; j++)
//     {
//         prev[j] = j * price[0];
//     }

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 0; j <= n; j++)
//         {
//             int dontTake = prev[j];

//             int take = INT_MIN;
//             int currLenght = i + 1;
//             if (j - currLenght >= 0)
//                 take = price[i] + curr[j - currLenght];

//             curr[j] = max(take, dontTake);
//         }

//         prev = curr;
//     }

//     return prev[n];
// }

int solve(int n, vector<int> &price)
{
    vector<int> prev(n + 1, 0);
    vector<int> curr(n + 1, 0);

    for (int j = 0; j <= n; j++)
    {
        prev[j] = j * price[0];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            int dontTake = prev[j];

            int take = INT_MIN;
            int currLenght = i + 1;
            if (j - currLenght >= 0)
                take = price[i] + prev[j - currLenght];

            curr[j] = max(take, dontTake);
        }

        prev = curr;
    }

    return prev[n];
}

int main()
{
    int n = 8;
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    cout << solve(n, price);

    return 0;
}