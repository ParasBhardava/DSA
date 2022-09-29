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

bool findPath(Node *root, int target, vector<int> &ans)
{
    if (root->data == target)
    {
        ans.push_back(root->data);
        return true;
    }

    if (root->left && findPath(root->left, target, ans))
    {
        ans.push_back(root->data);
        return true;
    }

    if (root->right && findPath(root->right, target, ans))
    {
        ans.push_back(root->data);
        return true;
    }

    return false;
}

void path(Node *root, int a, int b)
{
    vector<int> path1;
    vector<int> path2;
    findPath(root, a, path1);
    findPath(root, b, path2);

    int last;
    while (path1.size() > 0 && path2.size() > 0 && path1.back() == path2.back())
    {
        last = path1.back();
        path1.pop_back();
        path2.pop_back();
    }

    vector<int> path;
    for (int i = 0; i < path1.size(); i++)
        path.push_back(path1[i]);

    path.push_back(last);
    reverse(path2.begin(), path2.end());

    for (int i = 0; i < path2.size(); i++)
        path.push_back(path2[i]);

    for (int it : path)
        cout << it << " ";
    cout << "\n";
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

    // input :
    // path(root, 4, 7);

    string s = "a b c d e f";
    stringstream ss(s);
    string temp;

    ss >> temp;
    ss >> temp;
    // getline(ss, temp, ',');
    cout << temp << "\n";

    ss >> temp;
    // getline(ss, temp, ',');
    cout << temp << "\n";

    ss >> temp;
    // getline(ss, temp, ',');
    cout << temp << "\n";

    ss >> temp;

    ss >> temp;
    // getline(ss, temp, ',');
    cout << temp << "\n";

    return 0;
}

// TC : O(no. of nodes)
// SC : O(Height of tree)