#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int idx, int k, int &ans)
{
    if (arr.size() == 1)
    {
        ans = arr[0];
        return;
    }

    idx = (idx + k) % arr.size();
    arr.erase(arr.begin() + idx);

    solve(arr, idx, k, ans);
}

// optimal solution
/*
int solve(int n, int k)
{
    int res = 0;

    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;

    return res + 1;
}
*/

int main()
{
    int n, k;
    cin >> n >> k;

    int ans = 0;
    k -= 1;
    vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(i + 1);

    solve(arr, 0, k, ans);
    cout<<ans<<"\n";
    return ans;
}