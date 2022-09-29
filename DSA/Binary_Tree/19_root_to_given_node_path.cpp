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

bool solve(Node *root, vector<int> &arr, int x)
{
    if(root == NULL)
        return false;
    
    arr.push_back(root->data);

    if(root->data == x)
        return true;

    if(solve(root->left, arr, x)) 
        return true;
    
    if(solve(root->right, arr, x))
        return true;

    arr.pop_back();
    return false;
}

vector<int>getPath(Node * root, int x)
{
    vector<int>arr;
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return arr;
    }
    
    solve(root, arr, x);
    return arr;
}

int main()
{
    Node *root = new Node(1);   
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    vector<int>res = getPath(root, 7);
    for(auto i : res)
        cout<<i<<" ";
    cout<<"\n";

    return 0;
}