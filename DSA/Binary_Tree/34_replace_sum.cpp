#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val = 0)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorer(Node * root)
{
    if(root == NULL)
        return;

    cout<<root->data<<" ";
    preorer(root->left);
    preorer(root->right);
}

void sumRepalce(Node * root)
{
    if(root == NULL)
        return;

    sumRepalce(root->left);
    sumRepalce(root->right);

    if(root->left)
        root->data += root->left->data;
    
    if(root->right)
        root->data += root->right->data;
}

int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);    
    root->right->right = new Node(7);    

    preorer(root);
    sumRepalce(root);
    cout<<"\n";
    preorer(root);

return 0;
}