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

bool isIdentical(node *root1, node *root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    else
    {
        int cond1 = root1->data == root2->data;
        int cond2 = isIdentical(root1->left, root2->left);
        int cond3 = isIdentical(root1->right, root2->right);
        if (cond1 && cond2 && cond3)
            return true;
        else
            return false;
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
    struct node *root1 = new node(1);
    root1->left = new node(2);
    root1->right = new node(3);
    root1->left->left = new node(5);
    root1->left->right = new node(6);
    root1->right->right = new node(8);
    root1->right->right->right = new node(9);

    struct node *root2 = new node(1);
    root2->left = new node(2);
    root2->right = new node(3);
    root2->left->left = new node(5);
    root2->left->right = new node(6);
    root2->right->right = new node(8);
    root2->right->right->right = new node(9);

    if (isIdentical(root1, root2))
    {
        cout << "BSTs Are Identical" << endl;
    }
    else
    {
        cout << "BSTs Are Not Identical" << endl;
    }
}