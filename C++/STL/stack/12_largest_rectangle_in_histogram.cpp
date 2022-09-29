#include<bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int>&height)
{
    int n = height.size();
    stack<int>st;
    int leftSmall[n], rightSmall[n];

    // Code for nearest smallest to left
    for(int i = 0; i < n; i++)
    {
        while(!st.empty() && height[i] <= height[st.top()])
            st.pop();

        if(st.empty())
            leftSmall[i] = 0;

        else
            leftSmall[i] = st.top() + 1;
        
        st.push(i);
    }

    while(!st.empty())
        st.pop();

    // Code for nearest smallest to right
    for(int i = n-1; i >= 0; i--)
    {
        while(!st.empty() && height[i] <= height[st.top()])
            st.pop();

        if(st.empty())
            rightSmall[i] = n-1;

        else
            rightSmall[i] = st.top()-1;

        st.push(i);
    }

    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, height[i]*(rightSmall[i] - leftSmall[i] + 1));

    return ans;
}

int main()
{
    vector<int>height{2,1,5,6,2,3};
    cout<<largestRectangleArea(height);
    return 0;
}