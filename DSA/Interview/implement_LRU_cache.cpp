#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
    
    int key;
    int val;
    node *next;
    node *prev;

    node(int key, int val)
    {
        this->key = key;
        this->val = val;
    }
};

node *head  = new node(-1, -1);
node *tail  = new node(-1, -1);

int cap;
unordered_map<int, node*>mp;


int main()
{
    return 0;
}