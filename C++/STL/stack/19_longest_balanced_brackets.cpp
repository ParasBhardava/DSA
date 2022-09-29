#include <bits/stdc++.h>
using namespace std;

int maxLength(vector<int> &arr)
{
    int n = arr.size();
    int maxi = 0;
    stack<int> st; // stack keeps track of last unbalanced bracket
    st.push(0);

    for (int i = 1; i <= n; i++)
    {

        if (arr[i] > 0)
            st.push(i);

        else
        {
            int lastIdx = st.top();
            st.pop();

            if (arr[lastIdx] == -1 * arr[i])
                maxi = max(maxi, i - st.top());

            else
                st.push(i);
        }
    }

    return maxi;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n + 1); // take 1 based index array
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    cout << maxLength(arr);

    return 0;
}

// 1 -1 2 -2 6 4 5 -5 6 7 -7 -6 -4 9 -9 10