#include <bits/stdc++.h>
using namespace std;
struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void qlevelorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *value = q.front();
        q.pop();
        if (value != NULL)
        {
            cout << value->data << " ";

            if (value->left != NULL)
            {
                q.push(value->left);
            }
            if (value->right != NULL)
            {
                q.push(value->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
        }
    }
}
int sumlevelorder(Node *root, int key)
{
    int sum = 0;
    int level = 0;
    if (root == NULL)
    {
        return -2;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *value = q.front();
        q.pop();
        if (value != NULL)
        {
            if (level == key)
            {
                sum += value->data;
            }
            if (value->left != NULL)
            {
                q.push(value->left);
            }
            if (value->right != NULL)
            {
                q.push(value->right);
            }
        }
        else if (!q.empty())
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int main()
{
    /*
                 1
              /     \
             2       3
           /  \       \
          5    6       8
                        \
                         9
    */
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    root->left->right = new Node(6);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    // qlevelorder(root);
    cout << sumlevelorder(root, 0);
}