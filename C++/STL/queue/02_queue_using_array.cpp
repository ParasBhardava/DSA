#include <bits/stdc++.h>
using namespace std;
#define n 5

class Queue
{
    int front;
    int rear;
    int count;
    int arr[n];

public:
    Queue()
    {
        front = 0;
        rear = 0;
        count = 0;
    }

    void push(int val)
    {
        if (count == n)
        {
            cout << "Queue is Overflow\n";
            return;
        }

        arr[rear % n] = val;
        rear++;
        count++;
    }

    void pop()
    {
        if (count == 0)
        {
            cout << "Queue is underflow\n";
            return;
        }

        arr[front % n] = -1;
        front++;
        count--;
    }

    int top()
    {
        if (count == 0)
        {
            cout << "Queue is empty!\n";
            return -1;
        }

        return arr[front % n];
    }

    bool empty()
    {
        return count == 0;
    }

    int size()
    {
        return count;
    }

    void print()
    {
        for (int i = front; i <= rear - 1; i++)
            cout << arr[i % n] << " ";
        cout << "\n";
    }
};

int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.print();

    q.pop();
    q.print();

    q.push(6);
    q.print();

    q.pop();
    cout<<q.size()<<"\n";
    cout<<(q.empty() == true ? "Empty" : "Not empty");
  
    return 0;
}