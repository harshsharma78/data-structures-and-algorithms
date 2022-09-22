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
// node *SearchInBST(node *root, int value)
// {
//     int count = 0;
//     if (root->data == value)
//     {
//         return root;
//     }
//     if (root->data > value)
//     {
//         root->left = SearchInBST(root->left, value);
//     }
//     if (root->data < value)
//     {
//         root->right = SearchInBST(root->right, value);
//     }
//     return root;
// }
node *InorderPredecessor(node *root) // left subtree's rightmost child
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
    // node *temp = root;
    // while (temp && temp->right != NULL)
    // {
    //     temp = temp->right;
    // }
    // return temp;
}
node *Inordersuccessor(node *root)
{
    root = root->right;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;

    // node *temp = root;
    // while (temp && temp->left != NULL)
    // {
    //     temp = temp->left;
    // }
    // return temp;
}

node *DeletionInBST(node *root, int value)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    // if (root->left == NULL) // node with only one or no child
    // {
    //     node *temp = root->right;
    //     free(root);
    //     return temp;
    // }
    // if (root->right == NULL) // node with only one or no child
    // {
    //     node *temp = root->left;
    //     free(root);
    //     return temp;
    // }
    if (root->data > value)
    {
        root->left = DeletionInBST(root->left, value);
    }
    else if (root->data < value)
    {
        root->right = DeletionInBST(root->right, value);
    }
    else
    {
        struct node *ipre = InorderPredecessor(root);
        root->data = ipre->data;
        root->left = DeletionInBST(root->left, ipre->data);
        // struct node *isucc = Inordersuccessor(root);
        // root->data = isucc->data;
        // root->right = DeletionInBST(root->right, isucc->data);
    }
    return root;
}
// node *DeletionInBST(node *root, int value)
// {
//     if (root->data > value)
//     {
//         root->left = DeletionInBST(root->left, value);
//     }
//     if (root->data < value)
//     {
//         root->right = DeletionInBST(root->right, value);
//     }
//     else
//     {
//         if (root->left == NULL) // node with only one or no child
//         {
//             node *temp = root->right;
//             free(root);
//             return temp;
//         }
//         else if (root->right == NULL) // node with only one or no child
//         {
//             node *temp = root->left;
//             free(root);
//             return temp;
//         }
//         else
//         {
//             // struct node *ipre = InorderPredecessor(root->left);
//             // root->data = ipre->data;
//             // root->left = DeletionInBST(root->left, ipre->data);
//             struct node *isucc = Inordersuccessor(root->right);
//             root->data = isucc->data;
//             root->right = DeletionInBST(root->right, isucc->data);
//         }
//         return root;
//     }
// }
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    /*
         
    */
    struct node *root = NULL;
    root = InsertionInBSt(root, 5);
    root = InsertionInBSt(root, 3);
    root = InsertionInBSt(root, 6);
    root = InsertionInBSt(root, 1);
    root = InsertionInBSt(root, 4);
    // inorder(root);
    // cout << endl;
    // node *root1 = SearchInBST(root, 5);
    // if (root1 == NULL)
    // {
    //     cout << "Value Not Present in Binary Search Tree" << endl;
    // }
    // else
    // {
    //     cout << "Value is Present in Binary Search Tree" << endl;
    // }

    inorder(root);
    cout << endl;
    DeletionInBST(root, 5);
    inorder(root);
}