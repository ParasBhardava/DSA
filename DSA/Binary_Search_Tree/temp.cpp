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

void pushAll(Node *root, stack<Node *>&st)
{
    Node *curr = root;
    while(curr != NULL)
    {
        st.push(curr);
        curr = curr->left;
    }
}

Node * incresing(Node *root)
{
    stack<Node *>st;
    pushAll(root, st);

    Node *dummy = st.top();
    while(!st.empty())
    {
        Node *node = st.top();
        st.pop();
        pushAll(node->right, st);
        node->left = NULL;

        if(st.empty())
            node->right = NULL;

        else
            node->right = st.top();
    }

    return dummy;
}


int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left ->left = new Node(1);
    root->right->right = new Node(8);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    Node *r = incresing(root);
    while(r)
    {
        cout<<r->data<<" ";
        r = r->right;
    }

    return 0;
}