#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    node *top;
    int count;

public:

    Stack()
    {
        top = NULL;
        count = 0;
    }

    void push(int val)
    {
        node *newnode = new node(val);
        newnode->next = top;
        top = newnode;
        count++;
    }

    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow\n";
            return;
        }
        node *temp = top;
        top = top->next;
        count--;
        free(temp);
    }

    int Top()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty\n";
            return -1;
        }

        return top->data;
    }

    void print()
    {
        node *temp = top;
        if (temp == NULL)
        {
            cout << "Stack is Empty\n";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "\n";
    }

    bool empty()
    {
        return top == NULL;
    }

    int size()
    {
        return count;
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

    cout << "Size: " << st.size() << "\n";
    cout << (st.empty() == true ? "Empty\n" : "Not Empty\n");
    cout << "Top: " << st.Top() << "\n";

    st.pop();
    cout << "Size: " << st.size() << "\n";
    cout << (st.empty() == true ? "Empty\n" : "Not Empty\n");
    cout << "Top: " << st.Top() << "\n";

    st.print();
    while (!st.empty())
    {
        cout << st.Top() << " ";
        st.pop();
    }

    return 0;
}