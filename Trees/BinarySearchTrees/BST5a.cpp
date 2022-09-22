#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left, *right;
    node(int value)
    {
        data = value;
        left = right = NULL;
    }
};
vector<node *> possibleBST(int start, int end)
{
    vector<node *> BST;
    if (start > end)
    {
        BST.push_back(NULL);
        return BST;
    }
    for (int i = start; i <= end; i++)
    {
        vector<node *> leftsubtrees = possibleBST(start, i - 1);
        vector<node *> rightsubtrees = possibleBST(i + 1, end);
        for (int j = 0; j < leftsubtrees.size(); j++)
        {
            node *Left = leftsubtrees[j];
            for (int k = 0; k < rightsubtrees.size(); k++)
            {
                node *Right = rightsubtrees[k];
                node *Node = new node(i);
                Node->left = Left;
                Node->right = Right;
                BST.push_back(Node);
            }
        }
    }
    return BST;
}
void preorder(struct node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
int main()
{
    vector<node *> BSTrees = possibleBST(1, 4);
    for (int i = 0; i < BSTrees.size(); i++)
    {
        cout << (i + 1) << " --> ";
        preorder(BSTrees[i]);
        cout << endl;
    }
}