#include <iostream>
#include <stack>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// cconsecutive smaller or equal before it
// nearest greater to left
vector<int> stock_span(vector<int> v)
{
    stack<pair<int, int>> st; // stack({NGL, index})
    vector<int> ans;

    for (int i = 0; i < v.size(); i++)
    {
        if (st.size() == 0)
            ans.push_back(-1);

        else if (st.size() > 0 && st.top().first > v[i])
            ans.push_back(st.top().second);

        else if (st.size() > 0 && st.top().first <= v[i])
        {
            while (st.size() > 0 && st.top().first <= v[i])
            {
                st.pop();
            }

            if (st.size() == 0)
                ans.push_back(-1);

            else
                ans.push_back(st.top().second);
        }

        st.push({v[i], i});
    }

    for (int i = 0; i < ans.size(); i++)
        ans[i] = i - ans[i];

    return ans;
}

int main()
{
    vector<int> v{100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stock_span(v);

    for (int i = 0; i < span.size(); i++)
    {
        cout << span[i] << " ";
    }

    return 0;
}