#include <bits/stdc++.h>
using namespace std;

// Method 1: using 2 stacks
// Steps :
// push(x)
// s1 ---> s2 (element by element)
// x ---> s1
// s2 ---> s1(element by element)
// pop()
// s1.pop()

// Method 2: Usong two stacks but optimal
// steps :
// push(x)
// add x ---> s1
// pop()
// if(output stack not empty) 
//      output.pop()
// else
//      input ---> output (element by element)
//
// output.pop()
// top()
// if(output stack not empty) 
//      return output.pop()
// else
//      input ---> output (element by element)
//
// return output.pop()



class Queue
{
    stack<int> input;
    stack<int> output;
    int count = 0;

public:
    void push(int val)
    {
        input.push(val);
        count++;
    }

    int pop()
    {
        if (input.empty() && output.empty())
        {
            cout << "Queue is underflow\n";
            return -1;
        }

        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        int val = output.top();
        output.pop();
        count--;
        return val;
    }

    int front()
    {
        if (input.empty() && output.empty())
        {
            cout << "Queue is Empty\n";
            return -1;
        }

        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }

        return output.top();
    }

    int size()
    {
        return count;
    }

    bool empty()
    {
        if (input.empty() && output.empty())
            return true;

        return false;
    }
};

// Usng recursion
// class Queue
// {
//     stack<int>st;

//     public:
//     void push(int val)
//     {
//         st.push(val);
//     }

//     int pop()
//     {
//         if(st.empty())
//         {
//             cout<<"Queue Undeflow\n";
//             return -1;
//         }

//         int val = st.top();
//         st.pop();

//         if(st.empty())
//             return val;

//         int ans = pop();
//         st.push(val);

//         return ans;
//     }
// };

int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
  

    cout <<"size: " << q.size()<<"\n";
    cout<<"Front :"<<q.front()<<"\n";
    q.pop();
    cout <<"size: " << q.size()<<"\n";
    cout<<"Front :"<<q.front()<<"\n";

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    

    return 0;
}

