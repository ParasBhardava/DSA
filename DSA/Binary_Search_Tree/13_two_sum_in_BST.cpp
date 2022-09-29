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

class BSTIterator
{
    stack<Node *>st;
    bool reverse;

    void pushAll(Node *root)
    {
        while(root != NULL)
        {
            st.push(root);
            
            if(reverse == true)
                root = root->right;

            else
                root = root->left;
        }
    }

    public :  
    BSTIterator(Node *root, bool isReverse)
    {
        this->reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        Node* node = st.top();
        st.pop();

        if(reverse == true)
            pushAll(node->left);

        else
            pushAll(node->right);

        return node->data;
    }
    
};

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);

    int k = 12;
    bool ans = false;

    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next();

    while(i < j)
    {
        if(i + j == k)
        {
            ans = true;
            break;
        }

        if(i + j < k)
            i = l.next();

        else
            j = r.next();
    }

    cout<<ans<<"\n";

    return 0;
}