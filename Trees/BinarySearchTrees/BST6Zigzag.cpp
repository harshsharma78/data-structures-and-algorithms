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
void zigzagtraversal(node *root)
{
    stack<node *> currlevel, nextlevel;
    bool LefttoRight = true;
    currlevel.push(root);
    while (!currlevel.empty())
    {
        node *temp = currlevel.top();
        currlevel.pop();
        if (temp)
        {
            cout << temp->data << " ";
            if (LefttoRight)
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
            else
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
        }
        if (currlevel.empty())
        {
            LefttoRight = !LefttoRight;
            swap(currlevel, nextlevel);
        }
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
    struct node *root = new node(1);
    root->left = new node(2);
    root->left->left = new node(5);
    root->left->right = new node(6);
    root->right = new node(3);
    root->right->left = new node(9);
    root->right->right = new node(8);
    // root->right->right->right = new node(9);
    zigzagtraversal(root);
}