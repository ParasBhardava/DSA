#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5, 5, 5, 6, 7, 8, 8};

    for (auto &it : arr)
        cout << it << " ";
    cout << "\n";

    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (auto &it : arr)
        cout << it << " ";
    cout << "\n";

    return 0;
}