#include <bits/stdc++.h>
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

void inorder(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty !\n";
        return;
    }

    if (root->left)
        inorder(root->left);

    cout << root->data << " ";

    if (root->right)
        inorder(root->right);
}

void recoverBST(Node *root)
{
    Node *first = NULL;
    Node *prev = new Node(INT_MIN);
    Node *mid = NULL;
    Node *last = NULL;

    solve(root, first, prev, mid, last);

    if (first && last)
        swap(first->data, last->data);

    else if (first && mid)
        swap(first->data, mid->data);
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->right->left = new Node(2);

    inorder(root);
    cout << "\n";
    recoverBST(root);
    inorder(root);

    return 0;
}