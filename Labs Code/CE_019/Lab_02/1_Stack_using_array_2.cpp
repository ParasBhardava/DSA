#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define MAX_SIZE 10
using namespace std;

class stack_class
{
    int arr[MAX_SIZE];
    int top;
    
    public:
    
    stack_class()
    {
        top = -1;
    }
    
    void PUSH(int element)
    {
        if(top == MAX_SIZE-1)
        {
            cout<<"Stack Overflow"<<"\n";
            exit(0);
        }
        
        top++;
        arr[top] = element;
    }
    
    void POP()
    {
       if(top == -1)
       {
           cout<<"Stack Underflow"<<"\n";
           exit(0);
       }
        top--;
    }
    
    void CHANGE(int index, int value)
    {
        if(index > 0 && index <= top+1)   
            arr[top+1-index] = value;
        
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
        
        for(int i=top; i>=0; i--)
        {
            cout<<arr[i]<<" ";
        }
    }
    
};

int main()
{
    stack_class st;
    
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