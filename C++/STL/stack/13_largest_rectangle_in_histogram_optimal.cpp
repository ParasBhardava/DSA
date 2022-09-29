#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>&height)
{
    int n = height.size();
    int maxA = 0;
    stack<int>st;

    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && (i == n || height[i] <= height[st.top()]))
        {
            int h = height[st.top()];
            st.pop();

            int width;
            if(st.empty())
                width = i;

            else
                width = i - st.top() - 1;

            maxA = max(maxA, width * h);
        }

        st.push(i);
    }

    return maxA;
}

int main()
{
    vector<int>height{2,1,5,6,2,3};
    cout<<largestRectangleArea(height);
    return 0;
}