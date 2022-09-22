#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *left, *right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
// Method 1
bool checkBST1(node *root, node *left = NULL, node *right = NULL)
{
    if (root == NULL)
        return true;
    if (left != NULL && root->data <= left->data)
        return false;
    if (right != NULL && root->data >= right->data)
        return false;
    return (checkBST1(root->left, left, root) and checkBST1(root->right, root, right));
}
// Method 2 ----> InOrder Traversal
bool checkBST2(node *root)
{
    static node *prev = NULL;
    if (root != NULL)
    {
        if (!checkBST2(root->left))
            return false;
        if (prev != NULL && root->data <= prev->data) // bcz inorder prints BST in ascending order
            return false;
        prev = root;
        return checkBST2(root->right);
    }
    return true;
}
// Method 3 ---> Modification of Method 2
bool checkBST2a(node *root, node *&prev)
{
    if (root != NULL)
    {
        if (!checkBST2a(root->left, prev))
            return false;
        if (prev != NULL && root->data <= prev->data) // inorder prints BST in ascending order
            return false;
        prev = root;
        return checkBST2a(root->right, prev);
    }
    return true;
}
int main()
{
    /*
              30
            /   \
          15      35
        /          \
       5            37
    */
    struct node *root = new node(14);
    // root->left = new node(5);
    // root->left->left = new node(1);
    root->right = new node(15);
    root->right->right = new node(17);

    if (checkBST1(root, NULL, NULL))
    {
        cout << "Is BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
    if (checkBST2(root))
    {
        cout << "Is BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
    node *prev = NULL;
    if (checkBST2a(root, prev))
    {
        cout << "Is BST" << endl;
    }
    else
    {
        cout << "Not BST" << endl;
    }
}