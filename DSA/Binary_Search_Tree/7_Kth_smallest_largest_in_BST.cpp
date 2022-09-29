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

int KthSmallestElement(Node *root, int k)
{
    stack<Node *>st;
    Node *node = root;
    int count = 0;

    while(true)
    {
        if(node != NULL)
        {
            st.push(node);
            node = node->left;
        }

        else
        {
            if(st.empty())
                break;

            node = st.top();
            st.pop();

            count++;
            if(count == k)
                return node->data;

            node = node->right;
        }
    }

    return -1;
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->left->right = new Node(2);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    cout<<KthSmallestElement(root, 3);

    return 0;
}

// Kth largest element is (N-kth) smallest element
// N = total number of elements 