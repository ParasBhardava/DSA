#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int amount;
    cout<<"\n";
    cout << "Enter total amount: ";
    cin >> amount;

    vector<pair<int, int>> coin;
    int total = 0;

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] <= amount)
        {
            total += (amount / arr[i]);
            coin.push_back({arr[i], amount / arr[i]});
            amount -= (arr[i] * (amount / arr[i]));
        }
        if (amount <= 0)
            break;
    }
    cout << "\n" << "Total Coin Needed: " << total << "\n";
    cout << "\n"<<"BreakDown: "<<"\n";
    cout << "Value\tNumberOfCoin\tTotal\n";    
    for (int i = 0; i < (int)coin.size(); i++)
        cout << coin[i].first << "\t" << coin[i].second << "\t\t" << coin[i].first * coin[i].second << endl;

    cout<<"\n";

    return 0;
}
