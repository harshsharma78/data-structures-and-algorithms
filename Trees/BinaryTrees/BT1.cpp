#include <bits/stdc++.h>
using namespace std;
// Building Binary Tree from Preorder and Inorder
// Building Binary Tree from Postorder and Inorder

struct Node
{
    struct Node *left;
    struct Node *right;
    int data;
    Node(int value)
    {
        data = value;
        left = NULL;
        right = NULL;
    }
};
int SearchPre(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
int SearchPost(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
void Inorder(struct Node *root)
{
    if (root != NULL)
    {
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }
}
void Preorder(struct Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}
Node *buildtree(int preorder[], int inorder[], int start, int end)
{
    static int idx = 0;
    if (start > end)
    {
        return NULL;
    }
    int curr = preorder[idx];
    idx++;

    Node *value = new Node(curr);
    if (start == end)
    {
        return value;
    }
    int pos = SearchPre(inorder, start, end, curr);

    value->left = buildtree(preorder, inorder, start, pos - 1);
    value->right = buildtree(preorder, inorder, pos + 1, end);
    return value;
}
Node *Buildtree(int postorder[], int inorder[], int start, int end)
{
    static int idx = 4;
    if (start > end)
    {
        return NULL;
    }
    int curr = postorder[idx];
    idx--;
    Node *value = new Node(curr);
    if (start == end)
    {
        return value;
    }
    int pos = SearchPost(inorder, start, end, curr);
    value->right = Buildtree(postorder, inorder, pos + 1, end);
    value->left = Buildtree(postorder, inorder, start, pos - 1);
    return value;
}

int main()
{
    int preorder[] = {1, 6, 5, 7, 3};
    int postorder[] = {1, 6, 5, 7, 3};
    int inorder[] = {5, 6, 1, 3, 7};
    Node *root = buildtree(preorder, inorder, 0, 4);
    Inorder(root);
    cout << endl;
    Node *node = Buildtree(postorder, inorder, 0, 4);
    Preorder(node);
}