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

using namespace std;

class Node
{
public:
    char data;
    Node *next;
    ~Node()
    {
        free(next);
    }
};

class Stack
{
    Node *head= NULL;

public:
    void push(char data)
    {
        Node *temp = new Node();
        if(temp == NULL)
        {
            cout << "Stack Overflow";
            exit(0);
        }
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    void pop()
    {
        if(head == NULL)
        {
            cout << "Stack Underflow";
            exit(0);
        }
        Node *temp = head;
        head = head->next;
        free(temp);
    }
    int empty()
    {
        if(head == NULL)
            return 1;
        else
            return 0;
    }
    char top()
    {
        return head->data;
    }
};

int main()
{
    string exp, pfexp;
    int Rank = 0;
    char temp;

    getline(cin, exp);

    Stack s;
    Stack rp;
    map<char, int> f;
    map<char, int> g;
    map<char, int> r;

    f['+'] = 1;
    f['-'] = 1;
    f['*'] = 3;
    f['/'] = 3;
    f['^'] = 6;
    f['('] = 9;
    f[')'] = 0;
    g['+'] = 2;
    g['-'] = 2;
    g['*'] = 4;
    g['/'] = 4;
    g['^'] = 5;
    g['('] = 0;
    r['+'] = -1;
    r['-'] = -1;
    r['*'] = -1;
    r['/'] = -1;
    r['^'] = -1;

    for (char i = 'A', j = 'a'; (i <= 'Z' && j <= 'z'); i++, j++)
    {
        f[i] = 7;
        g[i] = 8;
        r[i] = 1;
        f[j] = 7;
        g[j] = 8;
        r[j] = 1;
    }
    s.push('(');
    exp.push_back(')');
    for (int i = 0; i < (int)exp.size(); i++)
    {
        if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '(' && exp[i] <= '+') || exp[i] == '-' || exp[i] == '/' ||           exp[i] == '^' || (exp[i] >= 'a' && exp[i] <= 'z'))
        {
            while (g[s.top()] > f[exp[i]])
            {
                temp = s.top();
                rp.push(temp);
                Rank += (r[s.top()]);
                s.pop();
            }
            if (g[s.top()] != f[exp[i]])
                s.push(exp[i]);
            else
                s.pop();
        }
        else
        {
            cout << "INPUT EXPRESSION IS INVALID";
            exit(0);
        }
    }
    if (!s.empty() || Rank != 1)
        cout << "INPUT EXPRESSION IS INVALID" << endl;
    else
    {
        while (!rp.empty())
        {
            temp = rp.top();
            pfexp.push_back(temp);
            rp.pop();
        }
        for (int i = pfexp.size() - 1; i >= 0; i--)
            cout << pfexp[i];
    }
    return 0;
}