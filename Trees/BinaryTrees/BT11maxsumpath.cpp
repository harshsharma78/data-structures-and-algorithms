
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
int maxsumpathutil(node *root, int &result)
{
    if (root == NULL)
        return 0;
    int left = maxsumpathutil(root->left, result);
    int right = maxsumpathutil(root->right, result);
    int wholepath = max(max(root->data, root->data + left + right),
                        max(root->data + left, root->data + right));
    result = max(result, wholepath);
    int singlepath = max(root->data, max(root->data + left, root->data + right));
    return singlepath;

    // int maxsingle = max(max(left, right) + root->data, root->data);
    // int maxtop = max(maxsingle, left + right + root->data); // when no ancestors
    // result = max(result , maxtop);
    // return maxsingle;
}
int maxsumpath(node *root)
{
    int result = INT_MIN;
    maxsumpathutil(root, result);
    return result;
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
    cout << "The Maximum Path Sum in a Binary Tree is " << maxsumpath(root) << endl;
}