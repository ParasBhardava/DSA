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

bool solve(Node *root1, Node *root2)
{
    if(root1 == NULL || root2 == NULL)
        return (root1 == root2);

    if(root1->data != root2->data)
        return false;

    return (solve(root1->left, root2->right) && solve(root1->right, root2->left));
}

bool isSymmetrical(Node *root)
{
    if(root == NULL)
        return true;

    return solve(root->left, root->right);
}

int main()
{

    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->right = new Node(2);
    root1->right->left = new Node(4);
    root1->right->right = new Node(3);

    cout<<isSymmetrical(root1)<<"\n";

    Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->right = new Node(3);
    root2->right = new Node(2);
    root2->right->right = new Node(3);

    cout<<isSymmetrical(root2)<<"\n";

    return 0;
}