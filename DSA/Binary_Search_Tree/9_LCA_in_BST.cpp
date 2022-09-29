#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    } 
};

Node *LCA(Node *root, Node *p, Node *q)
{
    if(root == NULL)
        return root;

    int curr = root->data;
    if(curr > p->data && curr > q->data)
        return LCA(root->left , p, q);

    if(curr < p->data && curr < q->data)
        return LCA(root->right, p, q);

    return root;
}

int main()
{
    Node *root = new Node(6);
    root->left = new Node(2);
    root->right = new Node(8);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->left->right->right = new Node(5);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    cout<<LCA(root, root->left->left, root->left->right->right)->data<<"\n";


    return 0;
}