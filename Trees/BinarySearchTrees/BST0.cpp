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
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node *InsertionInBSt(node *root, int value)
{
    if (root == NULL)
    {
        return new node(value);
    }
    if (value > root->data)
    {
        root->right = InsertionInBSt(root->right, value);
    }
    if (value < root->data)
    {
        root->left = InsertionInBSt(root->left, value);
    }
    return root;
}
node *SearchInBST(node *root, int value)
{
    int count = 0;
    if (root->data == value)
    {
        return root;
    }
    if (root->data > value)
    {
        root->left = SearchInBST(root->left, value);
    }
    if (root->data < value)
    {
        root->right = SearchInBST(root->right, value);
    }

    return root;
}
int main()
{
    struct node *root = NULL;
    root = InsertionInBSt(root, 1);
    root = InsertionInBSt(root, 3);
    root = InsertionInBSt(root, 2);
    root = InsertionInBSt(root, 5);
    root = InsertionInBSt(root, 9);
    inorder(root);
    cout << endl;
    node *root1 = SearchInBST(root, 5);
    if (root1 == NULL)
    {
        cout << "Value Not Present in Binary Search Tree" << endl;
    }
    else
    {
        cout << "Value is Present in Binary Search Tree" << endl;
    }
}