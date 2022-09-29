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

class BSTIterator
{
    stack<Node *>st;

    void pushAll(Node *root)
    {
        while(root !=  NULL)
        {
            st.push(root);
            root = root->left;
        }
    }

    public :

    BSTIterator(Node *root)
    {
        pushAll(root);
    }

    bool hasNext()
    {
        return !st.empty();
    }

    int next()
    {
        Node *node = st.top();
        st.pop();

        pushAll(node->right);
        return node->data;
    }

};

int main()
{
    Node *root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator i(root);
    cout<<i.next()<<" "<<i.next();

    return 0;
}