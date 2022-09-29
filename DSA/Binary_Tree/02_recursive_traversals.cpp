#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(struct Node * root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }

    cout<<root->data<<" ";

    if(root->left)
        preorder(root->left);
    
    if(root->right)
        preorder(root->right);
}

void inorder(struct Node * root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }   

    if(root->left)
        inorder(root->left);
    
    cout<<root->data<<" ";
    
    if(root->right)
        inorder(root->right);
}

void postorder(struct Node * root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }

    if(root->left)
        postorder(root->left);
    
    if(root->right)
        postorder(root->right);
        
    cout<<root->data<<" ";
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

    preorder(root);
    cout<<"\n";

    inorder(root);
    cout<<"\n";
    
    postorder(root);
    cout<<"\n";

    return 0;
}
