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

Node * inorderSuccessor(Node *root, Node *p)
{
    Node *successor = NULL;

    while(root !=  NULL)
    {
        if(root->data <= p->data)
            root = root->right;

        else
        {
            successor = root;
            root = root->left;
        }

    }
    return successor;
}

Node * inorderPredecessor(Node *root, Node *p)
{
    Node *predecessor = NULL;

    while(root !=  NULL)
    {
        if(root->data >= p->data)
            root = root->left;

        else
        {
            predecessor = root;
            root = root->right;
        }

    }
    return predecessor;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->right = new Node(9);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(10);

    cout<<inorderSuccessor(root, root->left->left)->data<<"\n";
    cout<<inorderPredecessor(root, root->left->left)->data<<"\n";

    return 0;
}