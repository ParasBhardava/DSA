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

void oneTraversal(Node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty !\n";
        return;
    }

    stack<pair<Node *, int>> st;
    st.push({root, 1});
    vector<int> preOrder, inOrder, postOrder;

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        // this is the part of preOrder
        // increment 1 to 2
        // push the left side of the tree

        if (it.second == 1)
        {
            preOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->left != NULL)
                st.push({it.first->left, 1});
        }

        // this is the part of inOrder
        // increment 2 to 3
        // push right

        else if (it.second == 2)
        {
            inOrder.push_back(it.first->data);
            it.second++;
            st.push(it);

            if (it.first->right != NULL)
                st.push({it.first->right, 1});
        }

        // dont push it again
        else
            postOrder.push_back(it.first->data);
    }

    cout << "PreOrder : ";
    for (int i = 0; i < preOrder.size(); i++)
        cout << preOrder[i] << " ";
    cout<<"\n";

    cout << "InOrder : ";
    for (int i = 0; i < inOrder.size(); i++)
        cout << inOrder[i] << " ";
    cout<<"\n";

    cout << "PostsOrder : ";
    for (int i = 0; i < postOrder.size(); i++)
        cout << postOrder[i] << " ";
    cout<<"\n";

    // time complexity : O(3n)
    // space complexity : O(4n)
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    oneTraversal(root);

    return 0;
}