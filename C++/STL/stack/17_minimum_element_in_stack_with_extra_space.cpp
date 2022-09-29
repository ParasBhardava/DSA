#include<bits/stdc++.h>
using namespace std;

stack<int>st;
stack<int>supporting_stack;

void push(int val)
{
    st.push(val);
    
    if(supporting_stack.size() == 0 || supporting_stack.top() >= val)
        supporting_stack.push(val);

}

int pop()
{
    if(st.size() == 0)
        return -1;

    int top = st.top();
    st.pop();

    if(top == supporting_stack.top())
        supporting_stack.pop();

    return top;
}

int getMin()
{
    if(supporting_stack.size() == 0)
        return -1;

    return supporting_stack.top();
}

int main()
{
    vector<int>v{18, 28, 29, 15, 16};
    for(int i = 0; i<v.size(); i++)
    {
        push(v[i]);
    }

    cout<<getMin()<<"\n";

    return 0;
}