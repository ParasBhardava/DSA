#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>&st, int temp)
{
    if(st.size()== 0 || st.top() <= temp)
    {
        st.push(temp);
        return;
    }

    int val = st.top();
    st.pop();
    insert(st, temp);
    st.push(val);

}

void sort(stack<int>&st)
{
    if(st.size() == 1)
        return;

    int temp = st.top();
    st.pop();
    sort(st);
    insert(st, temp);    
}

int main()
{
    stack<int>st;
    st.push(3);
    st.push(5);
    st.push(1);
    st.push(4);
    st.push(2);

    sort(st);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}