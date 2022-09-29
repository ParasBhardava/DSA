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

void changeTree(Node *root)
{
    if(root == NULL)
        return;

    int child = 0;
    if(root->left)
        child += root->left->data;

    if(root->right)
        child += root->right->data;

    if(child >= root->data)
        root->data = child;
    else
    {
        if(root->left)
            root->left->data = root->data;

        if(root->right)
            root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if(root->left)
        total += root->left->data;

    if(root->right)
        total += root->right->data;

    if(root->left || root->right)   // for checking not leaf node
        root->data = total;
}

void printLevelOrder(Node *root)
{
    if(root == NULL)
        return;

    queue<Node *>q;
    q.push(root);

    while(!q.empty())
    {
        Node *node = q.front();
        q.pop();

        cout<<node->data<<" ";

        if(node->left)
            q.push(node->left);

        if(node->right)
            q.push(node->right);
    }
}

int main()
{
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    printLevelOrder(root);
    cout<<"\n";

    changeTree(root);
    printLevelOrder(root);

    return 0;
}