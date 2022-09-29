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

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Stack
{
    Node *head = NULL;

public:
    void push(int data)
    {
        Node *temp = new Node();
        if (temp == NULL)
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
        temp->data = data;
        temp->next = head;
        head = temp;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
        Node *temp = head;
        int x = head->data;
        head = head->next;
        free(temp);
        return x;
    }
    
    int empty()
    {
        if (head == NULL)
            return 1;
        else
            return 0;
    }
    
    int top()
    {
        if (head == NULL)
        {
            cout << "Stack is Empty";
            exit(0);
        }
        return head->data;
    }
};

int Calculate(int x, int y, char optr)
{
    if (optr == '^')
        return pow(x, y);
    else
    {
        if (optr == '+')
            return x + y;
        else if (optr == '-')
            return x - y;
        else if (optr == '*')
            return x * y;
        else
        {
            if (y == 0)
            {
                cout << "INPUT EXPRESSION IS INVALID";
                exit(0);
            }
            return x / y;
        }
    }
}
int main()
{
    int size = 0;
    Stack s;
    string exp;
    getline(cin, exp);

    for (int i = 0; i < (int)exp.size(); i++)
    {
        if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' || exp[i] == '^')
        {
            if (exp[i - 1] != ' ')
            {
                cout << "INPUT EXPRESSION IS INVALID";
                exit(0);
            }
            int n2 = s.pop();
            int n1 = s.pop();
            int ans = Calculate(n1, n2, exp[i]);
            s.push(ans);
            size--;
        }
        else if (exp[i] >= '0' && exp[i] <= '9')
        {
            string temp = "";
            while (exp[i] != ' ' && exp[i] != '+' && exp[i] != '-' && exp[i] != '*' && exp[i] != '/' && exp[i] != '^' && i != (int)exp.size())
            {
                if (exp[i] == '.')
                {
                    cout << "INPUT EXPRESSION IS INVALID";
                    exit(0);
                }
                temp += exp[i];
                i++;
            }
            if (exp[i] != ' ')
            {
                cout << "INPUT EXPRESSION IS INVALID";
                exit(0);
            }
            s.push(stoi(temp));
            size++;
        }
        else if (exp[i] == ' ')
        {
            continue;
        }
        else
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
    }

    if (s.empty() || size != 1)
    {
        cout << "INPUT EXPRESSION IS INVALID";
        exit(0);
    }
    cout << s.top();
    return 0;
}

