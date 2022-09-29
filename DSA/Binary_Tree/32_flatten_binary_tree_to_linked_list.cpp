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

/*
time : O(N)
space : O(N)

void flatten(Node *root)
{
    if (root == NULL)
        return;

    flatten(root->right);
    flatten(root->left);

    root->right = prev;
    root->left = NULL;
    prev = root;
}
*/

/*
Time : O(N)
space : O(N)
void flatten(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> st;
    st.push(root);
    while (!st.empty())
    {
        Node *cur = st.top();
        st.pop();

        if (cur->right != NULL)
        {
            st.push(cur->right);
        }
        if (cur->left != NULL)
        {
            st.push(cur->left);
        }
        if (!st.empty())
        {
            cur->right = st.top();
        }
        cur->left = NULL;
    }
}
*/

// Time : O(N)
// space : O(1)
void flatten(Node *root)
{
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
            Node *prev = curr->left;
            while (prev->right)
                prev = prev->right;

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }

        curr = curr->right;
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    flatten(root);
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->right;
    }

    return 0;
}
