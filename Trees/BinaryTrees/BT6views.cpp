#include <bits/stdc++.h>
using namespace std;
struct node
{
    struct node *left;
    struct node *right;
    int data;
    node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
void rightview(node *root, int level, int *maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (level > *maxlevel)
    {
        cout << root->data << " ";
        *maxlevel = level;
    }
    rightview(root->right, level + 1, maxlevel);
    rightview(root->left, level + 1, maxlevel);
}

void rightviewq(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *value = q.front();
            q.pop();
            if (i == n)
            {
                cout << value->data << " ";
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
    }
}
void leftview(node *root, int level, int *maxlevel)
{
    if (root == NULL)
    {
        return;
    }
    if (level > *maxlevel)
    {
        cout << root->data << " ";
        *maxlevel = level;
    }
    leftview(root->left, level + 1, maxlevel);
    leftview(root->right, level + 1, maxlevel);
}
void leftviewq(node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            node *value = q.front();
            q.pop();
            if (i == 1)
            {
                cout << value->data << " ";
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
    }
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
                         9 */
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right->right = new node(8);
    root->right->right->right = new node(9);
    int maxlevelrightview = -1;
    int maxlevelleftview = 0;

    cout << "Right View of Binary Tree using Recursion" << endl;
    rightview(root, 0, &maxlevelrightview);
    cout << endl
         << "Right View of Binary Tree using Queue" << endl;
    rightviewq(root);

    cout << endl
         << "Left View of Binary Tree using Queue" << endl;
    leftviewq(root);
    cout << endl
         << "Left View of Binary Tree using Recursion" << endl;
    leftview(root, 1, &maxlevelleftview);
}