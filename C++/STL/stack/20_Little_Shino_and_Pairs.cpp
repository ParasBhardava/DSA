// Problem Link : https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/little-shino-and-pairs/

#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &arr)
{
    stack<int> st;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && st.top() <= arr[i])
        {
            count++;
            st.pop();
        }

        if (!st.empty())
            count++;

        st.push(arr[i]);
    }

    return count;
}

int main()
{

    int n = 5;
    vector<int> arr = {1, 3, 4, 2, 5};

    cout << solve(n, arr) << "\n";

    return 0;
}