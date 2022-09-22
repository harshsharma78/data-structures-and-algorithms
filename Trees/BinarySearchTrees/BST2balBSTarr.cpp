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
node *BSTSortedArray(int arr[], int start, int end)
{
    node *root;
    int mid = (start + end) / 2;
    root = new node(arr[mid]);
    if (start > end)
    {
        return NULL;
    }

    root->left = BSTSortedArray(arr, start, mid - 1);
    root->right = BSTSortedArray(arr, mid + 1, end);
    return root;
}
void preorder(node *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    node *root = BSTSortedArray(arr, 0, 4);
    preorder(root);
}