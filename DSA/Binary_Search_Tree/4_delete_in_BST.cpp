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

Node *findLastRight(Node *root)
{
    if (root->right == NULL)
        return root;

    return findLastRight(root->right);
}

Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;

    else if (root->right == NULL)
        return root->left;

    Node *rightChild = root->right;
    Node *lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}

Node *insertInBST(Node *root, int val)
{
    if (root == NULL)
        return new Node(val);

    Node *curr = root;

    while (true)
    {
        if (curr->data < val)
        {
            if (curr->right != NULL)
                curr = curr->right;

            else
            {
                curr->right = new Node(val);
                break;
            }
        }

        else
        {
            if (curr->left != NULL)
                curr = curr->left;

            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }

    return root;
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        cout << "BST is empty !";
        return;
    }

    if (root->left)
        inorder(root->left);

    cout << root->data << " ";

    if (root->right)
        inorder(root->right);
}

Node *deleteInBST(Node *root, int val)
{
    if (root == NULL)
        return NULL;

    if (root->data == val)
        return helper(root);

    Node *dummy = root;
    while (root)
    {
        if (root->data > val)
        {
            if (root->left != NULL && root->left->data == val)
            {
                root->left = helper(root->left);
                break;
            }

            else
                root = root->left;
        }

        else
        {
            if (root->right != NULL && root->right->data == val)
            {
                root->right = helper(root->right);
                break;
            }

            else
                root = root->right;
        }
    }

    return dummy;
}

int main()
{
    Node *root = NULL;
    root = insertInBST(root, 8);
    insertInBST(root, 5);
    insertInBST(root, 12);
    insertInBST(root, 4);
    insertInBST(root, 7);
    insertInBST(root, 6);
    insertInBST(root, 10);
    insertInBST(root, 14);
    insertInBST(root, 13);

    inorder(root);
    cout << "\n";

    root =  deleteInBST(root, 5);
    inorder(root);
    cout << "\n";

    return 0;
}