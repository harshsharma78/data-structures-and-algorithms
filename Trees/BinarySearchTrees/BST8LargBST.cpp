#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    node *right;
    int data;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
struct info
{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};
info largestBSTinBT(node *root)
{
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};
    info Left = largestBSTinBT(root->left);
    info Right = largestBSTinBT(root->right);
    info curr;
    curr.size = {1 + Left.size + Right.size};
    if (Left.isBST && Right.isBST && Left.max < root->data && Right.min > root->data)
    {
        curr.min = min(Left.min, min(Right.min, root->data));
        curr.max = max(Right.max, max(Left.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;
        return curr;
    }
    curr.ans = max(Left.ans, Right.ans);
    curr.isBST = false;
    return curr;
}
int main()
{
    /*
              30
            /     \
         15         35
        /   \      /   \
       5     32   29    37
    */
    struct node *root = new node(3);
    root->left = new node(15);
    root->left->left = new node(5);
    // root->left->right = new node(32);
    root->right = new node(35);
    root->right->left = new node(29);
    // root->right->right = new node(37);
    cout << "Size of the Largest BST in BT is " << largestBSTinBT(root).ans << endl;
}