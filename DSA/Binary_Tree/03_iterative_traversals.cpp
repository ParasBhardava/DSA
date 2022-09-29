#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val = 0)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void preorder(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return ;
    }

    stack<Node*>st;
    st.push(root);

    while(!st.empty())
    {
        root = st.top();
        st.pop();

        cout<<root->data<<" ";

        if(root -> right != NULL)
            st.push(root->right);

        if(root->left != NULL)
            st.push(root->left);
    }
}

void inorder(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }

    stack<Node*>st;
    Node *node = root;

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
            cout<<node->data<<" ";
            node = node->right;
        }

    }
}

// Using Two stack
// void postorder(Node *root)
// {
//     if(root == NULL)
//     {
//         cout<<"Tree is empty !\n";
//         return;
//     }

//     stack<Node *>st1;
//     stack<Node *>st2;
//     Node *node;

//     st1.push(root);
//     while(!st1.empty())
//     {
//         node = st1.top();
//         st1.pop();
//         st2.push(node);

//         if(node->left != NULL)
//             st1.push(node->left);

//         if(node->right != NULL)
//             st1.push(node->right);
//     }

//     while(!st2.empty())
//     {
//         cout << st2.top()->data << " ";
//         st2.pop();
//     }
// }

// Using 1 Stack
void postorder(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree is empty !\n";
        return;
    }

    Node *curr = root, *temp;
    stack<Node *>st;

    while(curr != NULL || !st.empty())
    {
        if(curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }

        else
        {
            temp = st.top()->right;
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                cout << temp->data << " ";

                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    cout << temp->data << " ";
                }
            }

            else
                curr = temp;
        }
    }
        
    // Time complexity : O(2n)
    // Space complexity : O(n)
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

    preorder(root);
    cout<<"\n";

    inorder(root);
    cout<<"\n";
    
    postorder(root);
    cout<<"\n";

    return 0;
}
