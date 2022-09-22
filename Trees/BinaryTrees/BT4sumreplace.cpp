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
int sumreplacement0(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int old = root->data;
    root->data = sumreplacement0(root->left) + sumreplacement0(root->right);
    return root->data + old;
}
void sumreplacement(node *root)
{
    if (root == NULL)
    {
        return;
    }
    sumreplacement(root->left);
    sumreplacement(root->right);
    if (root->left != NULL)
    {
        root->data += root->left->data;
    }
    if (root->right != NULL)
    {
        root->data += root->right->data;
    }
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
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
    preorder(root);
    cout << endl;
    // sumreplacement(root);
    // preorder(root);
    cout << endl;
    sumreplacement0(root);
    preorder(root);
}