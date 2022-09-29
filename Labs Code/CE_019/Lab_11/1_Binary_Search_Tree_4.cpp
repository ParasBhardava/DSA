#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

class BST
{
public:
    Node *root = NULL;

    Node *insertNode(Node *root, int data)
    {
        if (root == NULL)
            return new Node(data);

        if (data < root->data)
            root->left = insertNode(root->left, data);
        else
            root->right = insertNode(root->right, data);

        return root;
    }

    Node *deleteNode(Node *root, int data)
    {
        if (root == NULL)
        {
            cout << "Node " << data << " is not found in the tree";
            exit(0);
        }

        if (data < root->data)
            root->left = deleteNode(root->left, data);

        else if (data > root->data)
            root->right = deleteNode(root->right, data);

        else
        {
            if (root->left == NULL && root->right == NULL)
            {
                free(root);
                return NULL;
            }

            else if (root->left == NULL)
            {
                Node *temp = root->right;
                free(root);
                return temp;
            }

            else if (root->right == NULL)
            {
                Node *temp = root->left;
                free(root);
                return temp;
            }

            Node *curr = root->right;
            while (curr && curr->left != NULL)
                curr = curr->left;
            Node *temp = curr;
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    void inorder(Node *root)
    {
        if (root == NULL)
            return;

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void preorder(Node *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
};

int main()
{
    int numOfInsert, numOfDelete;
    cin >> numOfInsert;

    BST bst;

    while (numOfInsert--)
    {
        int num;
        cin >> num;
        bst.root = bst.insertNode(bst.root, num);
    }

    cin >> numOfDelete;
    while (numOfDelete--)
    {
        int num;
        cin >> num;
        bst.root = bst.deleteNode(bst.root, num);
    }

    bst.inorder(bst.root);
    cout << endl;
    bst.preorder(bst.root);

    return 0;
}
