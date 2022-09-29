#include<bits/stdc++.h>
using namespace std;

// Method 1: Using Two queues
// Steps
// push(x) :
// add x to q2
// q1 ---> q2 (element by element)
// swap q1 q2
// push():
// remove the front of q1

// class Stack
// {
//     int count;
//     queue<int>q1;
//     queue<int>q2;

//     public :
//     Stack()
//     {
//         count = 0;
//     }

//     void push(int val)
//     {
//         count++;
//         q2.push(val);
//         while(!q1.empty())
//         {
//             q2.push(q1.front());
//             q1.pop();
//         }
//         swap(q1, q2);
//     }

//     void pop()
//     {
//         if(q1.empty())
//         {
//             cout<<"Stack Underflow\n";
//             return;
//         }
    
//         count--;
//         q1.pop();
//     }

//     int Top()
//     {
//         if(q1.empty())
//         {
//             cout<<"Stack is Empty\n";
//             return -1;
//         }

//         return q1.front();
//     }

//     bool empty()
//     {
//         return q1.empty();
//     }

//     int size()
//     {
//         return count;
//     }
// };


// Method 2: Using Two queues
// Steps
// push(x) :
// add x to q1
// pop()
// q1.size() - 1  eleements q1 ---> q2 (element by element)
// q1.pop()
// swap (q1, q2)
// top()
// q1.size() - 1  eleements q1 ---> q2 (element by element)
// ans = q1.front()
// q2.push(ans)
// swap (q1, q2)
// return ans


// Using only one Queue 
class Stack
{
    queue<int>q;
    int count;

public:

    Stack()
    {
        count = 0;
    }

    void push(int val)
    {
        q.push(val);
        for(int i = 0; i <  q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        count++;
    }

    void pop()
    {
        if(q.empty())
        {
            cout<<"Stack Underflow\n";
            return;
        }

        q.pop();
        count--;
    }

    int Top()
    {
        if(q.empty())
        {
            cout<<"Queue is Empty\n";
            return -1;
        }

        return q.front();
    }

    bool empty()
    {
        return q.empty();
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

    while (!st.empty())
    {
        cout << st.Top() << " ";
        st.pop();
    }

    return 0;
}