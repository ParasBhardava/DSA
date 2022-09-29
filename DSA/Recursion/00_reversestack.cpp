#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>&st, int temp)
{
    if(st.size() == 0)
    {
        st.push(temp);
        return;
    }

    int k = st.top();
    st.pop();
    insert(st, temp);
    st.push(k);
}

void reverse(stack<int>&st)
{
    if(st.size() == 1)
        return;
    
    int temp = st.top();
    st.pop();
    reverse(st);
    insert(st, temp);
}

int main()
{
    stack<int>st;
    st.push(5);
    st.push(4);
    st.push(3);
    st.push(2);
    st.push(1);      // 1 2 3 4 5

    reverse(st);

    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
    return 0;
}