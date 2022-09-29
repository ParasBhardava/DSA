#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

vector<int> topView(Node *root)
{
    vector<int>res;
    if(root == NULL)
    {
        cout<< "Tree is empty !\n";
        return res;
    }

    queue<pair<Node*, int>>q;
    q.push({root, 0});
    map<int, int>mp;

    while(!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *node = it.first;
        int line = it.second;

        if(mp.find(line) == mp.end())
            mp[line] = node->data;

        if(node->left != NULL)
            q.push({node->left, line-1});

        if(node->right != NULL)
            q.push({node->right, line+1});
    }

    for(auto i : mp)
        res.push_back(i.second);

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int>res = topView(root);

    for(auto i: res)
        cout<<i<<" ";
    cout<<"\n";
    
    return 0;
}