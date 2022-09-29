#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class node
{
    public :
    int data;
    node *next;
};

class stack
{
    int top;
    node *top_ptr;
    
    public :
    stack()
    {
        top = -1;
        top_ptr = NULL;
    }
    
    void PUSH(int element)
    {
        if(top == 9)
        {
            cout<<"Stack Overflow"<<"\n";
            exit(0);
        }
        
        node *new_node = new node;
        new_node->data = element;
        new_node->next = top_ptr;
        top_ptr = new_node;
        
        top++;
        
    }
    
    void POP()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<"\n";
            exit(0);
        }
        
        top--;
        node *temp = top_ptr;
        top_ptr = top_ptr->next;
        delete temp;
    }
    
    void CHANGE(int index, int value)
    {
        if(index > 0 && index <= top+1)   
        {
            node *temp = top_ptr;
            index--;
            while(index--)
            {
                temp= temp->next;
            }
            temp->data = value;
        }
        
        else
        {
            cout<<"Indexed item not present in stack"<<"\n";
            exit(0);
        }
    }
    
    void PRINT()
    {
        if(top == -1)
        {
            cout<<"Stack is empty"<<"\n";
            exit(0);
        }
        
        node *temp = top_ptr;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
};

int main()
{
    stack st;
    
    int i;
    while(1)
    {
        cin>>i;
        if(i == 1)
        {
            int val;
            cin>>val;
            st.PUSH(val);
        }
        
        else if(i == 2)
        {
            st.POP();
        }
        
        else if(i == 3)
        {
            int index, val;
            cin>>index>>val;
            st.CHANGE(index, val);
        }
        
        else if(i == 4)
        {
            st.PRINT();
            break;
        }
        
        else
        {
            cout<<"Operation not supported"<<"\n";
            break;
        }
    }
    
    return 0;
}
