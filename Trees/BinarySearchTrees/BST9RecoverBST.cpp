#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *right, *left;
    int data;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
void swap(int *first, int *second)
{
    int temp = *first;
    *first = *second;
    *second = temp;
}
void correctBST(node *root, node **first, node **mid, node **last, node **prev)
{
    if (root)
    {
        correctBST(root->left, first, mid, last, prev);
        if (*prev && root->data < (*prev)->data)
        {
            if (!*first) // violation is occured at beginning
            {
                *first = *prev;
                *mid = root;
            }
            else
            {
                *last = root;
            }
        }
        *prev = root;
        correctBST(root->right, first, mid, last, prev);
    }
}
void recoverBST(node *root)
{
    node *first, *mid, *last, *prev;
    first = mid = last = prev = NULL;

    correctBST(root, &first, &mid, &last, &prev);

    if (first && last)
    {
        swap(&(first->data), &(last->data));
    }

    else if (first && mid)
    {
        swap(&(first->data), &(mid->data));
    }
}

void printInorder(node *root)
{
    if (!root)
        return;

    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
int main()
{
    /*
        6
      /   \
     10     2
    /  \   / \
    1   3 7   12
    */
    struct node *root = new node(6);

    root->left = new node(10);
    root->left->left = new node(1);
    root->left->right = new node(3);

    root->right = new node(2);
    root->right->left = new node(7);
    root->right->right = new node(12);

    cout << "The Incorrect BST" << endl;
    printInorder(root);

    recoverBST(root);

    cout << endl
         << "The Correct BST" << endl;
    printInorder(root);
}