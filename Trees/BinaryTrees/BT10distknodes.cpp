// Nodes at Distance k
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
        left = right = NULL;
    }
};
void nodesatdistK(node *root, int k) // this function print nodes from root to distance k
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->data << " ";
    }
    nodesatdistK(root->left, k - 1);
    nodesatdistK(root->right, k - 1);
}
int targetdisttok(node *root, node *target, int k)
{
    if (root == NULL || k < 0)
        return -1;
    if (root == target)
    {
        nodesatdistK(root, k);
        return 1;
    }
    /*

                 1
              /     \
             2       3
           /  \       \
          5    6       8
                        \
                         9
    */
    int distleft = targetdisttok(root->left, target, k);
    if (distleft != -1)
    {
        if (distleft  == k)
        {
            cout << root->data << " ";
        }
        else
        {
            targetdisttok(root->right, target, k - distleft - 1);
        }
        return 1 + distleft;
    }
    int distright = targetdisttok(root->right, target, k);
    if (distright != -1)
    {
        if (distright  == k)
        {
            cout << root->data << " ";
        }
        else
        {
            targetdisttok(root->left, target, k - distright - 1);
        }
        return 1 + distright;
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
                         9
    */
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right->right = new node(8);
    root->right->right->right = new node(9);
    targetdisttok(root, root->right, 1);
}