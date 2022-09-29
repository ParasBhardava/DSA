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

vector<vector<int>> zigzagLevelOrder(Node *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        cout << "tree is empty ! \n";
        return ans;
    }

    queue<Node *> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty())
    {
        int size = q.size();
        vector<int> row(size);

        for (int i = 0; i < size; i++)
        {
            Node *node = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            row[index] = node->data;

            if (node->left != NULL)
                q.push(node->left);

            if (node->right != NULL)
                q.push(node->right);
        }

        leftToRight = !leftToRight;
        ans.push_back(row);
    }

    return ans;
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

    vector<vector<int>>ans = zigzagLevelOrder(root);
    for(int i = 0; i<ans.size(); i++)
    {
        for(int j = 0; j<ans[i].size(); j++)
        {
            cout << ans[i][j] <<" ";
        }

        cout <<"\n";
    }

    return 0;
}