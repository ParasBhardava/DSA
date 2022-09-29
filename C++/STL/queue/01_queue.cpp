/*
Queues are a type of container adaptors which operate in a first in first out (FIFO) type of arrangement. Elements are inserted at the back (end) and are deleted from the front

Syntax :
queue<int>queue_name;

empty() – Returns whether the queue is empty.
size() – Returns the size of the queue.
queue::swap() in C++ STL : Exchange the contents of two queues but the queues must be of same type, although sizes may differ.
queue::emplace() in C++ STL : Insert a new element into the queue container, the new element is added to the end of the queue.
queue::front() and queue::back() in C++ STL – front() function returns a reference to the first element of the queue.back() function returns a reference to the last element of the queue.
push(ele) and pop() – push() function adds the element ‘ele’ at the end of the queue. pop() function deletes the first element of the queue.

*/

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.pop();

    cout<<"Front: "<<q.front()<<"\n";
    cout<<"Back: "<<q.back()<<"\n";
    cout<<"size: "<<q.size()<<"\n";
    cout<<(q.empty() == true ? "Empty\n" : "Not Empty\n");

    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

    return 0;
}