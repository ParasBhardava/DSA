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

int leftHeight(Node * root)
{
    int height = 0;
    
    while(root)
    {
        height++;
        root = root->left;
    }

    return height;
}

int rightHeight(Node * root)
{
    int height = 0;
    
    while(root)
    {
        height++;
        root = root->right;
    }

    return height;
}

int countNodes(Node *root)
{
    if(root == NULL)
        return 0;

    int lh = leftHeight(root);
    int rh = rightHeight(root);

    if(lh == rh)
        return pow(2, lh)-1;

    else
        return 1 + countNodes(root->left) + countNodes(root->right);

    // Time compexity = O(logn^2)
}


int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<<countNodes(root)<<"\n";

    return 0;
}