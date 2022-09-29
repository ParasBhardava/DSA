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

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if(root == NULL || root == p || root == q)
        return root;

    Node *left = lowestCommonAncestor(root->left, p, q);
    Node *right = lowestCommonAncestor(root->right, p, q);

    if(left == NULL)
        return right;

    else if(right == NULL)
        return left;

    else // both right and left are not null, we found our answer
        return root;

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
    root->right->left = new Node(8);
    root->right->right = new Node(9);

    Node * node = lowestCommonAncestor(root, root->left->left, root->left->right->right);
    cout<<node->data<<"\n";

    return 0;
}