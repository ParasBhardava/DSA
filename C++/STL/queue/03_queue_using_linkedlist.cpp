#include<bits/stdc++.h>
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

class Queue
{
    node *front;
    node *back;
    int count;

    public:

    Queue()
    {
        front = NULL;
        back = NULL;
        count = 0;
    }

    void push(int val)
    {
        node * newnode = new node(val);

        if(front == NULL)
        {
            back = newnode;
            front = newnode;
            count++;
            return;
        }
        back->next = newnode;
        back = newnode;
        count++;
    }

    void pop()
    {
        if(front == NULL)
        {
            cout<<"Queue is Underflow\n";
            return;
        }

        node *delnode = front;
        front = front->next;
        count--;
        delete delnode;
    }

    int Front()
    {
        if(front == NULL)
        {
            cout<<"Queue is empty\n";
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        if(front == NULL)
            return true;

        return false;
    }

    int size()
    {
        return this->count;
    }
};

int main()
{

    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.pop();

    cout<<"Size: "<<q.size()<<"\n";
    cout<<(q.empty() == true ? "Empty\n" : "Not empty\n");
    cout<<"Front: "<<q.Front()<<"\n";

    while (!q.empty())
    {
        cout<<q.Front()<<" ";
        q.pop();
    }
    

    return 0;
}