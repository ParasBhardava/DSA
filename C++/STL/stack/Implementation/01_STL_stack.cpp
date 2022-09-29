/* Stacks are a type of container adaptors with LIFO(Last In First Out) type of working, where a new element is added at one end and (top) an element is removed from that end only.

Syntax :
stack<data_type>stack_name;


Important functions : 
stack::empty() –> Returns whether the stack is empty – Time Complexity : O(1) 
stack::size() –> Returns the size of the stack – Time Complexity : O(1) 

stack::top() –> Returns a reference to the top most element of the stack – Time Complexity : O(1) 
stack::push(e) –> Adds the element ‘e’ at the top of the stack – Time Complexity : O(1) 
stack::pop() –> Deletes the top most element of the stack – Time Complexity : O(1) 
stack::swap() -> used to swap the contents of one stack with another stack of same type but the size may vary - Time Complexity : O(1)
stack::emplace(e) -> insert the element ‘e’ at the top of the stack – Time Complexity : O(1)

operators(=, ==, !=, >=, <=) : We can use operators with stack as well. 

Difference between stack::emplace() and stack::push() function : While push() function inserts a copy of the value or the parameter passed to the function into the container at the top, the emplace() function constructs a new element as the value of the parameter and then adds it to the top of the container.
*/

#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int>s1;
    stack<int>s2;

    if(s1.empty())
        cout<<"s1 size "<<s1.size()<<" s1 is empty"<<endl;
    
    if(s1.empty())
        cout<<"s2 size "<<s2.size()<<" s2 is empty"<<endl;
    

    s1.push(1);
    s1.push(6);
    s1.push(2);
    s1.push(5);
    s1.push(4);
    s1.push(3);
    s1.pop();
    s1.pop();

    cout<<"s1 size "<<s2.size()<<" :";;
    while(!s1.empty())
    {
        cout<<s1.top()<<" ";
        s1.pop();
    }

    s2.emplace(6);
    s2.emplace(7);
    s2.emplace(8);
    s2.emplace(9);
    s2.emplace(10);
    s2.emplace(11);
    s2.pop();

    cout<<"\ns2 size "<<s2.size()<<" :";
    while(!s2.empty())
    {
        cout<<s2.top()<<" ";
        s2.pop();
    }

    stack<int>s3;
    s3.push(1);
    s3.push(4);
    s3.push(9);
    s3.push(16);

    stack<int>s4;
    s4.push(3);
    s4.push(27);
    s4.push(81);

    s3.swap(s4);         // swap(s3, s4);
    cout<<"\ns3 size "<<s3.size()<<" :";;
    while(!s3.empty())
    {
        cout<<s3.top()<<" ";
        s3.pop();
    }

    cout<<"\ns4 size "<<s4.size()<<" :";
    while(!s4.empty())
    {
        cout<<s4.top()<<" ";
        s4.pop();
    }

    cout<<"\n";
    cout<<"s3 < s4 : "<<(s3<s4)<<"\n";
    cout<<"s3 > s4 : "<<(s3>=s4)<<"\n";
    cout<<"s3 == s4 : "<<(s4==s3)<<"\n";
    cout<<"s3 != s4 : "<<(s4!=s3)<<"\n";

    return 0;
}