#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    list<int> l;
    vector<int> ans;

    int i = 0, j = 0;

    if (k > n)
    {
        ans.push_back(*max(arr.begin(), arr.end()));
    }

    while (j < n)
    {
        while (l.size() > 0 && l.back() < arr[j])
            l.pop_back();
        l.push_back(arr[j]);

        if (j - i + 1 < k)
            j++;

        else if (j - i + 1 == k)
        {
            ans.push_back(l.front());
            if (arr[i] == l.front())
                l.pop_front();

            i++;
            j++;
        }
    }

    for (auto i : ans)
        cout << i << " ";

    return 0;
}