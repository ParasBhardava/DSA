#include <iostream>
#include <stack>

using namespace std;

stack<int> stack_sort(stack<int> &st)
{
    stack<int> temp_stack;
    
    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        while (!temp_stack.empty() && temp_stack.top() > temp)
        {
            st.push(temp_stack.top());
            temp_stack.pop();
        }

        temp_stack.push(temp);
    }

    return temp_stack;
}

int main()
{
    stack<int> st;
    st.push(12);
    st.push(1);
    st.push(5);
    st.push(16);
    st.push(3);
    st.push(8);
    st.push(11);

    stack<int>temp = stack_sort(st);

    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }

    return 0;
}