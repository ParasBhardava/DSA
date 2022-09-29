#include <bits/stdc++.h>
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

void solve(Node *root, int level,  vector<int>&res)
{
    if(root == NULL)
        return;

    if(res.size() == level)
    res.push_back(root->data);

    solve(root->left, level+1, res);
    solve(root->right, level+1, res);
}

vector<int>rightView(Node *root)
{
    vector<int>res;
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return res;
    }

    solve(root, 0, res);
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

    vector<int>res = rightView(root);
    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}