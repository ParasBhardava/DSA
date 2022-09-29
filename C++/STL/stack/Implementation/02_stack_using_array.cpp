#include<bits/stdc++.h>
using namespace std;
#define n 5

class Stack
{
    int top = -1;
    int arr[n];

    public:

    void push(int val)
    {
        if(top == n-1)
        {
            cout<<"Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = val;
    }    

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow\n";
            return;
        }

        top--;
    }

    int Top()
    {
        if(top == -1)
        {
            cout<<"Stack is empty\n";
            return -1;
        }

        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }

    int size()
    {
        return top+1;
    }

};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    cout<<"Size: "<<st.size()<<"\n";
    cout<<(st.empty() == true ? "Empty\n" : "Not Empty\n");
    cout<<"Top: "<<st.Top()<<"\n";
    
    st.pop();
    cout<<"Size: "<<st.size()<<"\n";
    cout<<(st.empty() == true ? "Empty\n" : "Not Empty\n");
    cout<<"Top: "<<st.Top()<<"\n";
    
    while(!st.empty())
    {
        cout<<st.Top()<<" ";
        st.pop();
    }

    return 0;
}