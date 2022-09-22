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
int heightoftree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(heightoftree(root->left), heightoftree(root->right)) + 1;
}
bool heightbalnced(node *root)
{
    if (root == NULL)
    {
        return true;
    }
    //   if (heightbalnced(root->left) == false)
    // {
    //     return false;
    // }
    // if (heightbalnced(root->right) == false)
    // {
    //     return false;
    // }
    int lh = heightoftree(root->left);
    int rh = heightoftree(root->right);
    if (abs(lh - rh) <= 1 && heightbalnced(root->left) && heightbalnced(root->right))
        return true;
    return false;
}
bool heightbalncedopt(node *root, int *height)
{
    if (root == NULL)
    {
        *height = 0;
        return true;
    }
    //   if (heightbalnced(root->left) == false)
    // {
    //     return false;
    // }
    // if (heightbalnced(root->right) == false)
    // {
    //     return false;
    // }
    int lh = 0;
    int rh = 0;
    *height = max(lh, rh) + 1;
    if (abs(lh - rh) <= 1 && heightbalncedopt(root->left, &lh) && heightbalncedopt(root->right, &rh))
        return true;
    return false;
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
    // root->right->right->right = new node(9);
    int height = 0;
    if (heightbalnced(root) == true)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Imbalanced" << endl;
    }
    if (heightbalncedopt(root, &height) == true)
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Imbalanced" << endl;
    }
}