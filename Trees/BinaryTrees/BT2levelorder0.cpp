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
int height(node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    int lheight = height(n->left);
    int rheight = height(n->right);
    // else
    // {
    //     int lheight = height(n->left);
    //     int rheight = height(n->right);
    //     if (lheight > rheight) // use the bigger
    //     {
    //         return (lheight + 1);
    //     }
    //     else
    //     {
    //         return (rheight + 1);
    //     }
    // } OR
    return max(lheight , rheight) + 1;
}
void printcurrentlevel(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == 1)
    {
        cout << root->data << " ";
    }
    else if (level > 1)
    {
        printcurrentlevel(root->left, level - 1);
        printcurrentlevel(root->right, level - 1);
    }
}
void printlevelorder(node *root)
{
    int H = height(root);
    for (int i = 1; i <= H; i++)
    {
        printcurrentlevel(root, i);
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
    cout << "The Height of the Binary Tree is " << height(root) << endl;
    cout << "The Level Order Traversal in Binary Tree is" << endl;
    printlevelorder(root);
}