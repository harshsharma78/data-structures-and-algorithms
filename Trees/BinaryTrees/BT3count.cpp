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
int countFullNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int count = 0;
    if (root->right && root->left)
        count++;

    count += countFullNodes(root->left) + countFullNodes(root->right);
    return count;
}
int countNodes(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int heightoftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(heightoftree(root->left), heightoftree(root->right)) + 1;
}
int diameteroftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lheight = heightoftree(root->left);
    int rheight = heightoftree(root->right);
    int ldiameter = diameteroftree(root->left);
    int rdiameter = diameteroftree(root->right);
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
int diameteroftreeopt(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return 0;
    }
    int lheight = 0, rheight = 0;
    int ldiameter = diameteroftreeopt(root->left, &lheight);
    int rdiameter = diameteroftreeopt(root->right, &rheight);
    *height = max(lheight, rheight) + 1;
    return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}
int main()
{
    //     1
    //   2    3
    // 4   5
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    int height = 0;
    cout << "Total Number of Full Nodes in a Binary Tree are " << countFullNodes(root) << endl;
    cout << "Total Number of Nodes in a Binary Tree are " << countNodes(root) << endl;
    cout << "The Diameter of a Binary Tree is " << diameteroftree(root) << endl;
    cout << "The Diameter of a Binary Tree is " << diameteroftreeopt(root, &height) << endl;
}