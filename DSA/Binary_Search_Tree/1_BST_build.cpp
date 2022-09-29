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

Node* insertInBST(Node *root, int val)
{
    if(root == NULL)
        return new Node(val);

    Node *curr = root;

    while(true)
    {
        if(curr->data < val)
        {
            if(curr->right != NULL)
                curr = curr->right;

            else
            {
                curr->right = new Node(val);
                break;
            }
        }

        else
        {
            if(curr->left != NULL)
                curr = curr->left;

            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
    
    return root;
}

void inorder(Node *root)
{
    if(root == NULL)
    {
        cout<<"BST is empty !";
        return ;
    }

    if(root -> left)
        inorder(root->left);

    cout<<root->data<<" ";

    if(root -> right)
        inorder(root->right);
}

int main()
{
    Node *root = NULL;
    root = insertInBST(root, 5);
    insertInBST(root, 1);
    insertInBST(root, 3);
    insertInBST(root, 4);
    insertInBST(root, 2);
    insertInBST(root, 7);

    inorder(root);
    return 0;
}