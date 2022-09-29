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

bool isLeaf(Node * node)
{
    return !node->left && !node->right;
}

void addLeftBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->left;
    while(curr)
    {
        if(!isLeaf(curr))
            res.push_back(curr->data);

        if(curr->left)
            curr = curr->left;

        else
            curr = curr->right;
    }
}

void addRightBoundary(Node *root, vector<int> &res)
{
    Node *curr = root->right;
    vector<int> temp;
    while(curr)
    {
        if(!isLeaf(curr))
            temp.push_back(curr->data);

        if(curr->right)
            curr = curr->right;

        else
            curr = curr->left;
    }

    for(int i = temp.size()-1; i>=0; i--)
        res.push_back(temp[i]);
}

void addLeaves(Node *root, vector<int> &res)
{
    // inorder traversal 
    if(isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }

    if(root->left)
        addLeaves(root->left, res);

    if(root->right)
        addLeaves(root->right, res);
}

vector<int> boundaryTraversal(Node *root)
{
    vector<int>res;
    if(root == NULL)
    {
        cout<<"tree is empty !\n";
        return res;
    }

    if(!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->left->right = new Node(4);
    root->left->left->right->left = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->left->left = new Node(10);
    root->right->right->left->right = new Node(11);


    vector<int>res = boundaryTraversal(root);

    for(auto i : res)
        cout<<i<<" ";

    return 0;
}