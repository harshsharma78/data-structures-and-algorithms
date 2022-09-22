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
// Using Stack
void inorder(node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
node *BTtoLL(node *root)
{
    if (!root)
        return NULL;
    stack<node *> st;
    node *result = root;
    while (root != NULL || st.size() != 0)
    {
        if (root->right != NULL)
            st.push(root->right);

        root->right = root->left;
        root->left = NULL;
        if (root->right == NULL && st.size() != 0)
        {
            root->right = st.top();
            st.pop();
        }
        root = root->right;
    }
    return result;
}
// Another Approach
void BTtoLLopt(node *root)
{
    if (root == NULL || root->right == NULL || root->left == NULL)
        return;
    if (root->left != NULL)
    {
        BTtoLLopt(root->left);
        node *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        node *tail = root->right;
        while (tail->right != NULL)
        {
            tail = tail->right;
        }
        tail->right = temp;
    }
    BTtoLLopt(root->right);
}
void BTtoDLLhelper(node *root, node *&head, node *&prev, int flag)
{
    if (!root)
        return;
    BTtoDLLhelper(root->left, head, prev, flag);
    if (flag == 0)
    {
        flag = 1;
        head = root;
        prev = root;
    }
    else
    {
        prev->right = root;
        prev->right->left = prev;
        prev = prev->right;
    }
    BTtoDLLhelper(root->right, head, prev, flag);
}
node *BTtoDLL(node *root)
{
    node *head = NULL;
    node *prev = NULL;
    int flag = 0;
    BTtoDLLhelper(root, head, prev, flag);
    return head;
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

    // cout << "Binary Tree before coverting to Linked List/Flattening" << endl;
    // inorder(root);
    // cout << endl;
    // cout << "Binary Tree after coverting to Linked List/Flattening" << endl;
    // node *Root = BTtoLL(root);
    // inorder(Root);
    // cout << endl;

    // cout << "Binary Tree before coverting to Linked List/Flattening" << endl;
    // inorder(root);
    // cout << endl;
    // cout << "Binary Tree after coverting to Linked List/Flattening" << endl;
    // BTtoLLopt(root);
    // inorder(root);
    // cout << endl;

    cout << "Binary Tree before coverting to Doubly Linked List/Flattening" << endl;
    inorder(root);
    cout << endl;
    cout << "Binary Tree after coverting to Doubly Linked List/Flattening" << endl;
    node *DLL = BTtoDLL(root);
    inorder(DLL);
}