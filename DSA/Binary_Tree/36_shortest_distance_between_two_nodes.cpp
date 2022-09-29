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

Node * LCA(Node *root, Node *p, Node *q)
{
    
    if(root == NULL || root == p || root == q)
        return root;

    Node *left = LCA(root->left, p, q);
    Node *right = LCA(root->right, p, q);

    if(left == NULL)
        return right;

    else if(right == NULL)
        return left;

    else
        return root;
}

int distance(Node *root, Node *node, int dis)
{
    if(root == NULL)
        return -1;

    if(root == node)
        return dis;
    
    int left = distance(root->left, node, dis+1);

    if(left != -1)
        return left;

    return distance(root->right, node, dis+1);
}

int shortestDistance(Node *root, Node *p, Node *q)
{
    Node * lca = LCA(root, p, q);
    int d1 = distance(lca, p, 0);
    int d2 = distance(lca, q, 0);

    return d1+d2;
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

    cout<<shortestDistance(root, root->right->left, root->right->right)<<"\n";

    return 0;
}