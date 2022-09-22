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
node *BSTfromPreorder(int pre[], int *preindex, int low, int high, int n)
{
    if (low > high || *preindex >= n)
        return NULL;
    node *root = new node(pre[*preindex]);
    *preindex += 1;
    if (low == high)
        return root;
    int i;
    for (i = low; i <= high; i++)
    {
        if (pre[i] > root->data)
            break;
    }
    root->left = BSTfromPreorder(pre, preindex, *preindex, i - 1, n);
    root->right = BSTfromPreorder(pre, preindex, i, high, n);
    return root;
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
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}
// Method 2
node *BSTfromPreorder2(int pre[], int *preindex, int key, int min, int max, int n)
{
    if (*preindex >= n)
    {
        return NULL;
    }
    node *root = NULL;
    if (key > min && key < max)
    {
        root = new node(key);
        *preindex += 1;
        if (*preindex < n)
        {
            root->left = BSTfromPreorder2(pre, preindex, pre[*preindex], min, key, n);
        }
        if (*preindex < n)
        {
            root->right = BSTfromPreorder2(pre, preindex, pre[*preindex], key, max, n);
        }
    }
    return root;
}

int main()
{
    int pre[] = {10, 5, 1, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);
    int preindex = 0;
    // node *root = BSTfromPreorder(pre, &preindex, 0, size - 1, size);
    node *root1 = BSTfromPreorder2(pre, &preindex, pre[0], INT_MIN, INT_MAX, size);
    preorder(root1);
    //inorder(root);
    inorder(root1);
}