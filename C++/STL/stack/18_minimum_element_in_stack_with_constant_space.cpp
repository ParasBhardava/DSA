#include<bits/stdc++.h>
using namespace std;

stack<int>st;
int minElement;

void push(int val)
{
    if(st.size() == 0)
    {
        st.push(val);
        minElement = val;
    }

    else
    {
        if(val >= minElement)
            st.push(val);

        else if(val < minElement)
        {
            st.push(2*val-minElement);
            minElement = val;
        }
    }
}

void pop()
{
    if(st.size() == 0)
        return;

    else
    {
        if(st.top() >= minElement)
            st.pop();

        else if(st.top() < minElement)
        {
            minElement = 2*minElement-st.top();
            st.pop();
        }
    }
}

int top()
{
    if(st.size() == 0)
        return -1;

    if(st.top() >= minElement)
        return st.top();

    else if(st.top() < minElement)
        return minElement; 

    return -1;
}

int main()
{
    vector<int>v{18, 28, 29, 15, 16};
    for(int i = 0; i<v.size(); i++)
    {
        push(v[i]);
    }

    cout<<top()<<"\n";
    cout<<minElement<<"\n";

    return 0;
}